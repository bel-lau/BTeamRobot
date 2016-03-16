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

  voltage = getVoltage(front_sensor);
  distance = 2.452*voltage*voltage - 14.3938*voltage + 23.135;

    
    Serial.print("volage: :");
    Serial.print(voltage);
    Serial.print("      Distance (in) ");
    Serial.print(distance);
    Serial.println("     ");
    /*
    delay (5000);
    */

    if(right_sensorState == LOW)
    {
      
    }
    else if(left_sensorState == LOW)
    {
      
    }
    else if(distance < 7)
    {
      servo_R.write(180);
      servo_L.write(0);
      delay(2000);
      servo_R.write(180);
      servo_L.write(180);
      delay(1300);
    }
    else
    {
      servo_R.write(90);
      servo_L.write(90);
    }
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814); 
}
