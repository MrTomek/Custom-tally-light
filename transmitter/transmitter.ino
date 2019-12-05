#define LIVE_CAM_0 11
#define LIVE_CAM_1 10
#define LIVE_CAM_2 9
#define LIVE_CAM_3 8

#define PREW_CAM_0 7
#define PREW_CAM_1 6
#define PREW_CAM_2 5
#define PREW_CAM_3 4
 
char SYGNET[5+2] = "ZSETV";

void setup() {
  pinMode(LIVE_CAM_0,INPUT);
  pinMode(LIVE_CAM_1,INPUT);
  pinMode(LIVE_CAM_2,INPUT);
  pinMode(LIVE_CAM_3,INPUT);
  
  
  pinMode(PREW_CAM_0,INPUT);
  pinMode(PREW_CAM_1,INPUT);
  pinMode(PREW_CAM_2,INPUT);
  pinMode(PREW_CAM_3,INPUT);
  
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
  //int liveCam0 = digitalRead(LIVE_CAM_0);
  //int liveCam1 = digitalRead(LIVE_CAM_1);
  //int liveCam2 = digitalRead(LIVE_CAM_2);
  //int liveCam3 = digitalRead(LIVE_CAM_3);
  
  //int prewCam0 = digitalRead(PREW_CAM_0);
  //int prewCam1 = digitalRead(PREW_CAM_1);
  //int prewCam2 = digitalRead(PREW_CAM_2);
  //int prewCam3 = digitalRead(PREW_CAM_3);
  
  
  if (digitalRead(LIVE_CAM_0) == HIGH) send(0x02); 
  else if (digitalRead(PREW_CAM_0) == HIGH) send(0x01);
  else send(0x00);

  if (digitalRead(LIVE_CAM_1) == HIGH) send(0x12); 
  else if (digitalRead(PREW_CAM_1) == HIGH) send(0x11);
  else send(0x10);
  
  if (digitalRead(LIVE_CAM_2) == HIGH) send(0x22); 
  else if (digitalRead(PREW_CAM_2) == HIGH) send(0x21);
  else send(0x20);

  if (digitalRead(LIVE_CAM_3) == HIGH) send(0x32); 
  else if (digitalRead(PREW_CAM_3) == HIGH) send(0x31);
  else send(0x30);

  //delay(10);
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
