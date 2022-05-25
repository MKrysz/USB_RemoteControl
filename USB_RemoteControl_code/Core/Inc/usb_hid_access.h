#ifndef BCB924AC_F6E3_4B3C_8E5C_6DB8D7463736
#define BCB924AC_F6E3_4B3C_8E5C_6DB8D7463736
#ifndef E5BD33A5_2FCA_489D_BDA3_25396E6F4612
#define E5BD33A5_2FCA_489D_BDA3_25396E6F4612

#include "main.h"
#include "stdint.h"

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} keyboardHID_t;


// MODIFIER KEYS

#define USB_HID_MOD_NO_MOD 0x00
#define USB_HID_MOD_LEFT_CTRL 0x01
#define USB_HID_MOD_LEFT_SHIFT 0x02
#define USB_HID_MOD_LEFT_ALT 0x04
#define USB_HID_MOD_LEFT_WIN 0x08
#define USB_HID_MOD_RIGHT_CTRL 0x10
#define USB_HID_MOD_RIGHT_SHIFT 0x20
#define USB_HID_MOD_RIGHT_ALT 0x40
#define USB_HID_MOD_RIGHT_WIN 0x80


//KEYCODES
//taken from https://controllerstech.com/wp-content/uploads/2020/09/KEYBOARD_HELPER.pdf

#define USB_HID_KEY_A 4
#define USB_HID_KEY_B 5
#define USB_HID_KEY_C 6
#define USB_HID_KEY_D 7
#define USB_HID_KEY_E 8
#define USB_HID_KEY_F 9
#define USB_HID_KEY_G 10
#define USB_HID_KEY_H 11
#define USB_HID_KEY_I 12
#define USB_HID_KEY_J 13
#define USB_HID_KEY_K 14
#define USB_HID_KEY_L 15
#define USB_HID_KEY_M 16
#define USB_HID_KEY_N 17
#define USB_HID_KEY_O 18
#define USB_HID_KEY_P 19
#define USB_HID_KEY_Q 20
#define USB_HID_KEY_R 21
#define USB_HID_KEY_S 22
#define USB_HID_KEY_T 23
#define USB_HID_KEY_U 24
#define USB_HID_KEY_V 25
#define USB_HID_KEY_W 26
#define USB_HID_KEY_X 27
#define USB_HID_KEY_Y 28
#define USB_HID_KEY_Z 29
#define USB_HID_KEY_1 30
#define USB_HID_KEY_2 31
#define USB_HID_KEY_3 32
#define USB_HID_KEY_4 33
#define USB_HID_KEY_5 34
#define USB_HID_KEY_6 35
#define USB_HID_KEY_7 36
#define USB_HID_KEY_8 37
#define USB_HID_KEY_9 38
#define USB_HID_KEY_0 39
#define USB_HID_KEY_ENTER 40
#define USB_HID_KEY_ESCAPE 41
#define USB_HID_KEY_DELETE 42
#define USB_HID_KEY_TAB 43
#define USB_HID_KEY_SPACEBAR 44
#define USB_HID_KEY_MINUS 45
#define USB_HID_KEY_EQUAL 46
#define USB_HID_KEY_SQUARE_BRACKET_LEFT 47
#define USB_HID_KEY_SQUARE_BRACKET_RIGHT 48
#define USB_HID_KEY_BACKSLASH 49
#define USB_HID_KEY_HASH 50
#define USB_HID_KEY_SEMICOLON 51
#define USB_HID_KEY_APOSTROPHE 52
#define USB_HID_KEY_GRAVE_ACCENT 53
#define USB_HID_KEY_COMMA 54
#define USB_HID_KEY_DOT 55
#define USB_HID_KEY_SLASH 56
#define USB_HID_KEY_CAPS_LOCK 57
#define USB_HID_KEY_F1 58
#define USB_HID_KEY_F2 59
#define USB_HID_KEY_F3 60
#define USB_HID_KEY_F4 61
#define USB_HID_KEY_F5 62
#define USB_HID_KEY_F6 63
#define USB_HID_KEY_F7 64
#define USB_HID_KEY_F8 65
#define USB_HID_KEY_F9 66
#define USB_HID_KEY_F10 67
#define USB_HID_KEY_F11 68
#define USB_HID_KEY_F12 69
#define USB_HID_KEY_PRINT_SCREEEN 70
#define USB_HID_KEY_SCROLL_LOCK 71
#define USB_HID_KEY_PAUSE 72
#define USB_HID_KEY_INSERT 73
/* ... */
#define USB_HID_KEY_RIGHT_ARROW 79
#define USB_HID_KEY_LEFT_ARROW 80
#define USB_HID_KEY_DOWN_ARROW 81
#define USB_HID_KEY_UP_ARROW 82
/* ... */
#define USB_HID_KEY_F13 104
#define USB_HID_KEY_F14 105
#define USB_HID_KEY_F15 106
#define USB_HID_KEY_F16 107
#define USB_HID_KEY_F17 108
#define USB_HID_KEY_F18 109
#define USB_HID_KEY_F19 110
#define USB_HID_KEY_F20 111
#define USB_HID_KEY_F21 112
#define USB_HID_KEY_F22 113
#define USB_HID_KEY_F23 114
#define USB_HID_KEY_F24 115
/* ... */
#define USB_HID_KEY_MUTE 127
#define USB_HID_KEY_VOLUME_UP 128
#define USB_HID_KEY_VOLUME_DOWN 129

void USB_HID_Init();
void USB_HID_Lock();
void USB_HID_Enter();
void USB_HID_Print(char* message, uint8_t modifier);
void USB_HID_SendKey(uint8_t key, uint8_t modifier);
void USB_HID_SendKeys(uint8_t *keys, uint8_t nrOfKeys, uint8_t modifier);
void USB_HID_Clear();

#endif /* E5BD33A5_2FCA_489D_BDA3_25396E6F4612 */


#endif /* BCB924AC_F6E3_4B3C_8E5C_6DB8D7463736 */
