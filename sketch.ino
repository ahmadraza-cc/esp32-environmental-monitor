#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Pin Assignments
#define DHTPIN 15          // DHT22 Data Pin connected to GPIO 15
#define DHTTYPE DHT22      // Sensor Type
#define LED_ALERT 2        // Alert LED connected to GPIO 2

// Object Declarations
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16x2 LCD at I2C address 0x27

const float TEMP_THRESHOLD = 35.0; // Temperature threshold in Celsius

void setup() {
  Serial.begin(115200);
  pinMode(LED_ALERT, OUTPUT);
  
  dht.begin();
  lcd.init();
  lcd.backlight();

  // Startup Screen
  lcd.setCursor(0, 0);
  lcd.print("System Status:");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  // Read verification
  if (isnan(humidity) || isnan(tempC)) {
    Serial.println("Error reading DHT22 sensor!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!   ");
    return;
  }

  // Display Telemetry on LCD Screen
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(tempC, 1) + "C   ");
  lcd.setCursor(0, 1);
  lcd.print("Humid: " + String(humidity, 1) + "%   ");

  // Output Telemetry to Serial Monitor
  Serial.print("Telemetry -> Temp: ");
  Serial.print(tempC);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Temperature Threshold Safety Alarm Logic
  if (tempC > TEMP_THRESHOLD) {
    digitalWrite(LED_ALERT, HIGH);
    Serial.println("[ALERT] High Temperature Threshold Exceeded!");
  } else {
    digitalWrite(LED_ALERT, LOW);
  }

  delay(2000); // 2 second measurement delay
}
