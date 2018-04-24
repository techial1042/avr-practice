/*
imakew -f FIRST.mak
*/
#include <iom16v.h>
#include <macros.h>
#include <math.h>
#include "define.h"
#include "led_send_display.h"
#include "key.h"
#include "init_avr.h"

unsigned long time = 0;
#pragma interrupt_handler timer0_comp_isr:iv_TIM0_COMP
void timer0_comp_isr(void)
{
	time++;
	ADCSRA |= (1 << ADSC);
	while (!(ADCSRA & (1 << ADIF)));
	ADCSRA |= (1 << ADIF);
}

void adc_init(void)
{
	ADMUX = 0x47;
	ADCSR = 0x87;
}

unsigned long get_v()
{
	return (unsigned long)ADC * 3300 / 1024;
}

int main(void)
{
	static char value[] = {1, 2, 4, 3, 5};
	const unsigned long MAX_V = 3000;
	unsigned char size = sizeof(value) / sizeof(*value);
	unsigned long v = get_v();
	unsigned long i = 0, j = 0;
	init();
	adc_init();
	while (1) {
		v = get_v();
		for (int i = 0; i < size; i++)
			if (abs(MAX_V / (i * 1.0 / (i + 3.0)) - v) < 100)
				j = i;
		display_number(value[j], 4, 0, &time);
	}
	return 0;
}
