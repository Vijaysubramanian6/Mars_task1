// C++ code
//

int ultrsonic_pin = 6;
int ultrasonic;

int height_container = 100; // cm

// force sensor
int FSRpin = A0;
int value;
int force;

void setup()
{
    Serial.begin(9600);
    pinMode(FSRpin, INPUT);
}

void loop()
{
    pinMode(ultrsonic_pin, OUTPUT);
    digitalWrite(ultrsonic_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrsonic_pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(ultrsonic_pin, LOW);

    pinMode(ultrsonic_pin, INPUT);

    long duration = pulseIn(ultrsonic_pin, HIGH);

    long cm = duration / 29 / 2;

    int height_liquid = height_container - cm;

    // Obtain analog reading from pin A0 (FSR)
    value = analogRead(FSRpin);

    Serial.print("Analog reading from FSR = ");
    Serial.println(value);

    // Map analog value to obtain Vo in mV
    force = map(value, 0, 914, 0, 10);
    Serial.print("Force = ");
    Serial.println(force);

    // area to be unit 2 cm2

    float density = 1.0 * force * 1000 / (2 * height_liquid * 980);

    Serial.print("Ultrasonic Sensor");
    Serial.println(cm);

    Serial.print("Density(milli)");
    Serial.println(density);
    delay(500);
}
