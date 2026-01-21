#pragma once

#include <Arduino.h>

static inline void MoistureSensorInit() {
  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
}

static inline uint16_t MoistureSensorRead() {
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC));
  return ADC;
}