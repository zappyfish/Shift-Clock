#include "shift.h"
#include "clock.h"

int latch_pin = 7;
int clock_pin = 8;
int data_pin = 4;

shift myShift(latch_pin, clock_pin, data_pin, true);

void setup() {

}

void loop() {
    for (int i = 0; i < 10; i++) {
        myShift.send_digit(i);
        Serial.print("Sending ");
        Serial.println(i);
        delay(500);
    }
}
