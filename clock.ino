#include "shift.h"
#include "clock.h"
#include <Servo.h>

#define NUM_DIGITS 4

int latch_pins[4] = {7, 3, 2, 5}; // Example latch pins, different one for each shift
// register. 
int clock_pin = 8;
int data_pin = 4;

shift myShifts[4] = {
  shift(latch_pins[0], clock_pin, data_pin, true),
  shift(latch_pins[1], clock_pin, data_pin, true),
  shift(latch_pins[2], clock_pin, data_pin, true),
  shift(latch_pins[3], clock_pin, data_pin, true)
};

clock myClock;

Servo on, off;

void setup() {
    myClock.init();
    on.attach(5);
    on.write(0);
    off.attach(3);
    off.write(90);
}

void loop() {
    myClock.check_time();
    for (int i = 0; i < NUM_DIGITS; i++) {
      uint8_t digit = myClock.get_digit(i);
      myShifts[i].send_digit(digit);
    }
}
