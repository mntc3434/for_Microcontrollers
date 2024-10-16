#define RED_LED_PIN 0     // Red LED connected to pin 0
#define YELLOW_LED_PIN 1  // Yellow LED connected to pin 1
#define GREEN_LED_PIN 2   // Green LED connected to pin 2

void delay(int time) {
    volatile int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1000; j++);  // Simple delay loop
}

void setup() {
    // Set the pins as output
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
    // Turn on Red light, turn off others
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(5000);  // Delay for 5 seconds
    
    // Turn on Yellow light, turn off others
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(2000);  // Delay for 2 seconds
    
    // Turn on Green light, turn off others
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(5000);  // Delay for 5 seconds
}

int main() {
    setup(); // Initialize the microcontroller

    while (1) {
        loop(); // Continuously run the traffic light system
    }

    return 0;
}
