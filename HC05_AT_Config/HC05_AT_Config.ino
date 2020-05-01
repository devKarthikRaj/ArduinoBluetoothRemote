#include <SoftwareSerial.h>
#define masterTx 2
#define masterRx 3
SoftwareSerial configBt(masterRx, masterTx); // RX, TX

void setup() 
{
  Serial.begin(38400);
  configBt.begin(38400);
  pinMode(masterTx, OUTPUT);
  pinMode(masterRx, INPUT);
}

void loop() 
{
  if(configBt.available()) //if the bluetooth module is sending something...
  {
    Serial.print(configBt.readString()); //print whatever the bluetooth module is sending 
  }
  
  if(Serial.available()) //if we have typed anything into the serial monitor input text box...
  {
    configBt.write(Serial.read()); //write whatever we typed into the serial monitor input text box to the bluetooth module
  }
}
