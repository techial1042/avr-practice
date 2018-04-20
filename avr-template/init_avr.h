#ifndef _INIT_AVR_H_
#define _INIT_AVR_H_

void init(void)
{
	CLI();
	PORTA = 0x00;
	DDRA  = 0x01;

	PORTB = 0x00;
	DDRB  = 0x03;

	PORTD = 0xff;
	DDRD  = 0xF0;

	TCCR0 = 0x00;
	TCNT0 = 0x83;
	OCR0  = 0x7D;
	TCCR0 = 0x0B;

	MCUCR = 0x00;
	GICR  = 0x00;
	TIMSK = 0x02;
	SEI();
}

#endif /* _INIT_AVR_H_ */