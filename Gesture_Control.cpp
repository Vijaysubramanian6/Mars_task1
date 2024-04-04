// C++ code
//
int speedpin = 5;
int dir1 = 4;
int dir2 = 3;
int motor_speed = 255;

int tiltpin = 8;
int tilt_value;
int flex_value;

int flexpin = A0;

void setup()
{
    pinMode(speedpin, OUTPUT);
    pinMode(dir1, OUTPUT);
    pinMode(dir2, OUTPUT);

    pinMode(tiltpin, INPUT);
    pinMode(flexpin, INPUT);

    Serial.begin(9600);
}

void loop()
{

    tilt_value = digitalRead(tiltpin);
    flex_value = analogRead(flexpin);
    delay(1000);

    // int rf = 1000/((5/flex_value)-1);

    Serial.println(flex_value);
    // Serial.println(rf);

    if (tilt_value == 1)
    { // not tilted

        if (flex_value > 14 && flex_value < 33)
        {
            digitalWrite(dir1, LOW);
            digitalWrite(dir2, HIGH);

            analogWrite(speedpin, 180);
        }
        else if (flex_value < 14)
        {
            analogWrite(speedpin, 255);
        }
        else
        {
            analogWrite(speedpin, 0);
        }
    }

    else
    {

        if (flex_value > 14 && flex_value < 33)
        {
            digitalWrite(dir1, HIGH);
            digitalWrite(dir2, LOW);

            analogWrite(speedpin, 180);
        }

        else if (flex_value < 14)
        {
            analogWrite(speedpin, 255);
        }

        else
        {
            analogWrite(speedpin, 0);
        }
    }
}
