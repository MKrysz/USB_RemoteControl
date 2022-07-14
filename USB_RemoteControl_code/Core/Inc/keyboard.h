#ifndef E5BD33A5_2FCA_489D_BDA3_25396E6F4612
#define E5BD33A5_2FCA_489D_BDA3_25396E6F4612

#include "main.h"
typedef struct
{
	uint8_t id;
	uint8_t modifier;
	uint8_t keys[3];
} keyboardHID_t;

typedef struct
{
	uint8_t id;
	uint8_t keys;
} mediaHID_t;

// MODIFIER KEYS
#define KEYBOARD_MOD_NO_MOD 0x00
#define KEYBOARD_MOD_LEFT_CTRL 0x01
#define KEYBOARD_MOD_LEFT_SHIFT 0x02
#define KEYBOARD_MOD_LEFT_ALT 0x04
#define KEYBOARD_MOD_LEFT_WIN 0x08
#define KEYBOARD_MOD_RIGHT_CTRL 0x10
#define KEYBOARD_MOD_RIGHT_SHIFT 0x20
#define KEYBOARD_MOD_RIGHT_ALT 0x40
#define KEYBOARD_MOD_RIGHT_WIN 0x80

// USB media codes
#define KEYBOARD_MEDIA_SCAN_NEXT 0x01
#define KEYBOARD_MEDIA_SCAN_PREV 0x02
#define KEYBOARD_MEDIA_STOP      0x04
#define KEYBOARD_MEDIA_EJECT     0x08
#define KEYBOARD_MEDIA_PAUSE     0x10
#define KEYBOARD_MEDIA_MUTE      0x20
#define KEYBOARD_MEDIA_VOL_INC   0x40
#define KEYBOARD_MEDIA_VOL_DEC   0x80


//KEYCODES
#define KEYBOARD_KEY_A 4
#define KEYBOARD_KEY_B 5
#define KEYBOARD_KEY_C 6
#define KEYBOARD_KEY_D 7
#define KEYBOARD_KEY_E 8
#define KEYBOARD_KEY_F 9
#define KEYBOARD_KEY_G 10
#define KEYBOARD_KEY_H 11
#define KEYBOARD_KEY_I 12
#define KEYBOARD_KEY_J 13
#define KEYBOARD_KEY_K 14
#define KEYBOARD_KEY_L 15
#define KEYBOARD_KEY_M 16
#define KEYBOARD_KEY_N 17
#define KEYBOARD_KEY_O 18
#define KEYBOARD_KEY_P 19
#define KEYBOARD_KEY_Q 20
#define KEYBOARD_KEY_R 21
#define KEYBOARD_KEY_S 22
#define KEYBOARD_KEY_T 23
#define KEYBOARD_KEY_U 24
#define KEYBOARD_KEY_V 25
#define KEYBOARD_KEY_W 26
#define KEYBOARD_KEY_X 27
#define KEYBOARD_KEY_Y 28
#define KEYBOARD_KEY_Z 29
#define KEYBOARD_KEY_1 30
#define KEYBOARD_KEY_2 31
#define KEYBOARD_KEY_3 32
#define KEYBOARD_KEY_4 33
#define KEYBOARD_KEY_5 34
#define KEYBOARD_KEY_6 35
#define KEYBOARD_KEY_7 36
#define KEYBOARD_KEY_8 37
#define KEYBOARD_KEY_9 38
#define KEYBOARD_KEY_0 39
#define KEYBOARD_KEY_ENTER 40
#define KEYBOARD_KEY_ESCAPE 41
#define KEYBOARD_KEY_DELETE 42
#define KEYBOARD_KEY_TAB 43
#define KEYBOARD_KEY_SPACEBAR 44
#define KEYBOARD_KEY_MINUS 45
#define KEYBOARD_KEY_EQUAL 46
#define KEYBOARD_KEY_SQUARE_BRACKET_LEFT 47
#define KEYBOARD_KEY_SQUARE_BRACKET_RIGHT 48
#define KEYBOARD_KEY_BACKSLASH 49
#define KEYBOARD_KEY_HASH 50
#define KEYBOARD_KEY_SEMICOLON 51
#define KEYBOARD_KEY_APOSTROPHE 52
#define KEYBOARD_KEY_GRAVE_ACCENT 53
#define KEYBOARD_KEY_COMMA 54
#define KEYBOARD_KEY_DOT 55
#define KEYBOARD_KEY_SLASH 56
#define KEYBOARD_KEY_CAPS_LOCK 57
#define KEYBOARD_KEY_F1 58
#define KEYBOARD_KEY_F2 59
#define KEYBOARD_KEY_F3 60
#define KEYBOARD_KEY_F4 61
#define KEYBOARD_KEY_F5 62
#define KEYBOARD_KEY_F6 63
#define KEYBOARD_KEY_F7 64
#define KEYBOARD_KEY_F8 65
#define KEYBOARD_KEY_F9 66
#define KEYBOARD_KEY_F10 67
#define KEYBOARD_KEY_F11 68
#define KEYBOARD_KEY_F12 69
#define KEYBOARD_KEY_PRINT_SCREEEN 70
#define KEYBOARD_KEY_SCROLL_LOCK 71
#define KEYBOARD_KEY_PAUSE 72
#define KEYBOARD_KEY_INSERT 73
/* ... */
#define KEYBOARD_DELETE_FORWARD 76
/* ... */
#define KEYBOARD_KEY_RIGHT_ARROW 79
#define KEYBOARD_KEY_LEFT_ARROW 80
#define KEYBOARD_KEY_DOWN_ARROW 81
#define KEYBOARD_KEY_UP_ARROW 82
/* ... */
// #define KEYBOARD_KEY_F13 104
// #define KEYBOARD_KEY_F14 105
// #define KEYBOARD_KEY_F15 106
// #define KEYBOARD_KEY_F16 107
// #define KEYBOARD_KEY_F17 108
// #define KEYBOARD_KEY_F18 109
// #define KEYBOARD_KEY_F19 110
// #define KEYBOARD_KEY_F20 111
// #define KEYBOARD_KEY_F21 112
// #define KEYBOARD_KEY_F22 113
// #define KEYBOARD_KEY_F23 114
// #define KEYBOARD_KEY_F24 115
// /* ... */
// #define KEYBOARD_KEY_MUTE 127
// #define KEYBOARD_KEY_VOLUME_UP 128
// #define KEYBOARD_KEY_VOLUME_DOWN 129

void KEYBOARD_Init();
void KEYBOARD_Enter();
void KEYBOARD_Clear();
void KEYBOARD_Print(char* message, uint8_t modifier);
void KEYBOARD_SendKey(uint8_t key, uint8_t modifier);
void KEYBOARD_SendKeys(uint8_t *keys, uint8_t nrOfKeys, uint8_t modifier);
void KEYBOARD_PressKey(uint8_t key, uint8_t modifier);
void KEYBOARD_Release();
void KEYBOARD_PressKeys(uint8_t *keys, size_t nrOfKeys, uint8_t modifier);
void KEYBOARD_MEDIA_Press(uint8_t media);
void KEYBOARD_MEDIA_Send(uint8_t media);

#endif /* E5BD33A5_2FCA_489D_BDA3_25396E6F4612 */
