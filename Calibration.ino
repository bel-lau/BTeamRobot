#include <Servo.h>

Servo servo_R;
Servo servo_L;
const int front_sensor = 0;
float distance, voltage;
const int left_sensor = 12;
const int right_sensor = 11;
int left_sensorState = 0;
int right_sensorState = 0;

void setup(void)
{
    servo_R.attach(10);
    servo_L.attach(9); 
    Serial.begin(9600);
    pinMode (left_sensor, INPUT);
    pinMode (right_sensor, INPUT);
}

void loop(void)
{
    left_sensorState = digitalRead(left_sensor);
    right_sensorState = digitalRead(right_sensor);

//Wheel Calibration
    /*
     * At 90 and 90, neither wheel should be moving. 
     * If one is, adjust its callibration screw until it is not.
     */ 
    servo_R.write(90); //0 for forward
    servo_L.write(90); //180 for forward


//Side Sensor Calibration
    /*
     * Test sensors on white and dark surfaces. 
     * Nothing should print in serial while on white surfaces. 
     * Both should print to serial while on dark surfaces.
     * If one of these is not the case, adjust the appropriate sensor's callibration wheel until the above are true.
     */
    //LOW = black/low light
    //HIGH = white/high light
    if(right_sensorState == LOW)
    {
        Serial.print("Right - LOW");
        Serial.println("     ");
    }
    if (left_sensorState == LOW)
    {
        Serial.print("Left - LOW");
        Serial.println("     ");
    }


//Front Sensor
    /*
     * To test the front sensor, un-comment the section below.
     */
   
    /*
    voltage = getVoltage(front_sensor);
    distance = 2.452*voltage*voltage - 14.3938*voltage + 23.135;
  
    Serial.print("volage: :");
    Serial.print(voltage);
    Serial.print("      Distance (in) ");
    Serial.print(distance);
    Serial.println("     ");

    delay (5000);
    */
}

float getVoltage(int pin)
{
    return (analogRead(pin) * 0.004882814); 
}
