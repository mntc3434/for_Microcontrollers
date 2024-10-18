#include <IRremote.h>  // Library for handling IR signals

const int IR_RECEIVE_PIN = 11;  // IR receiver pin on ESP32/Arduino
const int TV_POWER_PIN = 2;     // GPIO to control TV power
const int TV_VOL_UP_PIN = 3;    // GPIO to control TV volume up
const int TV_VOL_DOWN_PIN = 4;  // GPIO to control TV volume down

IRrecv irrecv(IR_RECEIVE_PIN);  // IR receiver object
decode_results results;         // To store decoded IR values

void setup() {
  // Set GPIOs as outputs
  pinMode(TV_POWER_PIN, OUTPUT);
  pinMode(TV_VOL_UP_PIN, OUTPUT);
  pinMode(TV_VOL_DOWN_PIN, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Start the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if an IR signal has been received
  if (irrecv.decode(&results)) {
    long irValue = results.value;  // Get the IR code

    // Process the IR value for corresponding TV control
    switch (irValue) {
      case 0xFFA25D:  // Example IR code for power toggle
        togglePower();
        break;
      case 0xFF629D:  // Example IR code for volume up
        increaseVolume();
        break;
      case 0xFFA857:  // Example IR code for volume down
        decreaseVolume();
        break;
      default:
        Serial.println("Unknown command");
        break;
    }

    // Resume receiving next signal
    irrecv.resume();
  }
}

// Function to toggle TV power
void togglePower() {
  Serial.println("Toggling Power");
  digitalWrite(TV_POWER_PIN, HIGH);  // Send high signal to power pin
  delay(500);                        // Keep it on for 500ms
  digitalWrite(TV_POWER_PIN, LOW);   // Turn off signal
}

// Function to increase TV volume
void increaseVolume() {
  Serial.println("Volume Up");
  digitalWrite(TV_VOL_UP_PIN, HIGH);  // Send high signal to volume up pin
  delay(500);
  digitalWrite(TV_VOL_UP_PIN, LOW);   // Turn off signal
}

// Function to decrease TV volume
void decreaseVolume() {
  Serial.println("Volume Down");
  digitalWrite(TV_VOL_DOWN_PIN, HIGH);  // Send high signal to volume down pin
  delay(500);
  digitalWrite(TV_VOL_DOWN_PIN, LOW);   // Turn off signal
}
