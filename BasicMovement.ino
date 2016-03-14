#include <Servo.h>

Servo servo_R;
Servo servo_L;

void setup(void)
{
  servo_R.attach(10);
  servo_L.attach(9); 
}

void loop(void)
{
  servo_R.write(0);
  servo_L.write(180); 
}
