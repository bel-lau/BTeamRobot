#include <mxapi.h>
#include <lcd.h>
#include <adc.h>
#include <servo.h>
int main(void)
{
    int x=0;
    lcd_init();	//Initialize LCD
    adc_init();	//Initialize analog sensor input
    servo_init();  //Initialize servo motor control

    servo_robot(FORWARD,100);
    delay_ms(1500);
    servo_robot(SPIN_LEFT,100);
    delay_ms(1200);              	
    servo_robot(STOP,0);
    delay_ms(350);            	//robot moves forward toward boundary, spins left to face center, then stops
	
    if(pin_value(PORT_B0)==HIGH)
    {
	    servo_robot(REVERSE,100);
	    delay_ms(500);
	    servo_robot(SPIN_RIGHT,100);
	    delay_ms(1000);
    }
    else if(pin_value(PORT_D7)==HIGH)
    {
	    servo_robot(REVERSE,100);
	    delay_ms(500);
	    servo_robot(SPIN_LEFT,100);
	    delay_ms(1000);
    }
    else if(pin_value(PORT_D6)==HIGH)
    {
	    servo_robot(FORWARD,100);
	    delay_ms(250);
    }
    else if(adc_read(5)>500)
    {
	    servo_robot(FORWARD,100);
	    delay_ms(1000);
	    servo_robot(SPIN_RIGHT,30);
	    delay_ms(100);
    }
 
    int count = 0;
    while(count<3)
    {
	    while(1==1)
	    {
  	        x=adc_read(5);
  	        lcd_decimal(FIRST_LINE, x, 4);
  	        lcd_instruction(GOTO_LINE1);
  	        delay_ms(10);
	
  	        if(pin_value(PORT_B0)==HIGH)
  	        {
    	        servo_robot(REVERSE,100);
    	        delay_ms(500);
    	        servo_robot(SPIN_RIGHT,100);
    	        delay_ms(1000);
  	        }
  	        else if(pin_value(PORT_D7)==HIGH)
  	        {
    	        servo_robot(REVERSE,100);
    	        delay_ms(500);
    	        servo_robot(SPIN_LEFT,100);
    	        delay_ms(1000);
  	        }
  	        else if(pin_value(PORT_D6)==HIGH)
  	        {
    	        servo_robot(FORWARD,100);
    	        delay_ms(250);
  	        }
  	        else if(adc_read(5)>500)
  	        {
    	        servo_robot(FORWARD,100);
    	        delay_ms(1000);
    	        servo_robot(SPIN_RIGHT,30);
    	        delay_ms(100);
  	        }
	    }
	    servo_robot(FORWARD,50);
	    delay_ms(500);
	    servo_robot(SPIN_LEFT,100);
	    delay_ms(350);
	    count++;
    }
    servo_robot(STOP,0);
    delay_ms(10000);
}
