//Inputing keyboard strokes into the serial monitor

char kbyte; //Keyboard byte
int led = 13; 

void setup() {
  
  //Serial Monitor
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

}

void loop() {

  kbyte = Serial.read();
  Serial.println(kbyte);
  delay(500);

  if (kbyte == '1'){
      digitalWrite(led,HIGH);
  }

  else if (kbyte == '2'){
      digitalWrite(led,LOW);
  }
}
