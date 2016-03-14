#include <Servo.h>

Servo servo_R;
Servo servo_L;
const int front_sensor = 0;
float distance, voltage;

void setup(void)
{
  servo_R.attach(10);
  servo_L.attach(9); 
  Serial.begin(9600);
}

void loop(void)
{
  servo_R.write(0); //0 for forward
  servo_L.write(180); //180 for forward
  
  
  voltage = getVoltage(front_sensor);
  distance = 2.452*voltage*voltage - 14.3938*voltage + 23.135;
  
  Serial.print("volage: :");
  Serial.print(voltage);
  Serial.print("      Distance (in) ");
  Serial.print(distance);
  Serial.println("     ");
  
  delay(5000);
  
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814); 
}
