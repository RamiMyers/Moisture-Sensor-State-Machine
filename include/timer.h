#pragma once

#include <Arduino.h>

static inline void timerInit() {
  TCCR0A = (1 << WGM01);
  TCCR0B = (1 << CS01) | (1 << CS00);
  OCR0A = 249;
  TIMSK0 = (1 << OCIE0A);
  sei();
}