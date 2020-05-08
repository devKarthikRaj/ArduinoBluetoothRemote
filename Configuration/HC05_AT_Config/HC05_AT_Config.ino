/* HC05 AT Config
 * --------------
 * This code can be used to log in to the HC05's AT command mode and configure the HC05 bluetooth module
 */

#include <SoftwareSerial.h>

#define tx 2
#define rx 3

SoftwareSerial configBt(rx, tx); // RX, TX

void setup() 
{
  //HC05 AT mode baud rate is 38400
  Serial.begin(38400);
  configBt.begin(38400);
  
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);  
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
