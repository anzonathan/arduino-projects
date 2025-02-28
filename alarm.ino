int LDR = A4;
int Button = A5;

int Gled = 13;
int Rled = 12;
int Buzzer = 11;

int buttonState;
int LDRState;

void setup() {
  Serial.begin(9600);

  //Inputs
  pinMode(LDR,INPUT);
  pinMode(Button,INPUT);

  //Outputs
  pinMode(Buzzer,OUTPUT);
  pinMode(Gled,OUTPUT);
  pinMode(Rled,OUTPUT);
  

}

void loop() {

  //button input 
  buttonState = digitalRead(Button);
  //Serial.println(buttonState);
  //delay(1000);

  //LDR input
  LDRState = analogRead(LDR);
  Serial.println(LDRState);
  delay(100);

  if (LDRState < 20){
    digitalWrite(Rled,HIGH);
    digitalWrite(Gled,LOW);
    tone(Buzzer,1000);
    
    if (buttonState == 1) {
    digitalWrite(Rled,HIGH);
    digitalWrite(Gled,LOW);
    noTone(Buzzer);
    
  }


  }


  else if (LDRState > 20)  {
    digitalWrite(Rled,LOW);
    digitalWrite(Gled,HIGH);
    noTone(Buzzer);
    
  }

}
