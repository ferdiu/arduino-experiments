
#include "output.hpp"
#include "input.hpp"

const float MAX_DISTANCE = 20.0f;
float distance = -1.0f;

void setup()
{
    setup_output();
    setup_input();
}

void loop()
{
    input_loop();
    distance = get_distance();
    if (distance >= 0.0f && distance <= MAX_DISTANCE)
        set_intensity(distance / MAX_DISTANCE * 255);
    else
        set_intensity(0);
}
