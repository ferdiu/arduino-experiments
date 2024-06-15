
#include <time.h>

#include "input.hpp"

INPUT_STATE state = IDLE;

unsigned long _last_state_change_micros = 0;
unsigned long _delta_echo_micros = 0;
bool _has_object = false;

// if no echo is recieved after 1500 microseconds then the
// object was 25.7325 centimeters distant or more
const unsigned long TOO_LONG = 1500;

void setup_input()
{
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);
}

float get_distance()
{
    // 0.03431 cm / 1 us
    return 0.03431 * _get_time();
}

bool has_near_object()
{
    return _has_object;
}

// return time in microseconds
int _get_time()
{
    return _delta_echo_micros * 0.5f;
}

void _set_state(INPUT_STATE new_state)
{
    _last_state_change_micros = micros();
    state = new_state;
}

void input_loop()
{
    switch (state)
    {
        case IDLE: return _idle_loop();
        case TRIGGERING: return _triggering_loop();
        case WAITING_ECHO_REQ: return _waiting_echo_req_loop();
        case WAITING_ECHO_RES: return _waiting_echo_res_loop();
    }
}

void _idle_loop()
{
    digitalWrite(PIN_TRIG, HIGH);
    _set_state(TRIGGERING);
}

void _triggering_loop()
{
    clock_t now = micros();
    if (now - _last_state_change_micros >= 10)
    {
        digitalWrite(PIN_TRIG, LOW);
        _set_state(WAITING_ECHO_REQ);
    }
}

void _waiting_echo_req_loop()
{
    clock_t diff = micros() - _last_state_change_micros;
    if (digitalRead(PIN_ECHO) == HIGH)
    {
        _set_state(WAITING_ECHO_RES);
    } else if (diff > TOO_LONG) {
        _delta_echo_micros = 0;
        _set_state(IDLE);
    }
}

void _waiting_echo_res_loop()
{
    clock_t diff = micros() - _last_state_change_micros;
    if (digitalRead(PIN_ECHO) == LOW)
    {
        _delta_echo_micros = diff;
        _has_object = true;
        _set_state(IDLE);
    } else if (diff > TOO_LONG) {
        _delta_echo_micros = 0;
        _has_object = false;
        _set_state(IDLE);
    }
}
