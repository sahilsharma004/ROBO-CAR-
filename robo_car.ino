#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk authentication token
char auth[] = "YOUR_AUTHENTICATION_CODE";

// WiFi credentials
char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASSWORD";

// Define motor driver pins
#define IN1 26  // Right Motor Forward
#define IN2 27  // Right Motor Backward
#define IN3 32  // Left Motor Forward
#define IN4 33  // Left Motor Backward

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// Forward (V0) - All motors move forward
BLYNK_WRITE(V0) {
  int state = param.asInt();
  if (state == 1) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    stopMotors();
  }
}

// Backward (V1) - All motors move backward
BLYNK_WRITE(V1) {
  int state = param.asInt();
  if (state == 1) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    stopMotors();
  }
}

// Right (V2) - Right motors move backward, Left motors move forward
BLYNK_WRITE(V2) {
  int state = param.asInt();
  if (state == 1) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    stopMotors();
  }
}

// Left (V3) - Left motors move backward, Right motors move forward
BLYNK_WRITE(V3) {
  int state = param.asInt();
  if (state == 1) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    stopMotors();
  }
}

// Function to stop all motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  Blynk.run();
}

