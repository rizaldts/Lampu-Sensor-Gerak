#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pirPin = 2;    // Pin sensor PIR
const int ledPin = 13;   // Pin LED

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C LCD, 16 kolom, 2 baris

int motionDetected = LOW;
int detectionCount = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor Gerak:");
  
  Serial.begin(9600);
}

void loop() {
  motionDetected = digitalRead(pirPin);
  
  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH);
    detectionCount++;
    lcd.setCursor(0, 1);
    lcd.print("Gerakan: ");
    lcd.print(detectionCount);
    lcd.print("    ");
    Serial.println("Gerakan terdeteksi! Lampu menyala.");
    delay(5000);  // Lampu tetap menyala selama 5 detik
  } else {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Tidak Ada Gerakan");
    Serial.println("Tidak ada gerakan. Lampu mati.");
  }
  
  delay(1000);  // Jeda 1 detik sebelum pengecekan berikutnya
}