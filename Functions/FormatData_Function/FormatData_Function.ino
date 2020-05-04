/*FormatData Function
* ------------------- 
* 
* This code formats the data in the txArray into 6 bytes
* if the transmitFlag (txFlag) has been set
* 
* The formatting is done to compress the data to be 
* transmitted as much as possible so as to speed up the 
* data communication rate for a faster response
* 
* This function is something like a software channel encoder
* function kinda thing!!!
* 
*/

//txArray definition (carried over from DataHandler Function)
int txArray[11];         //[eStop, jsAx, jsAy, jsAs, jsBx, jsBy, jsBs, tsw1, tsw2, tsw3, tsw4]
                         //  0      1     2     3     4     5     6    7     8      9     10 

byte tbyte1;
byte tbyte2;
byte tbyte3;
byte tbyte4;
byte tbyte5;
byte tbyte6;

void setup() {

  Serial.begin(9600);

  //txArray test values
  txArray[0]  = 0; 
  txArray[1]  = 492;
  txArray[2]  = 511;
  txArray[3]  = 1;
  txArray[4]  = 1020;
  txArray[5]  = 1021;
  txArray[6]  = 0;
  txArray[7]  = 0;
  txArray[8]  = 1;
  txArray[9]  = 1;
  txArray[10] = 0;
  txArray[11] = 1;

}

void loop() {
  
  //format tbyte1
  //-------------
  //Estop
  bitWrite(tbyte1, 0, bitRead(txArray[0], 0));
  
  //Joystick Ax bit 0 to bit 6
  for(int i=1; i<8; i++)
  {
    bitWrite(tbyte1, i, bitRead(txArray[1], i-1)); 
  }

  //format tbyte2
  //-------------

  //Joystick Ax bit 7 to bit 9
  for(int j=0; j<3; j++)
  {
    bitWrite(tbyte2, j, bitRead(txArray[1], j+7)); 
  }

  //Joystick Ay bit 0 to bit 4
  for(int k=3; k<8; k++)
  {
    bitWrite(tbyte2, k, bitRead(txArray[2], k-3)); 
  }
  
  //format tbyte3
  //-------------

  //Joystick Ay bit 5 to bit 9
  for(int l=0; l<5; l++)
  {
    bitWrite(tbyte3, l, bitRead(txArray[2], l+5)); 
  }

  //Joystick As
  bitWrite(tbyte3, 5, bitRead(txArray[3], 0));

  //Joystick Bx bit 0 to bit 1
  for(int m=6; m<8; m++)
  {
    bitWrite(tbyte3, m, bitRead(txArray[4],m-6)); 
  }

  //stuff

  //format tbyte4
  //-------------

  //Joystick Bx bit 2 to bit 9
  for(int n=0; n<8; n++)
  {
    bitWrite(tbyte4, n, bitRead(txArray[4], n+2)); 
  }

  //format tbyte5
  //-------------

  //Joystick By bit 0 to bit 7
  for(int o=0; o<8; o++)
  {
    bitWrite(tbyte5, o, bitRead(txArray[5], o)); 
  }

  //format tbyte6
  //-------------

  //Joystick By bit 8 to bit 9
  for(int p=0; p<2; p++)
  {
    bitWrite(tbyte6, p, bitRead(txArray[5], p+8));
  }

  //Joystick Bs
  bitWrite(tbyte6, 2, bitRead(txArray[6], 0));

  //Toggle Switches 1 to 5
  for(int q=3; q<8; q++)
  {
    bitWrite(tbyte6, q, bitRead(txArray[q+4], 0));
  }

  /*
  //for debugging   
  Serial.println(tbyte1);
  Serial.println(tbyte2);
  Serial.println(tbyte3);
  Serial.println(tbyte4);
  Serial.println(tbyte5);
  Serial.println(tbyte6);
  */
  
}
