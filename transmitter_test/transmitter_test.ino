
char SYGNET[5+2] = "ZSETV";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("Tally transmitter (Master,Serial) ");
  Serial.println("Create by Tomasz Osikowski <MrTomek.pl>");
  Serial.println("Custom tally light v0.3");
  Serial1.println("Tally transmitter (Master,Serial1) ");
  Serial1.println("Create by Tomasz Osikowski <MrTomek.pl>");
  Serial1.println("Custom tally light v0.3");
}

void loop() {
  send(0x02);
  delay(1000);
  send(0x01);
  delay(1000);
  send(0x00);
  delay(300);
  
  send(0x12);
  delay(300);
  send(0x11);
  delay(300);
  send(0x10);
  delay(300);
  
  send(0x22);
  delay(300);
  send(0x21);
  delay(300);
  send(0x20);
  delay(300);
    
  send(0x32);
  delay(1000);
  send(0x31);
  delay(1000);
  send(0x30);
  delay(300);
}

void send(int comand){
  for (int i = 0; i < 5; i++)
  {
    Serial1.print(SYGNET[i], HEX);
  }
  printHex(comand);
  printHex(comand);
  Serial1.print("\n");
}

char printHex(int num) {
  char tmp[16];
  sprintf(tmp, "%.2X", num);
  Serial1.print(tmp);
}
