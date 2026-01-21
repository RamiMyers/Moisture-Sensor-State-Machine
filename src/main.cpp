#include <Timer.h>
#include <LED.h>
#include <MoistureSensor.h>

#define CYCLE_FREQUENCY 1000 // 1 Hz
#define DRY_THRESHOLD 300

enum State { IDLE, CHECK, WATERING };

volatile uint16_t ticks = 0;

uint16_t cycleTimer = 0;
uint16_t moistureValue;
uint8_t currentLED = RED_LED_MASK;

LED ledHandler(currentLED);

State state = IDLE;

void onTimerTick() { ticks++; }

void setup() {
  Serial.begin(9600);
  TimerInit(onTimerTick);
  MoistureSensorInit();
  ledHandler.Set();
  sei();
}

void loop() {
  while (ticks) {
    cli();
    ticks--;
    sei();

    if (++cycleTimer >= CYCLE_FREQUENCY) {
      cycleTimer = 0;

      switch (state) {
        case IDLE:
          currentLED = RED_LED_MASK;
          state = CHECK;
          break;
        case CHECK:
          currentLED = GREEN_LED_MASK;
          moistureValue = MoistureSensorRead();

          if (moistureValue > DRY_THRESHOLD)
            state = WATERING;
          else
            state = IDLE;
          break;
        case WATERING:
          currentLED = BLUE_LED_MASK;
          state = IDLE;
          break;
      }

      ledHandler.Clear();
      ledHandler.SetMask(currentLED);
      ledHandler.Set();
    }
  }
}