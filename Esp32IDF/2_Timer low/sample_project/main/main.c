#include <stdio.h>
#include "esp_timer.h"
#include "esp32/rom/ets_sys.h"
#include "driver/uart.h"

void delay(unsigned int t){
    while(t --){
        ets_delay_us(1000);
    }
}
void app_main(void)
{
    	uart_set_baudrate(115200);
    while(1){
        uart_write_bytes("123123");
        delay(300);
    }
}
