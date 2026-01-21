#pragma once

#include <io_mapping.h>
#include <io_pin_handler.h>

class LED {
private:
    uint8_t _mask;
public:
    LED(uint8_t mask) : _mask(mask) { IO_Set_Direction(LED_DDR, _mask, OUTPUT); };

    inline void Set() { IO_Set(LED_PORT, _mask); }
    inline void Clear() { IO_Clear(LED_PORT, _mask); }
    inline void Toggle() { IO_Toggle(LED_PORT, _mask); }
    inline void Set_Mask(uint8_t mask) { _mask = mask; }
};
