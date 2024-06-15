
#include "output.hpp"
#include "input.hpp"
#include "cb.hpp"

const float MAX_DISTANCE = 20.0f;
float distance = -1.0f;

CircularBuffer cb;

void setup()
{
    // Serial.begin(9600);
    setup_output();
    setup_input();

    initBuffer(&cb);
}

// unsigned int i = 0;

void loop()
{
    input_loop();
    distance = get_distance();
    push(&cb, distance);
    // if (i >= 1000) {
    //     Serial.print(distance);
    //     Serial.print('\n');
    //     i = 0;
    // } else i++;
    const float avg = averageBuffer(&cb);
    if (has_near_object() && avg >= 0.0f && avg <= MAX_DISTANCE)
        set_intensity(255 - (avg / MAX_DISTANCE * 255));
    else
        set_intensity(0);
}
