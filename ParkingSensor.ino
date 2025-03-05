// Car Sonar System 
// by index

// Functions:
/*

1. 3 Ultrasonic sensor Ranges (define Parameters)
2. Each Parameter is triggers a certain led or Buzzer
3. LCD Monitors Distance 

*/

//alert function

#include <LiquidCrystal.h>

//Front Unit 
int FIZ1 = 10; //Front Indicator Zone -n 
int FIZ2 = 8;
int FIZ3 = 6;

int TFS = 9; //Front Sensor Trigger
int EFS = 5; //Front Sensor Echo

//Rear Unit 

int RIZ1 = 12; //Rear Indicator Zone -n 
int RIZ2 = 7;
int RIZ3 = 2;

int TRS = 11; //Rear Sensor Trigger
int ERS = 3; //Rear Sensor Echo


//Output 

const int rs = 13, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buzzer =4;

//States

float fduration, fdistance, rduration, rdistance;



int z1 = 180;
int z2 = 100;
int z3 = 70;


void setup() {


  //Outputs 
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.write("Hello World");
  
  
  pinMode(FIZ1,OUTPUT);
  pinMode(FIZ2,OUTPUT);
  pinMode(FIZ3,OUTPUT);

  pinMode(RIZ1,OUTPUT);
  pinMode(RIZ2,OUTPUT);
  pinMode(RIZ3,OUTPUT);

  pinMode(buzzer,OUTPUT);



  pinMode(TFS, OUTPUT);
  pinMode(TRS, OUTPUT);

  //Inputs 

  pinMode(EFS, INPUT);
  pinMode(ERS, INPUT);

}

void loop() {
  
  digitalWrite(TFS, LOW);
  delayMicroseconds(2);
  digitalWrite(TFS, HIGH);
  delayMicroseconds(10);
  digitalWrite(TFS, LOW);
  
  fduration = pulseIn(EFS, HIGH);
  fdistance = (fduration*.0343)/2;
  
    
  digitalWrite(TRS, LOW);
  delayMicroseconds(2);
  digitalWrite(TRS, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRS, LOW);
  
  rduration = pulseIn(ERS, HIGH);
  rdistance = (rduration*.0343)/2;
  
  Serial.print("Front Distance: ");
  Serial.print(fdistance);
  Serial.print(" Rear Distance: ");
  Serial.println(rdistance);
  delay(500);



  /*
  if (Serial.available()) {

    // wait a bit for the entire message to arrive

    delay(100);

    // clear the screen

    lcd.clear();

    // read all the available characters

    while (Serial.available() > 0) {

      // display each character to the LCD

      lcd.write(Serial.read());

    }

  }*/
  

  //Print on Displays Distance

 

//front Sensor
  if ((fdistance <= z1) && (fdistance >= z2)){

    digitalWrite(FIZ1, HIGH);

    digitalWrite(FIZ2, LOW);
    digitalWrite(FIZ3, LOW);


  }

  else if ((fdistance <= z2) && (fdistance >= z3)){

    digitalWrite(FIZ2, HIGH);

    digitalWrite(FIZ1, LOW);
    digitalWrite(FIZ3, LOW);

  }

  else if ((fdistance <= z3) && (fdistance >= 0)){

    digitalWrite(FIZ3, HIGH);

    digitalWrite(FIZ1, LOW);
    digitalWrite(FIZ2, LOW);
    alert();

  }



//Rear Sensor 
if ((rdistance <= z1) && (rdistance >= z2)){

    digitalWrite(RIZ1, HIGH);

    digitalWrite(RIZ2, LOW);
    digitalWrite(RIZ3, LOW);


  }

  else if ((rdistance <= z2) && (rdistance >= z3)){

    digitalWrite(RIZ2, HIGH);

    digitalWrite(RIZ1, LOW);
    digitalWrite(RIZ3, LOW);

  }

  else if ((rdistance <= z3) && (rdistance >= 0)){

    digitalWrite(RIZ3, HIGH);

    digitalWrite(RIZ1, LOW);
    digitalWrite(RIZ2, LOW);
    alert();


  }
  

  
  


}


int alert(){
	tone(buzzer,1000);
  	delay(300);
  	noTone(buzzer);
    delay(100);
}
s
