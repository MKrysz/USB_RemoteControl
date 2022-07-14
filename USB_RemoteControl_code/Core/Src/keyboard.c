#include "keyboard.h"
#include "usbd_hid.h"
#include "usb_device.h"
#include "ctype.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
uint32_t USB_delay;
#define SEND_DELAY HAL_Delay(USB_delay)


void KEYBOARD_MEDIA_Press(uint8_t media)
{
    mediaHID_t mediaReport = {0};
    mediaReport.id = 2;
    mediaReport.keys = media;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *) &mediaReport, sizeof (mediaReport));
    SEND_DELAY;
}

void KEYBOARD_MEDIA_Send(uint8_t media)
{
    KEYBOARD_MEDIA_Press(media);
    KEYBOARD_MEDIA_Press(0);
}

void KEYBOARD_Init()
{
    USB_delay = USBD_HID_GetPollingInterval(&hUsbDeviceFS);
}

void KEYBOARD_PressKeys(uint8_t *keys, size_t nrOfKeys, uint8_t modifier)
{
    keyboardHID_t keyboardReport = {0};
    for (size_t i = 0; i < 3; i++)
    {
        keyboardReport.keys[i] = i<nrOfKeys?keys[i]:0;
    }
    keyboardReport.modifier = modifier;
    keyboardReport.id = 1;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *) &keyboardReport, sizeof (keyboardReport));
    SEND_DELAY;
}

void KEYBOARD_PressKey(uint8_t key, uint8_t modifier)
{
    KEYBOARD_PressKeys(&key, 1, modifier);
}

void KEYBOARD_Release()
{
    KEYBOARD_PressKey(0,0);
}

void KEYBOARD_SendKey(uint8_t key, uint8_t modifier)
{
    KEYBOARD_PressKey(key, modifier);
    KEYBOARD_Release();
}

void KEYBOARD_SendKeys(uint8_t *keys, uint8_t nrOfKeys, uint8_t modifier)
{
    KEYBOARD_PressKeys(keys, 1, modifier);
    KEYBOARD_Release();
}

void KEYBOARD_Enter()
{
    KEYBOARD_SendKey(KEYBOARD_KEY_ENTER, KEYBOARD_MOD_NO_MOD);
}

