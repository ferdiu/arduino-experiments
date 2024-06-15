
const int interval = 50;
const int MY_PIN = 11; // this pin is marked as ~ and can simulate an analog output
const int step = 5;
int direction = 1;
int _i = 0;

void setup()
{
    pinMode(MY_PIN, OUTPUT);
}

void loop()
{
    // write value to pin
    analogWrite(MY_PIN, constrain(_i, 0, 255));
    delay(interval);

    // update value passed to pin
    _i += direction * step;

    // invert direction of the for loop
    if (_i >= 255 || _i <= 0)
        direction *= -1;
}
