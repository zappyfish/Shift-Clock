//
// Created by Liam Kelly on 7/2/19.
//

#ifndef CLOCK_CLOCK_H
#define CLOCK_CLOCK_H

#include <stdint.h>
#include <Wire.h>
#include "RTClib.h"

class clock {

public:

    clock();
    ~clock();

    void check_time();
    bool init();
    uint8_t get_digit(uint8_t digit_index);

private:

    uint8_t digits[4];
    RTC_DS1307 rtc;

};


#endif //CLOCK_CLOCK_H
