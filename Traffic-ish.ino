int green = 10;
int yellow = 5;
int red = A4;

void setup() {
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);


}

void loop() {
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(green,LOW);
  delay(1000);
  digitalWrite(yellow,HIGH);
  delay(500);
  digitalWrite(yellow,LOW);
  delay(1000);
  digitalWrite(red,HIGH);
  delay(250);
  digitalWrite(red,LOW);
  delay(1000);

}
