
#pragma once

typedef enum INPUT_STATE {
    IDLE,
    TRIGGERING,
    WAITING_ECHO
} INPUT_STATE;

const int PIN_TRIG = 8;
const int PIN_ECHO = 7;

void setup_input();
void input_loop();

/**
 * @brief Get the distance in centimeters of the object from the sensor.
 *
 * @return float - The distance in centemeters.
 */
float get_distance();
