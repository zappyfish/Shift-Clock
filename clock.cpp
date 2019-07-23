//
// Created by Liam Kelly on 7/2/19.
//

#include "clock.h"
#include <Arduino.h>

clock::clock() {}

clock::~clock() {}

bool clock::init() {
    return rtc.begin();
}

void clock::check_time() {
    // TODO: get the time and then fill the digits array with the current time digits
    // TODO: e.g. if the time is 23:54, you should do: digits[0] = 2; digits[1]  = 3; etc.
    DateTime now = rtc.now();
    digits[0] = now.hour() / 10;
    digits[1] = now.hour() % 10;
    digits[2] = now.second() / 10;
    digits[3] = now.second() % 10;
}

uint8_t clock::get_digit(uint8_t digit_index) {
    // check_time();
    return digits[digit_index];
}
