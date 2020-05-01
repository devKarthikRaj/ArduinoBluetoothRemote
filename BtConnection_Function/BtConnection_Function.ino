/*BtConnection Function
* This code monitors the HC05 state pin
* The code will turn on an LED if bluetooth connected and 
* turn off the led if bluetooth disconnected
*/

int btStatePin = 4;
int txLED = 5;
void setup() {
  Serial.begin(9600);
  pinMode(btStatePin, INPUT);
  pinMode(txLED, OUTPUT); 
}

void loop() {
  int btState = digitalRead(btStatePin);
  if(btState==0)
  {
    Serial.print(0);
    digitalWrite(txLED, LOW);
  }
  if(btState==1)
  {
    Serial.print(1);
    digitalWrite(txLED, HIGH);
  }
}
