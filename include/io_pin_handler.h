#pragma once

#include <Arduino.h>

static inline void IO_Set_Direction(volatile uint8_t& ddr, uint8_t mask, uint8_t state) {
    if (state) ddr |= mask;
    else ddr &= ~mask;
}

static inline void IO_Toggle(volatile uint8_t& port, uint8_t mask) {
    port ^= mask;
}

static inline void IO_Set(volatile uint8_t& port, uint8_t mask) {
    port |= mask;
}

static inline void IO_Clear(volatile uint8_t& port, uint8_t mask) {
    port &= ~mask;
}