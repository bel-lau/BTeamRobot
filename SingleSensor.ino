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

    servo_R.write(0);
    servo_L.write(90);
    delay(10);
   while(distance<4)
   {
    servo_R.write(0);
    servo_L.write(180);
    delay(10);
    voltage = getVoltage(front_sensor);
    distance = 2.452*voltage*voltage - 14.3938*voltage + 23.135;
   }
   while(right_sensorState == HIGH)
    {
      servo_R.write(90);
      servo_L.write(180);
      delay(10);
      left_sensorState = digitalRead(left_sensor);
      right_sensorState = digitalRead(right_sensor);
      if(right_sensorState == LOW)
      {
          break;
      }
      if(distance<4)
      {
          break;
      }
    }

}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814); 
}

