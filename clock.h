//
// Created by Liam Kelly on 7/2/19.
//

#ifndef CLOCK_CLOCK_H
#define CLOCK_CLOCK_H

#include <stdint.h>

class clock {

public:

    clock();
    ~clock();

    uint8_t get_digit(uint8_t digit_index);

private:

    uint8_t digits[4];

    void check_time();

};


#endif //CLOCK_CLOCK_H
