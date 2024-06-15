
#include "output.hpp"
#include "input.hpp"

const float MAX_DISTANCE = 20.0f;
float distance = -1.0f;

void setup()
{
    // Serial.begin(9600);
    setup_output();
    setup_input();
}

// unsigned int i = 0;

void loop()
{
    input_loop();
    distance = get_distance();
    // if (i >= 1000) {
    //     Serial.print(distance);
    //     Serial.print('\n');
    //     i = 0;
    // } else i++;
    if (has_near_object() && distance >= 0.0f && distance <= MAX_DISTANCE)
        set_intensity(255 - (distance / MAX_DISTANCE * 255));
    else
        set_intensity(0);
}
