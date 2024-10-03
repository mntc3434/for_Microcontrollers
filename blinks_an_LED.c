#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB0

int main(void) {
    // Set LED_PIN as an output
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Turn the LED on
        PORTB |= (1 << LED_PIN);
        _delay_ms(1000); // Wait for 1 second

        // Turn the LED off
        PORTB &= ~(1 << LED_PIN);
        _delay_ms(1000); // Wait for 1 second
    }

    return 0;
}
