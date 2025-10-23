
#include "songs.h"
#include "sensors.h"
#define BATTERY_LOW_V   11.5     
#define VOLTAGE_PRINT_PERIOD  60000UL
#define LOWBEEP_PERIOD  1000UL

void batteryMonitorTick() {
  static unsigned long lastPrintMs = 0;
  static unsigned long lastBeepMs  = 0;

  const unsigned long now = millis();
  const float voltage = getBatteryVoltage();  

  if (now - lastPrintMs >= VOLTAGE_PRINT_PERIOD) {
    Serial.print("Battery: ");
    Serial.print(voltage, 2);
    Serial.println(" V");
    lastPrintMs = now;
  }

  if (voltage <= BATTERY_LOW_V) {
    if (now - lastBeepMs >= LOWBEEP_PERIOD) {
      tone(BDPIN_BUZZER, 1000, 150); 
      lastBeepMs = now;
    }
  } else {
    noTone(BDPIN_BUZZER);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Launching IMU");
  IMU.begin();
  Serial.println("Playing start melody");
  playSequence(HappyBirthday,noteDurations_HappyBirthday);
  pinMode( led_pin, OUTPUT );
  Serial.print("Battery: ");
  Serial.print(getBatteryVoltage(), 2);
  Serial.println(" V");
}

void loop() {
  static unsigned long lastMyVoltPrint = 0;
  unsigned long now = millis();

  float roll  = getRoll();
  float yaw   = getYaw();
  float pitch = getPitch();

  if (now - lastMyVoltPrint >= 60000UL) {   
    float voltage = getBatteryVoltage();    
    Serial.print("V="); Serial.print(voltage, 2);
    Serial.print("V  |  Roll:");  Serial.print(roll, 2);
    Serial.print("  Pitch:");     Serial.print(pitch, 2);
    Serial.print("  Yaw:");       Serial.println(yaw, 2);
    lastMyVoltPrint = now;
  }

  batteryMonitorTick();
  delay(10);
}
