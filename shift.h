//
// Created by Liam Kelly on 7/2/19.
//

#ifndef CLOCK_SHIFT_H
#define CLOCK_SHIFT_H

#define SHIFT_OUT_DELAY_MS 5

#include <stdint.h>
#include <Arduino.h>

class shift {

public:

    shift(int latch_pin, int clock_pin, int data_pin, bool using_common_anode);
    ~shift();

    void send_digit(uint8_t digit);

private:

    static const uint8_t COMMON_ANODE_MASK;

    int m_latch_pin;
    int m_clock_pin;
    int m_data_pin;

    void configure_pins();

    void update_shift_register();
    uint8_t get_binary_for_digit(uint8_t digit);

    // TODO: change the digits for the 7-segment
    uint8_t digits[10] = {0B11111100, 0B01100000, 0B11011010, 0B11110010, 0B01100110, 0B10110110, 0B10111110, 0B11100000,
                          0B11111110, 0B11110110};
    // Is it using a common anode mask?
    bool m_is_using_common_anode;

};


#endif //CLOCK_SHIFT_H