void KEYBOARD_Print(char* message, uint8_t modifier)
{
    for(size_t i = 0; message[i] != 0; i++){
        char c = message[i];
        //if character is uppercase hold left shift while writing
        uint8_t mod = modifier;
        if(isupper(c)){
            mod |= KEYBOARD_MOD_LEFT_SHIFT;
            c = tolower(c);
        }
        switch(c){
            case('a'):
                KEYBOARD_SendKey(KEYBOARD_KEY_A, mod);
                break;
            case('b'):
                KEYBOARD_SendKey(KEYBOARD_KEY_B, mod);
                break;
            case('c'):
                KEYBOARD_SendKey(KEYBOARD_KEY_C, mod);
                break;
            case('d'):
                KEYBOARD_SendKey(KEYBOARD_KEY_D, mod);
                break;
            case('e'):
                KEYBOARD_SendKey(KEYBOARD_KEY_E, mod);
                break;
            case('f'):
                KEYBOARD_SendKey(KEYBOARD_KEY_F, mod);
                break;
            case('g'):
                KEYBOARD_SendKey(KEYBOARD_KEY_G, mod);
                break;
            case('h'):
                KEYBOARD_SendKey(KEYBOARD_KEY_H, mod);
                break;
            case('i'):
                KEYBOARD_SendKey(KEYBOARD_KEY_I, mod);
                break;
            case('j'):
                KEYBOARD_SendKey(KEYBOARD_KEY_J, mod);
                break;
            case('k'):
                KEYBOARD_SendKey(KEYBOARD_KEY_K, mod);
                break;
            case('l'):
                KEYBOARD_SendKey(KEYBOARD_KEY_L, mod);
                break;
            case('m'):
                KEYBOARD_SendKey(KEYBOARD_KEY_M, mod);
                break;
            case('n'):
                KEYBOARD_SendKey(KEYBOARD_KEY_N, mod);
                break;
            case('o'):
                KEYBOARD_SendKey(KEYBOARD_KEY_O, mod);
                break;
            case('p'):
                KEYBOARD_SendKey(KEYBOARD_KEY_P, mod);
                break;
            case('q'):
                KEYBOARD_SendKey(KEYBOARD_KEY_Q, mod);
                break;
            case('r'):
                KEYBOARD_SendKey(KEYBOARD_KEY_R, mod);
                break;
            case('s'):
                KEYBOARD_SendKey(KEYBOARD_KEY_S, mod);
                break;
            case('t'):
                KEYBOARD_SendKey(KEYBOARD_KEY_T, mod);
                break;
            case('u'):
                KEYBOARD_SendKey(KEYBOARD_KEY_U, mod);
                break;
            case('v'):
                KEYBOARD_SendKey(KEYBOARD_KEY_V, mod);
                break;
            case('w'):
                KEYBOARD_SendKey(KEYBOARD_KEY_W, mod);
                break;
            case('x'):
                KEYBOARD_SendKey(KEYBOARD_KEY_X, mod);
                break;
            case('y'):
                KEYBOARD_SendKey(KEYBOARD_KEY_Y, mod);
                break;
            case('z'):
                KEYBOARD_SendKey(KEYBOARD_KEY_Z, mod);
                break;
            case('0'):
                KEYBOARD_SendKey(KEYBOARD_KEY_0, mod);
                break;
            case('1'):
                KEYBOARD_SendKey(KEYBOARD_KEY_1, mod);
                break;
            case('2'):
                KEYBOARD_SendKey(KEYBOARD_KEY_2, mod);
                break;
            case('3'):
                KEYBOARD_SendKey(KEYBOARD_KEY_3, mod);
                break;
            case('4'):
                KEYBOARD_SendKey(KEYBOARD_KEY_4, mod);
                break;
            case('5'):
                KEYBOARD_SendKey(KEYBOARD_KEY_5, mod);
                break;
            case('6'):
                KEYBOARD_SendKey(KEYBOARD_KEY_6, mod);
                break;
            case('7'):
                KEYBOARD_SendKey(KEYBOARD_KEY_7, mod);
                break;
            case('8'):
                KEYBOARD_SendKey(KEYBOARD_KEY_8, mod);
                break;
            case('9'):
                KEYBOARD_SendKey(KEYBOARD_KEY_9, mod);
                break;
            case('='):
                KEYBOARD_SendKey(KEYBOARD_KEY_EQUAL, mod);
                break;
            case(' '):
                KEYBOARD_SendKey(KEYBOARD_KEY_SPACEBAR, mod);
                break;
            case('('):
                KEYBOARD_SendKey(KEYBOARD_KEY_9, mod | KEYBOARD_MOD_LEFT_SHIFT);
                break;
            case(')'):
                KEYBOARD_SendKey(KEYBOARD_KEY_0, mod | KEYBOARD_MOD_LEFT_SHIFT);
                break;
            case('?'):
                KEYBOARD_SendKey(KEYBOARD_KEY_SLASH, mod | KEYBOARD_MOD_LEFT_SHIFT);
                break;
            case('&'):
                KEYBOARD_SendKey(KEYBOARD_KEY_7, mod | KEYBOARD_MOD_LEFT_SHIFT);
                break;
            case('\\'):
                KEYBOARD_SendKey(KEYBOARD_KEY_BACKSLASH, mod);
                break;
            case('|'):
                KEYBOARD_SendKey(KEYBOARD_KEY_BACKSLASH, mod | KEYBOARD_MOD_LEFT_SHIFT);
                break;
            case('\n'):
                KEYBOARD_SendKey(KEYBOARD_KEY_ENTER, mod);
                break;
            case('/'):
                KEYBOARD_SendKey(KEYBOARD_KEY_SLASH, mod);
                break;
            case(':'):
                KEYBOARD_SendKey(KEYBOARD_KEY_SEMICOLON, mod | KEYBOARD_MOD_LEFT_SHIFT);
                break;
            case('.'):
                KEYBOARD_SendKey(KEYBOARD_KEY_DOT, mod);
                break;
            default:
                break;
        }
    }
}


