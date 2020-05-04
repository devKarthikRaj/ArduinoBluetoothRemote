/*Arduino Bluetooth Remote Main Code
* ----------------------------------
* 
* 
*/

//Adding Libraries
#include <SoftwareSerial.h>

//Pin Declarations
#define tx         2
#define rx         3
#define btStatePin 4
#define connLED    5
#define txLED      6
#define eStop      7
#define tsw1       8
#define tsw2       9
#define tsw3      10
#define tsw4      11
#define jsAs      12
#define jsBs      13
#define jsAx      A0
#define jsAy      A1
#define jsBx      A2
#define jsBy      A3

//Bluetooth Initial Configuration
SoftwareSerial bt(rx, tx); //RX, TX

//Variable Declarations
bool txFlag;
byte tbyte1;
byte tbyte2;
byte tbyte3;
byte tbyte4;
byte tbyte5;
byte tbyte6;

//Array Declarations     //Array Structures
int inputStateArray[11]; //[eStop, jsAx, jsAy, jsAs, jsBx, jsBy, jsBs, tsw1, tsw2, tsw3, tsw4]
                         //  0      1     2     3     4     5     6    7     8      9     10    
int txArray[11];         //[eStop, jsAx, jsAy, jsAs, jsBx, jsBy, jsBs, tsw1, tsw2, tsw3, tsw4]
                         //  0      1     2     3     4     5     6    7     8      9     10   


void setup() {

  //Baud Rate Settings
  Serial.begin(9600);
  bt.begin(9600);

  //IO Definitions 
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pinMode(btStatePin, INPUT);
  pinMode(connLED, OUTPUT);
  pinMode(txLED, OUTPUT);
  pinMode(eStop, INPUT);
  pinMode(jsAx, INPUT);
  pinMode(jsAy, INPUT);
  pinMode(jsAs, INPUT);
  pinMode(jsBx, INPUT);
  pinMode(jsBy, INPUT);
  pinMode(jsBs, INPUT);
  pinMode(tsw1, INPUT);
  pinMode(tsw2, INPUT);
  pinMode(tsw3, INPUT);
  pinMode(tsw4, INPUT);

  //Setting inital pin states to read joystick push button state
  digitalWrite(jsAs, HIGH); 
  digitalWrite(jsBs, HIGH); 
  
}

void loop() {

  while(BtConnection() == 0) //while bluetooth is not connected
  {
    ; //do nothing 
  }

  //if bluetooth is connected... continue...
  DataHandler();
  Serial.println(txFlag);
  if(txFlag == true)
  {
    FormatData();
    TransmitData();
  }
  Serial.println(txFlag);
}

int BtConnection() {

  int btState = digitalRead(btStatePin);

  if(btState==0)
  {
    digitalWrite(connLED, LOW);
  }

  else if(btState==1)
  {
    digitalWrite(connLED, HIGH);
  }

  return btState;
  
}

void DataHandler() {

  inputStateArray[0]  = digitalRead(eStop);
  inputStateArray[1]  = analogRead(jsAx);
  inputStateArray[2]  = analogRead(jsAy);
  inputStateArray[3]  = digitalRead(jsAs);
  inputStateArray[4]  = analogRead(jsBx);
  inputStateArray[5]  = analogRead(jsBy);
  inputStateArray[6]  = digitalRead(jsBs);
  inputStateArray[7]  = digitalRead(tsw1);
  inputStateArray[8]  = digitalRead(tsw2);
  inputStateArray[9]  = digitalRead(tsw3);
  inputStateArray[10] = digitalRead(tsw4);
  
  switch(0)
  {
    case 0:
            if(inputStateArray[0] == txArray[0])
            {
              goto state1;
            }
            else
            {
              goto userInput;
            }
            break;
    case 1:
            state1:
                    if(inputStateArray[1] == txArray[1] || inputStateArray[1] == txArray[1]-1 || inputStateArray[1] == txArray[1]+1)
                    {
                      goto state2;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
    case 2:
            state2:
                    if(inputStateArray[2] == txArray[2] || inputStateArray[2] == txArray[2]-1 || inputStateArray[2] == txArray[2]+1)
                    {
                      goto state3;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
    case 3:
            state3:
                    if(inputStateArray[3] == txArray[3])
                    {
                      goto state4;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
    case 4:
            state4:
                    if(inputStateArray[4] == txArray[4] || inputStateArray[4] == txArray[4]-1 || inputStateArray[4] == txArray[4]+1)
                    {
                      goto state5;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
    case 5:
            state5:
                    if(inputStateArray[5] == txArray[5] || inputStateArray[5] == txArray[5]-1 || inputStateArray[5] == txArray[5]+1)
                    {
                      goto state6;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
    case 6:
            state6:
                    if(inputStateArray[6] == txArray[6])
                    {
                      goto state7;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
    case 7:
            state7:
                    if(inputStateArray[7] == txArray[7])
                    {
                      goto state8;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;   
    case 8:
            state8:
                    if(inputStateArray[8] == txArray[8])
                    {
                      goto state9;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;   
    case 9:
            state9:
                    if(inputStateArray[9] == txArray[9])
                    {
                      goto state10;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break; 
    case 10:
            state10:
                    if(inputStateArray[10] == txArray[10])
                    {
                      goto noUserInput;
                    }
                    else
                    {
                      goto userInput;
                    }
                    break;
  }

  noUserInput:
                //Serial.println(0);
                return;

  userInput: 
                //Serial.println(1);
                txFlag = true;
                for(int j=0; j<11;j++)
                {
                  txArray[j] = inputStateArray[j];
                }
                return;
                
}

void FormatData() {

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
  
}

void TransmitData() {

  digitalWrite(txLED, HIGH);
  bt.write(tbyte1);
  bt.write(tbyte2);
  bt.write(tbyte3);
  bt.write(tbyte4);
  bt.write(tbyte5);
  bt.write(tbyte6);
  txFlag = false;
  digitalWrite(txLED, LOW);
  
}
