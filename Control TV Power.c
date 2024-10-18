#include <IRremote.h>  // Include the IR library

const int IR_RECEIVE_PIN = 11;  // IR receiver pin
const int TV_POWER_PIN = 2;     // GPIO to control TV power
const int TV_VOL_UP_PIN = 3;    // GPIO to control TV volume up
const int TV_VOL_DOWN_PIN = 4;  // GPIO to control TV volume down
const int TV_CHANNEL_UP_PIN = 5;// GPIO to control TV channel up
const int TV_CHANNEL_DOWN_PIN = 6;// GPIO to control TV channel down
const int TV_MUTE_PIN = 7;      // GPIO to toggle mute
const int MUTE_LED_PIN = 8;     // LED to indicate mute status

IRrecv irrecv(IR_RECEIVE_PIN);  // IR receiver object
decode_results results;         // To store decoded IR values

bool isMuted = false;           // Variable to track mute status

void setup() {
  // Set GPIOs as outputs
  pinMode(TV_POWER_PIN, OUTPUT);
  pinMode(TV_VOL_UP_PIN, OUTPUT);
  pinMode(TV_VOL_DOWN_PIN, OUTPUT);
  pinMode(TV_CHANNEL_UP_PIN, OUTPUT);
  pinMode(TV_CHANNEL_DOWN_PIN, OUTPUT);
  pinMode(TV_MUTE_PIN, OUTPUT);
  pinMode(MUTE_LED_PIN, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Start the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if an IR signal has been received
  if (irrecv.decode(&results)) {
    long irValue = results.value;  // Get the IR code
    Serial.print("Received IR value: ");
    Serial.println(irValue, HEX);  // Print received IR code in HEX format

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
      case 0xFFC23D:  // Example IR code for channel up
        nextChannel();
        break;
      case 0xFFE01F:  // Example IR code for channel down
        previousChannel();
        break;
      case 0xFFE21D:  // Example IR code for mute toggle
        toggleMute();
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

// Function to switch to the next channel
void nextChannel() {
  Serial.println("Channel Up");
  digitalWrite(TV_CHANNEL_UP_PIN, HIGH);  // Send high signal to channel up pin
  delay(500);
  digitalWrite(TV_CHANNEL_UP_PIN, LOW);   // Turn off signal
}

// Function to switch to the previous channel
void previousChannel() {
  Serial.println("Channel Down");
  digitalWrite(TV_CHANNEL_DOWN_PIN, HIGH);  // Send high signal to channel down pin
  delay(500);
  digitalWrite(TV_CHANNEL_DOWN_PIN, LOW);   // Turn off signal
}

// Function to toggle TV mute and update mute LED status
void toggleMute() {
  isMuted = !isMuted;  // Toggle mute state
  Serial.println(isMuted ? "Muted" : "Unmuted");
  digitalWrite(TV_MUTE_PIN, HIGH);  // Send high signal to mute pin
  delay(500);
  digitalWrite(TV_MUTE_PIN, LOW);   // Turn off signal

  // Update Mute LED
  digitalWrite(MUTE_LED_PIN, isMuted ? HIGH : LOW);  // Turn LED on if muted, off if unmuted
}
