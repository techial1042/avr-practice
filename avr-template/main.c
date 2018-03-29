/*
imakew -f FIRST.mak
*/
#include <iom16v.h>
#include <macros.h>

#define ARRAY_SIZE_UNSAFE(ARR) (sizeof((ARR)) / sizeof(*(ARR)))

const char step_out[] = {
//       45    90   135   180   -135   -90  -45,  0
	0x02, 0x06, 0x04, 0x0C, 0x08, 0x09, 0x01, 0x03,
//       0     2     3     4      5     6     7    8
};

const char step_index[] = {
//      0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
	-1, 6, 0, 7, 2, -1, 1, -1, 4, 5,  -1,  -1, 3,
};

void delay(unsigned int time)
{
	int i = 0;
	while (time--) {
		for (i = 0; i < 100; i++);
	}
}

void init(void)
{
	DDRB = 0x7F;
	PORTB = 0x00;

	DDRC = 0x00;

	DDRD = 0x00; 
	PORTD = 0x0F;
}

void turn45(char direct)
{
	char next = (step_index[PORTB] + direct + ARRAY_SIZE_UNSAFE(step_out)) % ARRAY_SIZE_UNSAFE(step_out);
	PORTB = step_out[next];
}

int main(void)
{
	unsigned char direct = 0;
	unsigned char turn_cnt = 0;
	init();
	while (1) {
		int i = 0;
		int btn = ~PIND & 7;

		if (btn) {
			DDRC = 1 << 2;
			direct = 0;	
			turn_cnt = 0;
			while (~PIND & 7);

			DDRC = btn;
			if (btn == 1 << 0) {
				direct = 1;
			} else if (btn == 1 << 1) {
				direct = -1;
			}
			if (direct)
				turn_cnt = 3 * ARRAY_SIZE_UNSAFE(step_out);
		}

		if (direct && turn_cnt) {
			turn45(direct);
			delay(200);
			turn_cnt--;
		} else {
			DDRC = 1 << 2;
		}	
	}
	
	return 0;
}
