#include "mouse.h"


void MOUSE_Move(int8_t X, int8_t Y)
{
  mouseHID mouse = {0};
  mouse.mouse_x = X;
  mouse.mouse_y = Y;
  USBD_HID_SendReport(&hUsbDeviceFS, &mouse, sizeof(mouseHID));
}


void MOUSE_Click()
{
  mouseHID mouse = {0};
  mouse.button = 1;
  USBD_HID_SendReport(&hUsbDeviceFS, &mouse, sizeof(mouseHID));
  HAL_Delay(50);
  mouse.button = 0;
  USBD_HID_SendReport(&hUsbDeviceFS, &mouse, sizeof(mouseHID));
  HAL_Delay(50);
}


void MOUSE_Scroll(int8_t val)
{
  mouseHID mouse = {0};
  mouse.wheel = val;
  USBD_HID_SendReport(&hUsbDeviceFS, &mouse, sizeof(mouseHID));
  HAL_Delay(50);
}