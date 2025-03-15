#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String authorizedIds[] = {
  "1A2B3C4D5E",  
  "1F2E3D4C5B",  
  "1G2H3I4J5K",  
  "1L2M3N4O5P",  
  "1Q2R3S4T5U",  
  "1V2W3X4Y5Z",  
  "1A2F3D4G5H"
};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao inicializar o display OLED!"));
    while (true);
  }
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Sistema de Acesso");
  display.display();
  delay(2000);
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
      
      String readCardID = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        readCardID += String(mfrc522.uid.uidByte[i], HEX);
      }
      
      Serial.print("ID do cartão: ");
      Serial.println(readCardID);
      
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(1);

      bool accessGranted = false;
      for (int i = 0; i < 7; i++) {
        if (readCardID == authorizedIds[i]) {
          accessGranted = true;
          break;
        }
      }

      if (accessGranted) {
        display.setCursor(0, 20);
        display.setTextSize(2);
        display.print("Acesso Liberado");
      } else {
        display.setCursor(0, 20);
        display.setTextSize(2);
        display.print("Acesso Negado");
      }

      display.display();
      delay(3000);
      
      mfrc522.PICC_HaltA();
      mfrc522.PCD_StopCrypto1();
    }
  }
}
