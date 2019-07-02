//
// Created by Liam Kelly on 7/2/19.
//

#include "shift.h"

const uint8_t shift::COMMON_ANODE_MASK = 0b11111111;

shift::shift(int latch_pin, int clock_pin, int data_pin, bool using_common_anode) : m_latch_pin(latch_pin),
m_clock_pin(clock_pin), m_data_pin(data_pin), m_is_using_common_anode(using_common_anode) {
    configure_pins();
}

shift::~shift() {}

void shift::configure_pins() {
    pinMode(m_latch_pin, OUTPUT);
    pinMode(m_data_pin, OUTPUT);
    pinMode(m_clock_pin, OUTPUT);
    digitalWrite(m_latch_pin, LOW);
}

uint8_t shift::get_binary_for_digit(uint8_t digit) {
    return digits[digit];
}

void shift::send_digit(uint8_t digit) {
    uint8_t bin = get_binary_for_digit(digit);
    if (m_is_using_common_anode) {
        bin ^= COMMON_ANODE_MASK;
    }
    // Shift out the digit through binary signal
    shiftOut(m_data_pin, m_clock_pin, LSBFIRST, bin);
    // For this shift register, move from shift register to latch register (output)
    digitalWrite(m_latch_pin, HIGH);
    delay(SHIFT_OUT_DELAY_MS);
    digitalWrite(m_latch_pin, LOW);
}