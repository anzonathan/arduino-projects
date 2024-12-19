#define NUM_LEDS 5   // Number of LEDs
#define POT_PIN A0    // Analog pin connected to the potentiometer

//led number
int l1 = 8;
int l2 = 9;
int l3 = 10;
int l4 = 11;
int l5 = 12;

//Sensor Min and Max
const int Min = 0;
const int Max = 1023;

//int ledPins[NUM_LEDS] = {l1,l2,l3,l4,l5};

void setup() {
  Serial.begin(9600);

  // Set all LED pins as outputs
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);

  //Set Potentiometer as input
  pinMode(A0, INPUT);

}

void loop() {
    // Read the potentiometer value (0 to 1023)
    int potValue = analogRead(A0);

    //interval value for pot 
    int index = map(potValue, Min, Max, 0,4);

    if (potValue == 0){
        digitalWrite(l1,LOW);
        digitalWrite(l2,LOW);
        digitalWrite(l3,LOW);
        digitalWrite(l4,LOW);
        digitalWrite(l5,LOW);

    }

    else {

    //Switch Case
    switch (index){
      case 0:
        Serial.println("Soft " + String(potValue));
        digitalWrite(l1,HIGH);
        digitalWrite(l2,LOW);
        digitalWrite(l3,LOW);
        digitalWrite(l4,LOW);
        digitalWrite(l5,LOW);
        break;

      
      case 1:
        Serial.println("mid " + String(potValue));
        digitalWrite(l2,HIGH);
        digitalWrite(l3,LOW);
        digitalWrite(l4,LOW);
        digitalWrite(l5,LOW);
        break;

      
      case 2:
        Serial.println("loud " + String(potValue));
        digitalWrite(l3,HIGH);
        digitalWrite(l4,LOW);
        digitalWrite(l5,LOW);
        break;

      
      case 3:
        Serial.println("louder " + String(potValue));
        digitalWrite(l4,HIGH);
        digitalWrite(l5,LOW);
        break;

      
      case 4:
        digitalWrite(l5,HIGH);
        Serial.println("loudest " + String(potValue));
        break;

    }
    delay(500);}



}
