
#pragma once

typedef enum INPUT_STATE {
    IDLE,
    TRIGGERING,
    WAITING_ECHO_REQ,
    WAITING_ECHO_RES
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
/**
 * @brief Check whether there is a near object or not (near means in about 25 cm from the sensor).
 *
 * @return true when there is an object near the sensor.
 * @return false otherwise.
 */
bool has_near_object();