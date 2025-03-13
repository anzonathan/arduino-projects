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

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  Serial.print(F("RFID Tag UID:"));

  printHex(rfid.uid.uidByte, rfid.uid.size);
  
  Serial.println("");

  lcd.setCursor(0,2);
  char UID[] = {rfid.uid.uidByte};
  lcd.print(UID);
  

  rfid.PICC_HaltA(); // Halt PICC
}

//Routine to dump a byte array as hex values to Serial. 
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
