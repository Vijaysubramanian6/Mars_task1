// C++ code
//
#include <Servo.h>;

int ldrvalueL;
int ldrvalueR;

int ambient_light_pin = 5;
int ambient_light_value;

int servopin = A4;
int ldrpinR = A0;
int ldrpinL = A2;

int servo_pos;

Servo myservo;

void setup()
{
    myservo.attach(servopin);
    pinMode(servopin, OUTPUT);
    pinMode(ldrpinL, INPUT);
    pinMode(ldrpinR, INPUT);

    pinMode(ambient_light_pin, INPUT);

    Serial.begin(9600);

    myservo.write(90);
}

void loop()
{
    ldrvalueL = analogRead(A2);
    ldrvalueR = analogRead(A0);

    // Serial.print("LDR: ");
    //  Serial.println(ldrvalue);
    delay(1000);

    ambient_light_value = analogRead(ambient_light_pin);
    Serial.println(ambient_light_value);

    // Rigth side more light--> turn left
    if (ldrvalueL > ldrvalueR)
    {
        if ((ldrvalueL - ldrvalueR >= 100) && (ldrvalueL - ldrvalueR <= 300))
        {
            // myservo.write(-servo_pos);
            myservo.write(120);
            // servo_pos = -30;

            delay(1000);
        }

        else if ((ldrvalueL - ldrvalueR >= 300) && (ldrvalueL - ldrvalueR <= 600))
        {
            myservo.write(-servo_pos);
            myservo.write(165);
            servo_pos = -75;
            delay(1000);
        }
        else if ((ldrvalueL - ldrvalueR >= 600))
        {
            // myservo.write(-servo_pos);
            myservo.write(180);
            // servo_pos = -90;
            delay(1000);
        }
        else
        {
            myservo.write(90);
            delay(1000);
        }
    }

    // Rigth side more light--> turn left
    else if (ldrvalueL < ldrvalueR)
    {
        if ((ldrvalueR - ldrvalueL >= 100) && (ldrvalueR - ldrvalueL <= 300))
        {
            // myservo.write(-servo_pos);
            myservo.write(60);
            // servo_pos = 30;
            // myservo.write(servo_pos);

            delay(1000);
        }

        else if ((ldrvalueR - ldrvalueL >= 300) && (ldrvalueR - ldrvalueL <= 600))
        {
            // myservo.write(-servo_pos);
            myservo.write(15);
            // servo_pos = 75;

            delay(1000);
        }
        else if (ldrvalueR - ldrvalueL >= 600)
        {
            // myservo.write(-servo_pos);
            myservo.write(0);
            // servo_pos = 90;

            delay(1000);
        }
        else
        {
            myservo.write(90);
            delay(1000);
        }
    }

    else
    {
        myservo.write(90);
        delay(1000);
    }

    // Serial.print("LDR Right : ");
    // Serial.println(ldrvalueR);

    // Serial.print("LDR Left : ");
    //  Serial.println(ldrvalueL);
}