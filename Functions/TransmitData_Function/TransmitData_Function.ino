/*TransmitData Function
* --------------------- 
* This code transmits the joysticks and toggle switch input state data
* that has been formatted and stored into 6 bytes if the transmit flag (txFlag) is set
* 
* The txFlag is set if the user has moved the joysticks or toggled the switches 
* 
* If the remote is idle and the user has not moved the joysticks or toggled the
* switches the txFlag will be low
* 
*/

#include <SoftwareSerial.h>
#define tx 2
#define rx 3
#define txLED 6
SoftwareSerial bt(rx, tx); //RX, TX

byte tbyte1;
byte tbyte2;
byte tbyte3;
byte tbyte4;
byte tbyte5;
byte tbyte6;

void setup() {

  Serial.begin(9600);
  bt.begin(9600);

  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pinMode(txLED, OUTPUT);

  //tbyte test values 
  tbyte1 = 216; 
  tbyte2 = 251; 
  tbyte3 = 47;
  tbyte4 = 255;
  tbyte5 = 253;
  tbyte6 = 179;
  
}

void loop() {

  digitalWrite(txLED, HIGH);
  bt.write(tbyte1);
  bt.write(tbyte2);
  bt.write(tbyte3);
  bt.write(tbyte4);
  bt.write(tbyte5);
  bt.write(tbyte6);
  digitalWrite(txLED, LOW);

}
