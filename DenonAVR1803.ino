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
void handle_Denon_Wakeup(){
  uint16_t A[31] = {280, 756, 280, 1818, 278, 758, 280, 758, 276, 784, 278, 1796, 278, 784, 250, 784, 278, 760, 276, 784, 276, 1796, 276, 1822, 252, 1822, 276, 760, 276, 784, 252}; // DENON 221C uint64_t data = 0x221C;
  uint16_t B[31] = {278, 782, 280, 1794, 280, 782, 276, 760, 278, 760, 276, 784, 278, 1796, 278, 1820, 252, 1822, 278, 1796, 276, 784, 276, 760, 278, 784, 252, 1822, 276, 1796, 276}; // DENON 21E3 uint64_t data = 0x21E3;
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"wakleup\": true}");
}
void handle_Denon_Standby(){
  String response = "Standby";
  uint16_t A[31] = {280, 780, 278, 1794, 280, 758, 278, 784, 278, 758, 278, 784, 252, 1820, 278, 760, 276, 784, 278, 758, 278, 1798, 274, 1822, 278, 1796, 276, 784, 276, 760, 278}; // DENON 211C uint64_t data = 0x211C; 
  uint16_t B[31] = {280, 756, 280, 1818, 278, 758, 280, 758, 276, 784, 278, 1796, 278, 784, 252, 1820, 278, 1796, 276, 1822, 276, 760, 278, 782, 252, 786, 278, 1796, 276, 1822, 274}; // DENON 22E3 uint64_t data = 0x22E3; 
  send_DenonCommand(A,B);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"standby\": true}");
}