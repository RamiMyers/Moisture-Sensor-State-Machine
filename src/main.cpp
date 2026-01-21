#include <Timer.h>
#include <LED.h>
#include <MoistureSensor.h>

#define BLINK_FREQUENCY 1000
#define NUM_LEDs 3

volatile uint16_t ticks = 0;

uint8_t ledToggle = 0;
uint16_t ledTimer = 0;
uint8_t leds[] = { RED_LED_MASK, GREEN_LED_MASK, BLUE_LED_MASK };

LED ledHandler(RED_LED_MASK);

ISR(TIMER0_COMPA_vect) {
  ticks++;
}

void setup() {
  Serial.begin(9600);
  TimerInit();
  MoistureSensorInit();
}

void loop() {
  while (ticks) {
    cli();
    ticks--;
    sei();

    if (++ledTimer >= BLINK_FREQUENCY) {
      ledTimer = 0;

      ledHandler.Clear();
      ledHandler.Set_Mask(leds[ledToggle]);
      ledHandler.Set();
      
      ledToggle = (ledToggle + 1) % NUM_LEDs;

      Serial.println(MoistureSensorRead());
    }
  }
}