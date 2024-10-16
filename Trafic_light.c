#include <stdio.h>
#include <unistd.h>  // for sleep function

void redLight() {
    printf("Red Light ON\n");
    sleep(5); // Red light stays on for 5 seconds
}

void yellowLight() {
    printf("Yellow Light ON\n");
    sleep(2); // Yellow light stays on for 2 seconds
}

void greenLight() {
    printf("Green Light ON\n");
    sleep(5); // Green light stays on for 5 seconds
}

int main() {
    while (1) {  // Infinite loop for continuous operation
        redLight();
        yellowLight();
        greenLight();
    }
    return 0;
}
