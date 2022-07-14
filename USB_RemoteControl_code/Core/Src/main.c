/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "keyboard.h"
#include "usbd_hid.h"
#include "usb_device.h"
extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// USB media codes
#define USB_HID_SCAN_NEXT 0x01
#define USB_HID_SCAN_PREV 0x02
#define USB_HID_STOP      0x04
#define USB_HID_EJECT     0x08
#define USB_HID_PAUSE     0x10
#define USB_HID_MUTE      0x20
#define USB_HID_VOL_UP    0x40
#define USB_HID_VOL_DEC   0x80

// USB keyboard codes
#define USB_HID_MODIFIER_LEFT_CTRL   0x01
#define USB_HID_MODIFIER_LEFT_SHIFT  0x02
#define USB_HID_MODIFIER_LEFT_ALT    0x04
#define USB_HID_MODIFIER_LEFT_GUI    0x08 // (Win/Apple/Meta)
#define USB_HID_MODIFIER_RIGHT_CTRL  0x10
#define USB_HID_MODIFIER_RIGHT_SHIFT 0x20
#define USB_HID_MODIFIER_RIGHT_ALT   0x40
#define USB_HID_MODIFIER_RIGHT_GUI   0x80
#define USB_HID_KEY_L     0x0F

#define UART_BUFFER_SIZE 128
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  // HID Keyboard
  struct keyboardHID_t {
      uint8_t id;
      uint8_t modifiers;
      uint8_t key1;
      uint8_t key2;
      uint8_t key3;
  };
  struct keyboardHID_t keyboardHID;
  keyboardHID.id = 1;
  keyboardHID.modifiers = 0;
  keyboardHID.key1 = 0;
  keyboardHID.key2 = 0;
  keyboardHID.key3 = 0;
  // HID Media
  struct mediaHID_t {
    uint8_t id;
    uint8_t keys;
  };
  struct mediaHID_t mediaHID;
  mediaHID.id = 2;
  mediaHID.keys = 0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  KEYBOARD_Init();
  char UART_Buffer[UART_BUFFER_SIZE] = "";

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // for (size_t i = 0; i < UART_BUFFER_SIZE; i++)
    // {
    //   UART_Buffer[i] = 0;
    // }
    // HAL_UART_Receive(&huart1, UART_Buffer, UART_BUFFER_SIZE, 500);
    // if(UART_Buffer[0] == 0)
    //   continue;
    // #define cmdEq(X) (strcmp(UART_Buffer, (X)) == 0)
    // if(cmdEq("Right")){
    //   KEYBOARD_SendKey(KEYBOARD_KEY_RIGHT_ARROW, KEYBOARD_MOD_LEFT_CTRL | KEYBOARD_MOD_LEFT_ALT);
    // }
    // else if(cmdEq("Left")){
    //   KEYBOARD_SendKey(KEYBOARD_KEY_LEFT_ARROW, KEYBOARD_MOD_LEFT_CTRL | KEYBOARD_MOD_LEFT_ALT);
    // }
    // else if(cmdEq("Center")){
    //   KEYBOARD_SendKey(KEYBOARD_KEY_SPACEBAR, KEYBOARD_MOD_LEFT_CTRL | KEYBOARD_MOD_LEFT_ALT);
    // }
    // else if(cmdEq("VolUp")){
    //   KEYBOARD_SendKey(KEYBOARD_KEY_VOLUME_UP, 0);
    // }
    // else if(cmdEq("VolDown")){
    //   KEYBOARD_SendKey(KEYBOARD_KEY_VOLUME_DOWN, 0);
    // }
    // else if(cmdEq("Mute")){
    //   KEYBOARD_SendKey(KEYBOARD_KEY_MUTE, 0);
    // }
    // // else if(cmdEq("%Test")){
    // //   KEYBOARD_SendKey(KEYBOARD_KEY_MUTE, 0);
    // // }
    // else{
    //   KEYBOARD_Print("NOOP\n", KEYBOARD_MOD_NO_MOD);
    //   KEYBOARD_Print(UART_Buffer, KEYBOARD_MOD_NO_MOD);
    // }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */    // Send HID report
    mediaHID.keys = USB_HID_VOL_DEC;
    USBD_HID_SendReport(&hUsbDeviceFS, &mediaHID, sizeof(struct mediaHID_t));
    HAL_Delay(300);
    mediaHID.keys = 0;
    USBD_HID_SendReport(&hUsbDeviceFS, &mediaHID, sizeof(struct mediaHID_t));
    HAL_Delay(300);

    keyboardHID.modifiers = USB_HID_MODIFIER_RIGHT_SHIFT;
    keyboardHID.key1 = USB_HID_KEY_L;
    USBD_HID_SendReport(&hUsbDeviceFS, &keyboardHID, sizeof(struct keyboardHID_t));
    HAL_Delay(300);
    keyboardHID.modifiers = 0;
    keyboardHID.key1 = 0;
    USBD_HID_SendReport(&hUsbDeviceFS, &keyboardHID, sizeof(struct keyboardHID_t));
    HAL_Delay(300);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
