#ifndef FC327D07_6E17_4882_B7E8_60515E178E01
#define FC327D07_6E17_4882_B7E8_60515E178E01

#include "usbd_hid.h"

typedef struct
{
	uint8_t button;
	int8_t mouse_x;
	int8_t mouse_y;
	int8_t wheel;
} mouseHID;

extern USBD_HandleTypeDef hUsbDeviceFS;

void MOUSE_Move(int8_t X, int8_t Y);
void MOUSE_Click();
void MOUSE_Scroll(int8_t val);

#endif /* FC327D07_6E17_4882_B7E8_60515E178E01 */