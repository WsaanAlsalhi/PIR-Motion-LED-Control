// Define pins
const int pirPin = 2; // PIR sensor input pin
const int ledPin = 13; // LED output pin

// Store previous sensor state
int previousState = LOW;

void setup() {
  pinMode(pirPin, INPUT); // Set PIR as input
  pinMode(ledPin, OUTPUT); // Set LED as output
  digitalWrite(ledPin, LOW); // Ensure LED is off initially
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int motionDetected = digitalRead(pirPin); // Read PIR sensor

  if (motionDetected == HIGH && previousState == LOW) {
    Serial.println("Motion detected: LED ON");
    digitalWrite(ledPin, HIGH); // Turn on LED
    delay(5000); // Keep LED on for 5 seconds
    digitalWrite(ledPin, LOW); // Turn off LED
    previousState = HIGH;
  } else if (motionDetected == LOW && previousState == HIGH) {
    Serial.println("No motion: LED OFF");
    previousState = LOW;
  }

  delay(100); // Short delay
}

