//Led Ladder Sequence 
//Variation 2: Ladder goes up then turns of down

//led number
int l1 = 8;
int l2 = 9;
int l3 = 10;
int l4 = 11;
int l5 = 12;


void setup() {

  // Set all LED pins as outputs
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);



}

void loop() {

  //up 
  digitalWrite(l1,HIGH);
  delay(300);
  digitalWrite(l2,HIGH);
  delay(300);
  digitalWrite(l3,HIGH);
  delay(300);
  digitalWrite(l4,HIGH);
  delay(300);
  digitalWrite(l5,HIGH);
  delay(300);
  //down
  digitalWrite(l5,LOW);
  delay(100);
  digitalWrite(l4,LOW);
  delay(100);
  digitalWrite(l3,LOW);
  delay(100);
  digitalWrite(l2,LOW);
  delay(100);
  digitalWrite(l1,LOW);
  delay(100);




}
