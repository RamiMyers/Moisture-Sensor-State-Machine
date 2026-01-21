#pragma once

#include <io_mapping.h>
#include <io_pin_handler.h>

static inline void LED_Init() {
    IO_Set_Direction(LED_DDR, RED_LED_MASK, OUTPUT);
}

static inline void LED_Toggle() {
    IO_Toggle(LED_PORT, RED_LED_MASK);
}

static inline void LED_Set() {
    IO_Set(LED_PORT, RED_LED_MASK);
}

static inline void LED_Clear() {
    IO_Clear(LED_PORT, RED_LED_MASK);
}