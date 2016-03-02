#include <mxapi.h>
#include <servo.h>
#include <ms_delay.h>
#include <lcd.h>
#include <adc.h>

int main(void)  
{
    servo_init();       //Initialize servo motor control
    
    while(1==1)  
    {
        if(pin_value(PORT_B0)==HIGH)
        {
            servo_robot(REVERSE, 50);
            delay_ms(1000);
            servo_robot(SPIN_RIGHT, 100);
            delay_ms(500);
        }
        else if(pin_value(PORT_D7)==HIGH) 
        { 
            servo_robot(REVERSE, 50);
            delay_ms(1000);
            servo_robot(SPIN_LEFT, 100);
            delay_ms(500);
        }
        else if(adc_read(ADC5)>300) 
        {  
            servo_robot(REVERSE, 100);
            delay_ms(1000);
            servo_robot(SPIN_RIGHT, 50);
            delay_ms(100);
        }
        else 
        { 
            servo_robot(FORWARD, 100);
        }  
        delay_ms(10);
    } 
} 
