//Keycard System

//Rfid lib
#include <SPI.h> 
#include <MFRC522.h>


//lcd lib
#include <LiquidCrystal_I2C.h>

//Initialize the LCD 
LiquidCrystal_I2C lcd(0x27,  16, 2);

//Initialize the RFID Reader 
#define SS_PIN 10
#define RST_PIN 7
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 
/*
Jane
A6 59 37 BB
John
08 33 AF 1B
Jewel
04 7C C6 DB
Jasper
C1 C0 CD CF
*/

//const int numOfCards = 4;

//byte cards[numOfCards][4] = {{0xA6,0x59,0x37,0xBB},{0x08,0x33,0xAF,0x1B},{0x04,0x7C,0xC6,0xDB},{0xC1,0xC0,0xCD,0xCF}};
//String names[numOfCards] = {"Jane","John","Jewel","Jasper"};

void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init RC522 

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RFID Tag UID");

}
 
void loop() {
  byte card_ID[4];//card UID size 4byte
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  //Serial.print(F("RFID Tag UID:"));
  //printUID(rfid.uid.uidByte);
  //Serial.println("UID :");
  
  Serial.print(UID(rfid.uid.uidByte));
  Serial.println("");




  lcd.setCursor(0,2);
  //char UID[] = {rfid.uid.uidByte};
  //lcd.print(UID);
  

  rfid.PICC_HaltA(); // Halt PICC
}

//Funtion to return UID as a string
String UID(byte *buffer) {
  
  String index = "";

  for (byte i = 0; i < 4; i++) {

    String bit = String(buffer[i], HEX);
    index.concat(bit);
  }

 return index;
}

