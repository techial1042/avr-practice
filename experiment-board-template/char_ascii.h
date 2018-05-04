#ifndef _CHAR_ASCII_H_
#define _CHAR_ASCII_H_

struct CHINESE_ASCII {
	unsigned char value[2];
	unsigned char data[24];
};

const struct CHINESE_ASCII chinese[] = {
	{
		"��", {
			0x40, 0x48, 0x48, 0xFC, 0x44, 0x40, 0xFC, 0x40, 0x40, 0x48, 0x50, 0x00,
			0x08, 0x08, 0x24, 0x3F, 0x02, 0x10, 0x0B, 0x0C, 0x12, 0x21, 0x38, 0x00
		}
	},
	{
		"��", {
			0x40, 0xF0, 0x0C, 0x00, 0xF4, 0x08, 0x10, 0x08, 0x08, 0x08, 0xF8, 0x00,
			0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1F, 0x00
		}
	},
	{
		"Ƕ", {
			0x40, 0xFC, 0x50, 0x50, 0xF0, 0x5C, 0x90, 0x70, 0x50, 0x5C, 0xC0, 0x00,
			0x00, 0x1F, 0x0A, 0x0A, 0x1F, 0x11, 0x08, 0x07, 0x04, 0x09, 0x10, 0x00
		}
	},
	{
		"��", {
			0x00, 0x00, 0x00, 0x04, 0xC4, 0x38, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x00
		}
	},
	{
		"ʽ", {
			0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xFC, 0x10, 0x14, 0x18, 0x10, 0x00,
			0x10, 0x10, 0x10, 0x0F, 0x08, 0x08, 0x01, 0x06, 0x08, 0x10, 0x1C, 0x00
		}
	}
};

#endif /* _CHAR_ASCII_H_ */