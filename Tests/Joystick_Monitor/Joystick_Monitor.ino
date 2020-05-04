/*Joystick Monitor
* ----------------
* 
* This code reads the X, Y and switch outputs of 2 joysticks
* 
* Use putty as the serial monitor
*/

#define Ax A0
#define Ay A1
#define As 12
#define Bx A2
#define By A3
#define Bs 13


void setup() {
  
  Serial.begin(9600);
  
  pinMode(Ax, INPUT);
  pinMode(Ay, INPUT);
  pinMode(As, INPUT);
  pinMode(Bx, INPUT);
  pinMode(By, INPUT);
  pinMode(Bs, INPUT);

  digitalWrite(As, HIGH);
  digitalWrite(Bs, HIGH);
}

void loop() {
  
  Serial.print("Ax:");
  Serial.print(analogRead(Ax));

  Serial.print("   ");
  
  Serial.print("Ay:");
  Serial.print(analogRead(Ay));

  Serial.print("   ");

  Serial.print("As:");
  Serial.print(digitalRead(As));

  Serial.print("   ");
  
  Serial.print("Bx:");
  Serial.print(analogRead(Bx));

  Serial.print("   ");

  Serial.print("By:");
  Serial.print(analogRead(By));

  Serial.print("   ");

  Serial.print("Bs:");
  Serial.print(digitalRead(Bs));

  Serial.print("   ");

  Serial.print("\r");  
  
} 
