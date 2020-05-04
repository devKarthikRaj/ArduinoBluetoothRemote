/*DataHandler Function
*---------------------
*
* This code reads the input states of 2 joysticks, estop toggle switch and 4 other generic toggle switches
* 
* Then if the user operates the remote (that is, if the user moves the joysticks or toggles the switches)... 
* the code will set a transmit flag (txFlag) to indicate that the user has "operated" the remote
* 
* If the user doesn't touch the remote, the txFlag will be low;
* 
*/

//Emergency Stop 
#define eStop 7

//Joystick A
#define jsAx A0
#define jsAy A1
#define jsAs 12

//Joystick B
#define jsBx A2
#define jsBy A3
#define jsBs 13

//Toggle Switch
#define tsw1 8
#define tsw2 9
#define tsw3 10
#define tsw4 11


//Array Declarations     //Array Structures
int inputStateArray[11]; //[eStop, jsAx, jsAy, jsAs, jsBx, jsBy, jsBs, tsw1, tsw2, tsw3, tsw4]
					               //	 0	    1     2     3     4     5     6    7     8      9     10    
int txArray[11];         //[eStop, jsAx, jsAy, jsAs, jsBx, jsBy, jsBs, tsw1, tsw2, tsw3, tsw4]
					               //	 0	    1     2     3     4     5     6    7     8      9     10   
                        
bool txFlag; //Transmit Flag to alert transmit function that user has changed operated the remote

void setup() {
  
	  Serial.begin(9600);

    pinMode(jsAx, INPUT);
    pinMode(jsAy, INPUT);
    pinMode(jsAs, INPUT);
    pinMode(jsBx, INPUT);
    pinMode(jsBy, INPUT);
    pinMode(jsBs, INPUT);

    digitalWrite(jsAs, HIGH); //activate atmega328p internal pullup resistor
    digitalWrite(jsBs, HIGH); //activate atmega328p internal pullup resistor

    pinMode(tsw1, INPUT);
    pinMode(tsw2, INPUT);
    pinMode(tsw3, INPUT);
    pinMode(tsw4, INPUT);
    
    txFlag = false;

    //initial values
    txArray[0] = 0;
    txArray[1] = 0;
    txArray[2] = 0;
    txArray[3] = 0;
    txArray[4] = 0;
    txArray[5] = 0;
    txArray[6] = 0;
    txArray[7] = 0;
    txArray[8] = 0;
    txArray[9] = 0;
    txArray[10] = 0;
    
}

void loop() {
  
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
                    if(inputStateArray[1] == txArray[1] || inputStateArray[1] == txArray[1]-1 || inputStateArray[1] == txArray[1]+1 || inputStateArray[1] == txArray[1]+2 || inputStateArray[1] == txArray[1]-2 || inputStateArray[1] == txArray[1]+3 || inputStateArray[1] == txArray[1]-3 || inputStateArray[1] == txArray[1]+4 || inputStateArray[1] == txArray[1]-4 || inputStateArray[1] == txArray[1]+5 || inputStateArray[1] == txArray[1]-5)                                                            
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
                    if(inputStateArray[2] == txArray[2] || inputStateArray[2] == txArray[2]-1 || inputStateArray[2] == txArray[2]+1 || inputStateArray[2] == txArray[2]+2 || inputStateArray[2] == txArray[2]-2 || inputStateArray[2] == txArray[2]+3 || inputStateArray[2] == txArray[2]-3 || inputStateArray[2] == txArray[2]+4 || inputStateArray[2] == txArray[2]-4 || inputStateArray[2] == txArray[2]+5 || inputStateArray[2] == txArray[2]-5)
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
                    if(inputStateArray[4] == txArray[4] || inputStateArray[4] == txArray[4]-1 || inputStateArray[4] == txArray[4]+1 || inputStateArray[4] == txArray[4]+2 || inputStateArray[4] == txArray[4]-2 || inputStateArray[4] == txArray[4]+3 || inputStateArray[4] == txArray[4]-3 || inputStateArray[4] == txArray[4]+4 || inputStateArray[4] == txArray[4]-4 || inputStateArray[4] == txArray[4]+5 || inputStateArray[4] == txArray[4]-5)
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
                    if(inputStateArray[5] == txArray[5] || inputStateArray[5] == txArray[5]-1 || inputStateArray[5] == txArray[5]+1 || inputStateArray[5] == txArray[5]+2 || inputStateArray[5] == txArray[5]-2 || inputStateArray[5] == txArray[5]+3 || inputStateArray[5] == txArray[5]-3 || inputStateArray[5] == txArray[5]+4 || inputStateArray[5] == txArray[5]-4 || inputStateArray[5] == txArray[5]+5 || inputStateArray[5] == txArray[5]-5)
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
                Serial.println(0);
                return;

  userInput: 
                Serial.println(1);
                txFlag = true;
                for(int j=0; j<11;j++)
                {
                  txArray[j] = inputStateArray[j];
                }
                return;
                
}
