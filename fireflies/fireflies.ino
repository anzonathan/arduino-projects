

int led = 13; 
int x;// python read 

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);

  pinMode(led,OUTPUT);
}

void  loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();

  if (x == 1){
      digitalWrite(led,HIGH);
      Serial.println("On");
  }

  else if (x == 2){
      digitalWrite(led,LOW);
      Serial.println("Off");

}

  else {Serial.println("Invalid");}
}
