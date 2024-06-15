
#include "output.hpp"

void setup_output()
{
    pinMode(PIN_LED, OUTPUT);
}

void set_intensity(const int value)
{
    analogWrite(PIN_LED, constrain(value, 0, 255));
}
