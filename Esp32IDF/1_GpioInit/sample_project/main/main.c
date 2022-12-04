#include <stdio.h>

#include "driver/gpio.h"





void gpio_set_state(unsigned char  pin,unsigned char  mode){

    gpio_config_t ioConfig = {
		.pin_bit_mask = (0x01 << pin),
//等价于	.pin_bit_mask = 0x60000
		.mode = mode,
	//	.	....省
	//  .   ....略
	//	.	....号
	};
	//传入gpio_config_t指针
	gpio_config(&ioConfig);

}


void init(){
gpio_set_direction(2,GPIO_MODE_OUTPUT);


gpio_set_level(2,1);



gpio_set_state(12, GPIO_MODE_OUTPUT);
gpio_set_state(13, GPIO_MODE_OUTPUT);
gpio_set_state(14, GPIO_MODE_OUTPUT);

gpio_set_direction(27, GPIO_MODE_INPUT);
gpio_set_direction(34, GPIO_MODE_INPUT);
gpio_set_direction(35, GPIO_MODE_INPUT);

gpio_set_level(12,1);
gpio_set_level(13,1);
gpio_set_level(14,1);



gpio_set_intr_type(34,GPIO_INTR_NEGEDGE);




}
unsigned char flag = 0;
void KeyScanner(){

    
    if(gpio_get_level(27)==0){
        while(gpio_get_level(27)==0);
        gpio_set_level(12,0);
                gpio_set_level(2,0);
    }
    if(gpio_get_level(34)==0){
        while(gpio_get_level(34)==0);
        gpio_set_level(13,0);    
                flag = 0;    
    }    
    if(gpio_get_level(35)==0){
        while(gpio_get_level(35)==0);
        gpio_set_level(14,0);
        flag = 1;

    }

}


void Led2_Hx(){

unsigned int count = 1000;
    for (int i = 0; i < count; i++)
    {
        do
        {
                   
        for (int j = 0; j < i; j++)
        {
            gpio_set_level(2,1);
            if (flag == 0)break;
            
    
        }
        for(int j = 0;j < count -i ;j++){
            gpio_set_level(2,0);if (flag == 0)break;
        }  
        } while (gpio_get_level(27) == 0);
 if (flag == 0)break;    
    }

    for (int i = 0; i < count; i++)
    {
    do
    {
            
        for (int j = 0; j < i; j++)
        {
            gpio_set_level(2,0);if (flag == 0)break;
        }
        for(int j = 0;j < count -i ;j++){
            gpio_set_level(2,1);if (flag == 0)break;
        } 
if (flag == 0)break;
    } while (gpio_get_level(27) == 0);     
    }    

}

void app_main(void)
{

init();



while (1)
{
    KeyScanner();


if (flag)
{
    Led2_Hx();
}
   

}


}
