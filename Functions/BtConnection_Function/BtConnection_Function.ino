/*BtConnection Function
* ---------------------
* 
* This code monitors the HC05 state pin
* 
* The code will turn on an LED if bluetooth is connected and ready for data exchange and 
* turn off the LED if bluetooth is disconnected
* 
*/

#define btStatePin 4
#define connLED 5

void setup() {
  
  Serial.begin(9600);
  
  pinMode(btStatePin, INPUT);
  pinMode(connLED, OUTPUT);
   
}

void loop() {
  
  int btState = digitalRead(btStatePin);
  
  if(btState==0)
  {
    Serial.print(0);
    digitalWrite(connLED, LOW);
  }
  
  else if(btState==1)
  {
    Serial.print(1);
    digitalWrite(connLED, HIGH);
  }
  
}
