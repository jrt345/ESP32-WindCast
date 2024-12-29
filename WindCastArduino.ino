#include "apiwifikeys.h" //API keys and wifi credentials

#include <WiFi.h> // Built-in library for ESP32 Wi-Fi
#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

void setup() {
  lcd.begin(16, 2);
  lcd.print("WindCast:");
  
  // Start the serial monitor for debugging
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Establish connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print connection details
  Serial.println("\nWi-Fi connected!");
  Serial.print("ESP32 IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
