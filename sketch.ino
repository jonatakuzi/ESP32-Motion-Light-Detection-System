// ESP32 PIR + Light Sensor (LDR) Example
// PIR OUT → GPIO 33
// LDR analog out → GPIO 27
// LED → GPIO 2

int pirPin = 33;        // PIR sensor output pin
int ledPin = 2;         // Onboard LED
int ldrPin = 27;        // LDR analog pin (A0 from module)

// Tune this value
int lightThreshold = 2000;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  Serial.begin(115200);
  delay(60000);  // allow PIR to stabilize

  Serial.println("PIR + LDR Motion Light Test Starting...");
}

void loop() {
  int motion = digitalRead(pirPin);
  int lightValue = analogRead(ldrPin); // Range: 0–4095

  // Determine current light level description
  String lightLevel;

  if (lightValue < 1000) {
    lightLevel = "Bright";
  } 
  else if (lightValue < 2500) {
    lightLevel = "Medium Light";
  } 
  else {
    lightLevel = "Dark";
  }

  // Print info
  Serial.print("Light value: ");
  Serial.print(lightValue);
  Serial.print(" (");
  Serial.print(lightLevel);
  Serial.print(") | Motion: ");
  Serial.println(motion == HIGH ? "YES" : "NO");

  // Motion + darkness condition
  if (motion == HIGH && lightValue > lightThreshold) {
    Serial.println("⚠️ Motion detected in low light → LED ON");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}