#include <avr/io.h>
#include <util/delay.h>

// Motor A (Left Motor) connected to PB0 and PB1
#define MOTOR_A_FORWARD PB0
#define MOTOR_A_BACKWARD PB1

// Motor B (Right Motor) connected to PB2 and PB3
#define MOTOR_B_FORWARD PB2
#define MOTOR_B_BACKWARD PB3

void move_forward() {
    // Set both motors to move forward
    PORTB |= (1 << MOTOR_A_FORWARD);
    PORTB &= ~(1 << MOTOR_A_BACKWARD);
    PORTB |= (1 << MOTOR_B_FORWARD);
    PORTB &= ~(1 << MOTOR_B_BACKWARD);
}

void move_backward() {
    // Set both motors to move backward
    PORTB &= ~(1 << MOTOR_A_FORWARD);
    PORTB |= (1 << MOTOR_A_BACKWARD);
    PORTB &= ~(1 << MOTOR_B_FORWARD);
    PORTB |= (1 << MOTOR_B_BACKWARD);
}

void turn_left() {
    // Left motor backward, right motor forward
    PORTB &= ~(1 << MOTOR_A_FORWARD);
    PORTB |= (1 << MOTOR_A_BACKWARD);
    PORTB |= (1 << MOTOR_B_FORWARD);
    PORTB &= ~(1 << MOTOR_B_BACKWARD);
}

void turn_right() {
    // Left motor forward, right motor backward
    PORTB |= (1 << MOTOR_A_FORWARD);
    PORTB &= ~(1 << MOTOR_A_BACKWARD);
    PORTB &= ~(1 << MOTOR_B_FORWARD);
    PORTB |= (1 << MOTOR_B_BACKWARD);
}

void stop_robot() {
    // Stop both motors
    PORTB &= ~(1 << MOTOR_A_FORWARD);
    PORTB &= ~(1 << MOTOR_A_BACKWARD);
    PORTB &= ~(1 << MOTOR_B_FORWARD);
    PORTB &= ~(1 << MOTOR_B_BACKWARD);
}

int main(void) {
    // Set motor control pins as outputs
    DDRB |= (1 << MOTOR_A_FORWARD) | (1 << MOTOR_A_BACKWARD) | (1 << MOTOR_B_FORWARD) | (1 << MOTOR_B_BACKWARD);

    while (1) {
        move_forward();
        _delay_ms(2000);  // Move forward for 2 seconds

        turn_left();
        _delay_ms(1000);  // Turn left for 1 second

        move_backward();
        _delay_ms(2000);  // Move backward for 2 seconds

        turn_right();
        _delay_ms(1000);  // Turn right for 1 second

        stop_robot();
        _delay_ms(2000);  // Stop for 2 seconds
    }

    return 0;
}
