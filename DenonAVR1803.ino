void send_DenonCommand(uint16_t* A, uint16_t* B){
  irsend.sendRaw(A, 31, 38);
  delay(50);
  irsend.sendRaw(B, 31, 38);
}
void handle_Denon_VolumeUp() {
  uint16_t A[31] = {360, 676, 364, 1734, 284, 752, 364, 674, 360, 698, 284, 1790, 308, 734, 328, 724, 286, 752, 308, 1788, 282, 1790, 308, 1790, 282, 1794, 304, 754, 282, 778, 280}; // DENON 223C uint64_t data = 0x223C;
  uint16_t B[31] = {304, 756, 282, 1792, 280, 780, 278, 758, 280, 758, 276, 784, 278, 1794, 278, 1820, 252, 1820, 278, 758, 278, 782, 278, 758, 280, 782, 254, 1820, 278, 1796, 278}; // DENON 21C3 uint64_t data = 0x21C3;
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"Volume\": 1}");
}
void handle_Denon_VolumeDown() {
  uint16_t A[31] = {282, 780, 256, 1818, 280, 758, 278, 782, 278, 758, 278, 782, 254, 1820, 278, 758, 278, 784, 276, 1796, 278, 1818, 254, 1820, 278, 1796, 278, 784, 252, 784, 280}; // DENON 213C uint64_t data = 0x213C;
  uint16_t B[31] = {280, 756, 282, 1818, 254, 782, 280, 758, 278, 782, 278, 1796, 278, 782, 252, 1820, 278, 1794, 278, 784, 276, 760, 278, 782, 254, 784, 278, 1796, 278, 1820, 252}; // DENON 22C3 uint64_t data = 0x22C3;
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"Volume\": -1}");
}
void handle_Denon_mute(){
  uint16_t A[31] = {278, 780, 282, 1792, 280, 780, 280, 756, 280, 782, 254, 782, 278, 758, 278, 782, 276, 760, 278, 1796, 276, 1820, 278, 1796, 278, 1820, 252, 784, 280, 758, 276}; // DENON 203C uint64_t data = 0x203C;
  uint16_t B[31] = {282, 756, 278, 1818, 282, 756, 278, 782, 278, 758, 280, 1818, 252, 1820, 278, 1794, 278, 1820, 276, 760, 280, 758, 276, 782, 278, 758, 280, 1818, 252, 1820, 278}; // DENON 23C3 uint64_t data = 0x23C3;
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"toggle-mute\": true}");
}
void handle_Denon_Wakeup(){
  uint16_t A[31] = {280, 756, 280, 1818, 278, 758, 280, 758, 276, 784, 278, 1796, 278, 784, 250, 784, 278, 760, 276, 784, 276, 1796, 276, 1822, 252, 1822, 276, 760, 276, 784, 252}; // DENON 221C uint64_t data = 0x221C;
  uint16_t B[31] = {278, 782, 280, 1794, 280, 782, 276, 760, 278, 760, 276, 784, 278, 1796, 278, 1820, 252, 1822, 278, 1796, 276, 784, 276, 760, 278, 784, 252, 1822, 276, 1796, 276}; // DENON 21E3 uint64_t data = 0x21E3;
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"wakleup\": true}");
}
void handle_Denon_Standby(){
  uint16_t A[31] = {280, 780, 278, 1794, 280, 758, 278, 784, 278, 758, 278, 784, 252, 1820, 278, 760, 276, 784, 278, 758, 278, 1798, 274, 1822, 278, 1796, 276, 784, 276, 760, 278}; // DENON 211C uint64_t data = 0x211C; 
  uint16_t B[31] = {280, 756, 280, 1818, 278, 758, 280, 758, 276, 784, 278, 1796, 278, 784, 252, 1820, 278, 1796, 276, 1822, 276, 760, 278, 782, 252, 786, 278, 1796, 276, 1822, 274}; // DENON 22E3 uint64_t data = 0x22E3; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"standby\": true}");
}
void handle_Denon_changeChannel_phono(){
  uint16_t A[31] = {284, 776, 284, 1790, 284, 778, 280, 756, 282, 756, 280, 780, 280, 756, 282, 1816, 256, 1818, 282, 1792, 280, 1818, 278, 758, 280, 780, 256, 1818, 280, 1792, 280}; // DENON 20F3 uint64_t data = 0x20F3;
  uint16_t B[31] = {286, 752, 284, 1814, 284, 754, 282, 778, 280, 756, 284, 1792, 278, 1818, 280, 754, 282, 778, 256, 782, 280, 756, 280, 1816, 280, 1794, 280, 780, 256, 780, 282}; // DENON 230C uint64_t data = 0x230C; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"phono\"}");
}
void handle_Denon_changeChannel_cd(){
  uint16_t A[31] = {282, 754, 282, 1792, 278, 780, 282, 756, 280, 780, 280, 756, 280, 780, 254, 1818, 280, 756, 278, 782, 278, 758, 280, 1818, 254, 1818, 280, 756, 280, 780, 254}; // DENON 208C uint64_t data = 0x208C;
  uint16_t B[31] = {282, 778, 282, 1792, 282, 780, 254, 782, 282, 756, 278, 1818, 278, 1794, 280, 780, 254, 1820, 280, 1794, 278, 1818, 278, 758, 280, 780, 254, 1818, 280, 1794, 280}; // DENON 2373 uint64_t data = 0x2373; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"cd\"}");
}
void handle_Denon_changeChannel_tuner(){
  uint16_t A[31] = {282, 754, 282, 1792, 280, 780, 280, 756, 280, 782, 278, 758, 280, 1818, 256, 782, 278, 1794, 280, 1818, 254, 1818, 280, 758, 278, 782, 278, 1794, 280, 1818, 254}; // DENON 2173 uint64_t data = 0x2173;
  uint16_t B[31] = {282, 778, 282, 1792, 282, 758, 278, 780, 280, 756, 280, 1818, 276, 758, 280, 1818, 254, 782, 278, 758, 278, 782, 254, 1820, 278, 1796, 276, 782, 278, 758, 280}; // DENON 228C uint64_t data = 0x228C; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"tuner\"}");
}
void handle_Denon_changeChannel_dvd_vdp(){
  uint16_t A[31] = {282, 756, 280, 1816, 280, 756, 280, 780, 254, 782, 280, 1796, 278, 1820, 276, 758, 280, 782, 254, 782, 278, 1796, 278, 1818, 252, 1820, 278, 782, 254, 782, 278}; // DENON 231C uint64_t data = 0x231C;
  uint16_t B[31] = {256, 780, 284, 1792, 280, 780, 280, 758, 280, 780, 254, 782, 280, 758, 278, 1818, 278, 1796, 280, 1818, 254, 782, 280, 758, 278, 782, 252, 1820, 278, 1818, 254}; // DENON 20E3 uint64_t data = 0x20E3; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"dvd/cdp\"}");
}
void handle_Denon_changeChannel_tv_dbs(){
  uint16_t A[31] = {282, 754, 282, 1816, 254, 782, 280, 756, 280, 782, 278, 1794, 280, 782, 254, 782, 280, 1794, 278, 782, 278, 758, 280, 1818, 254, 1820, 278, 758, 278, 782, 252}; // DENON 224C uint64_t data = 0x224C;
  uint16_t B[31] = {282, 778, 280, 1792, 282, 780, 254, 782, 280, 758, 278, 782, 278, 1794, 280, 1818, 254, 782, 278, 1794, 278, 1820, 276, 760, 280, 782, 254, 1820, 278, 1794, 278}; // DENON 21B3 uint64_t data = 0x21B3; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"tv/dbs\"}");
}
void handle_Denon_changeChannel_vcr_one(){
  uint16_t A[31] = {280, 756, 282, 1794, 278, 780, 280, 758, 278, 782, 276, 758, 280, 1818, 254, 782, 278, 758, 278, 1820, 252, 1820, 278, 760, 276, 784, 278, 1796, 278, 1818, 254}; // DENON 2133 uint64_t data = 0x2133; 
  uint16_t B[31] = {282, 754, 280, 1818, 280, 756, 280, 782, 278, 758, 280, 1818, 254, 782, 278, 1794, 278, 1820, 252, 782, 280, 760, 276, 1820, 276, 1796, 278, 782, 252, 784, 278}; // DENON 22CC uint64_t data = 0x22CC;
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"vcr-1\"}");
}
void handle_Denon_changeChannel_vcr_two(){
  uint16_t A[31] = {280, 756, 282, 1792, 278, 782, 280, 758, 278, 782, 278, 1794, 280, 782, 254, 784, 278, 758, 278, 1820, 252, 1820, 280, 782, 254, 784, 276, 1796, 278, 1818, 254}; // DENON 2233 uint64_t data = 0x2233;
  uint16_t B[31] = {280, 780, 280, 1792, 280, 780, 254, 782, 280, 758, 278, 782, 276, 1796, 280, 1818, 252, 1820, 278, 758, 278, 782, 252, 1820, 280, 1818, 254, 782, 278, 758, 278}; // DENON 21CC uint64_t data = 0x21CC; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"vcr-2\"}");
}
void handle_Denon_changeChannel_v_aux(){
  uint16_t A[31] = {282, 780, 280, 1794, 280, 758, 278, 782, 278, 758, 278, 1818, 252, 1820, 280, 758, 276, 782, 278, 1796, 278, 1818, 254, 784, 288, 750, 278, 1820, 276, 1796, 278}; // DENON 2333 uint64_t data = 0x2333;
  uint16_t B[31] = {282, 756, 280, 1816, 280, 756, 280, 758, 278, 782, 278, 758, 278, 782, 252, 1820, 280, 1794, 278, 782, 278, 758, 278, 1818, 254, 1820, 278, 758, 278, 782, 278}; // DENON 20CC uint64_t data = 0x20CC; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"channel\": \"v-aux\"}");
}
