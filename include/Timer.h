#pragma once

#include <Arduino.h>

typedef void (*timer_callback_t)(void);

// TODO: Set interrupt callback

class Timer {
  Timer() {
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    OCR0A = 249;
    TIMSK0 = (1 << OCIE0A);
    sei();
  }
};

static inline void TimerInit() {
  TCCR0A = (1 << WGM01);
  TCCR0B = (1 << CS01) | (1 << CS00);
  OCR0A = 249;
  TIMSK0 = (1 << OCIE0A);
  sei();
}

static inline void TimerSetCallback() {

}