//
// Created by Liam Kelly on 7/2/19.
//

#include "clock.h"
#include <Arduino.h>

clock::clock() {}

clock::~clock() {}

void clock::check_time() {
    // TODO: get the time and then fill the digits array with the current time digits
    // TODO: e.g. if the time is 23:54, you should do: digits[0] = 2; digits[1]  = 3; etc.
    if (digits[0] > 9)  {
      digits[0] = 0;
    } else  {
      digits[0]++;
    }
    delay(500);
}

uint8_t clock::get_digit(uint8_t digit_index) {
    // check_time();
    return digits[digit_index];
}
