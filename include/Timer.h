#pragma once

#include <Arduino.h>

typedef void (*timer_callback_t)(void);

static volatile timer_callback_t timer0Callback = 0;

static inline void TimerInit(timer_callback_t callback) {
  TCCR0A = (1 << WGM01);
  TCCR0B = (1 << CS01) | (1 << CS00);
  OCR0A = 249;
  TIMSK0 = (1 << OCIE0A);

  timer0Callback = callback;
}

static inline void TimerSetCallback(timer_callback_t callback) {
  timer0Callback = callback;
}

ISR(TIMER0_COMPA_vect) {
  if (timer0Callback) timer0Callback();
}