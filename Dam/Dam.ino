#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define TRIG_PIN  5
#define ECHO_PIN  18
#define BUZZER_PIN 19
#define LED_PIN 4 
LiquidCrystal_I2C lcd(0x27, 16, 2);
const float WARNING_LEVEL_CM = 5.0;
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Level Mon.");
  delay(2000);
  lcd.clear();
}
void loop() {
  float distance_cm = measureDistance();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance_cm, 1);
  lcd.print(" cm   ");
  if (distance_cm < WARNING_LEVEL_CM) {
    lcd.setCursor(0, 1);
    lcd.print("WATER LEVEL HIGH!");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Level Normal    ");
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
}
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance_cm = duration * 0.0343 / 2;
  if (distance_cm == 0 || distance_cm > 400) {
    return 400;
  }
  return distance_cm;
}
