/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/
#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"

int LED_BUILTIN = 25;

void blink() {
	gpio_put(LED_BUILTIN, 1);
	sleep_ms(750);

	gpio_put(LED_BUILTIN, 0);
	sleep_ms(1050);
}

int main() {
	stdio_init_all();
	
	gpio_init(LED_BUILTIN);
	gpio_set_dir(LED_BUILTIN, GPIO_OUT);

	puts("Hello World\n");

	while (true) {    
			puts(".");    
			blink();
	}
}