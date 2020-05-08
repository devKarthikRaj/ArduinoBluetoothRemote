/* Receiver with Decompression Testing
 * -----------------------------------
 * This code receives the 6 bytes sent from the TransmitterMain
 * and decompresses the 6 bytes to retrieve the original joystick and
 * toggle switch input states 
 * Then these input state values are stored in the rxArray
 * 
 */

#include <SoftwareSerial.h>

#define tx 2
#define rx 3

byte rbyte1;
byte rbyte2;
byte rbyte3;
byte rbyte4;
byte rbyte5;
byte rbyte6;

                         //Array Structure
int rxArray[11];         //[eStop, jsAx, jsAy, jsAs, jsBx, jsBy, jsBs, tsw1, tsw2, tsw3, tsw4]
                         //  0      1     2     3     4     5     6    7     8      9     10   

SoftwareSerial bt(rx, tx); //RX, TX

void setup() {

  Serial.begin(9600);
  bt.begin(9600);

  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);

}

void loop() {

  ReceiveData();
  DeformatData();
  ClearBuffer();
  
  //For debugging only
  //---------------------------------------------
  
  for(int b=0; b<11; b++)
  {
    Serial.println(rxArray[b]);
  }
  Serial.println("----------------------------");
  
  /*
  Serial.println(rbyte1);
  Serial.println(rbyte2);
  Serial.println(rbyte3);
  Serial.println(rbyte4);
  Serial.println(rbyte5);
  Serial.println(rbyte6);
  Serial.println("------------------");
  */
  //---------------------------------------------
}

void ReceiveData() {
  
  if(bt.available()==6)
  {
    rbyte1 = bt.read();
    rbyte2 = bt.read();
    rbyte3 = bt.read();
    rbyte4 = bt.read();
    rbyte5 = bt.read();
    rbyte6 = bt.read();
  }
}

void DeformatData() {

  //deformat rbyte1
  //---------------
  //Estop
  bitWrite(rxArray[0], 0, bitRead(rbyte1, 0));
  
  //Joystick Ax bit 0 to bit 6
  for(int i=1; i<8; i++)
  {
    bitWrite(rxArray[1], i-1, bitRead(rbyte1, i)); 
  }

  //deformat rbyte2
  //---------------

  //Joystick Ax bit 7 to bit 9
  for(int j=0; j<3; j++)
  {
    bitWrite(rxArray[1], j+7, bitRead(rbyte2, j)); 
  }

  //Joystick Ay bit 0 to bit 4
  for(int k=3; k<8; k++)
  {
    bitWrite(rxArray[2], k-3, bitRead(rbyte2, k)); 
  }
  
  //deformat rbyte3
  //---------------

  //Joystick Ay bit 5 to bit 9
  for(int l=0; l<5; l++)
  {
    bitWrite(rxArray[2], l+5, bitRead(rbyte3, l)); 
  }

  //Joystick As
  bitWrite(rxArray[3], 0, bitRead(rbyte3, 5));

  //Joystick Bx bit 0 to bit 1
  for(int m=6; m<8; m++)
  {
    bitWrite(rxArray[4], m-6, bitRead(rbyte3, m)); 
  }

  //deformat rbyte4
  //---------------

  //Joystick Bx bit 2 to bit 9
  for(int n=0; n<8; n++)
  {
    bitWrite(rxArray[4], n+2, bitRead(rbyte4, n)); 
  }

  //deformat rbyte5
  //---------------

  //Joystick By bit 0 to bit 7
  for(int o=0; o<8; o++)
  {
    bitWrite(rxArray[5], o, bitRead(rbyte5, o)); 
  }

  //deformat rbyte6
  //---------------

  //Joystick By bit 8 to bit 9
  for(int p=0; p<2; p++)
  {
    bitWrite(rxArray[5], p+8, bitRead(rbyte6, p));
  }

  //Joystick Bs
  bitWrite(rxArray[6], 0, bitRead(rbyte6, 2));

  //Toggle Switches 1 to 5
  for(int q=3; q<7; q++)
  {
    bitWrite(rxArray[q+4], 0, bitRead(rbyte6, q));
  }
}

void ClearBuffer() {
  while(bt.available()){    
    bt.read();
  }
}
