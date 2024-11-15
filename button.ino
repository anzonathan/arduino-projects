//Button Imput


int button = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int x = digitalRead(button);

  Serial.println(x);
  delay(100);

  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);

  while (x == 1){
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  }
  

}
