#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <IRsend.h>

#include "config.h"
#include "index.h"

IRrecv irrecv(IR_RCV);
IRsend irsend(IR_LED);

ESP8266WebServer server(80);

void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}

#define MAX_DATA_LENGTH 100
uint16_t signal_data[MAX_DATA_LENGTH];
int current_data_length = -1;

decode_results results;

void handleRecord() {
  String output = "";
  for(int i = 0;i<=100;i++) {
    if (irrecv.decode(&results)) {
      output += resultToSourceCode(&results);
      irrecv.resume();  // Receive the next value
    } else {
      output += "+5ms";
    }
    output +="<br>";
    delay(5);
  }
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/html", output);
}

void handleNotFound(){
  server.send(404, "text/plain", "bad command");
}

void setup(void){
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the receiver
  irsend.begin(); // Start IR sender
  while (!Serial)  // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(IR_RCV);


  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME);
  WiFi.begin(SSID, PASSWORD);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(SSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/",          handleRoot);
  server.on("/record",    handleRecord);
  server.on("/denon/volumeup",       handle_Denon_VolumeUp);
  server.on("/denon/volumedown",     handle_Denon_VolumeDown);
  server.on("/denon/mute",           handle_Denon_mute);
  server.on("/denon/wakeup",         handle_Denon_Wakeup);
  server.on("/denon/standby",        handle_Denon_Standby);
  server.on("/denon/channel/phono",  handle_Denon_changeChannel_phono);
  server.on("/denon/channel/cd",     handle_Denon_changeChannel_cd);
  server.on("/denon/channel/tuner",  handle_Denon_changeChannel_tuner);
  server.on("/denon/channel/dvdvdp", handle_Denon_changeChannel_dvd_vdp);
  server.on("/denon/channel/tvdbs",  handle_Denon_changeChannel_tv_dbs);
  server.on("/denon/channel/vcrone", handle_Denon_changeChannel_vcr_one);
  server.on("/denon/channel/vcrtwo", handle_Denon_changeChannel_vcr_two);
  server.on("/denon/channel/vaux",   handle_Denon_changeChannel_v_aux);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
