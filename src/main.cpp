#include <timer.h>
#include <LED.h>

#define BLINK_FREQUENCY 1000

// TODO: Dependency injection for LEDs
// TODO: ADC for moisture sensor

volatile uint16_t ticks = 0;

uint16_t ledTimer = 0;

ISR(TIMER0_COMPA_vect) {
  ticks++;
}

void setup() {
  Serial.begin(9600);
  timerInit();
  LED_Init();
}

void loop() {
  while (ticks) {
    cli();
    ticks--;
    sei();

    if (++ledTimer >= BLINK_FREQUENCY) {
      ledTimer = 0;
      LED_Toggle();
    }
  }
}