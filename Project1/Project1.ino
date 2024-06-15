
const int interval = 500;
const int MY_PIN = 12; // original: LED_BUILTIN

void setup()
{
    // Set the mode for the D13 pin to OUTPUT
    pinMode(MY_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(MY_PIN, HIGH);
    delay(interval);

    digitalWrite(MY_PIN, LOW);
    delay(interval);
}
