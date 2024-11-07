
int redP = A1;
int greenP = A2;
int blueP = A3;

int value1,value2,value3;

void setup() {
  //Set baud 
  Serial.begin(9600);


  // Inputs
  pinMode(redP,INPUT);
  pinMode(greenP,INPUT);
  pinMode(blueP,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly


  value1 = analogRead(redP);
  value2 = analogRead(greenP);
  value3 = analogRead(blueP);

  Serial.println(value1);
  Serial.println(value2);
  Serial.println(value3);
  delay(500);



}
