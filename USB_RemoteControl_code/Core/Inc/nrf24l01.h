#ifndef E67CE933_5B5F_43DC_A2BA_92D8E4803092
#define E67CE933_5B5F_43DC_A2BA_92D8E4803092

#include "gpio.h"
#include "spi.h"

#define RF_HSPI hspi1

void RF_Init();
void RF_InterruptHandler(uint16_t pin);

#endif /* E67CE933_5B5F_43DC_A2BA_92D8E4803092 */
