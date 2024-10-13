#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB0      // LED connected to pin PB0
#define BUTTON_PIN PB1   // Button connected to pin PB1

int main(void) {
    // Set LED pin as output
    DDRB |= (1 << LED_PIN);

    // Set BUTTON pin as input with pull-up resistor enabled
    DDRB &= ~(1 << BUTTON_PIN);    // Input mode
    PORTB |= (1 << BUTTON_PIN);    // Enable pull-up resistor

    uint8_t button_state = 0;      // Holds the button state (pressed or not)

    while (1) {
        // Check if button is pressed (active low: pressed = 0)
        if (!(PINB & (1 << BUTTON_PIN))) {
            _delay_ms(50); // Debounce delay

            // Check again after debounce delay to avoid false triggers
            if (!(PINB & (1 << BUTTON_PIN))) {
                button_state ^= 1;    // Toggle button state
                _delay_ms(500);       // Prevent multiple toggles from a single press
            }
        }

        // Set LED based on button state
        if (button_state) {
            PORTB |= (1 << LED_PIN);  // Turn on LED
        } else {
            PORTB &= ~(1 << LED_PIN); // Turn off LED
        }
    }

    return 0;
}
