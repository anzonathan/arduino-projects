//Blink program to test board with default led 13

int red = A4;

void setup(){

  pinMode(red,OUTPUT);
}

void loop(){

  digitalWrite(red,HIGH);
  delay(3000);
  digitalWrite(red,LOW);
  delay(1000);
}
