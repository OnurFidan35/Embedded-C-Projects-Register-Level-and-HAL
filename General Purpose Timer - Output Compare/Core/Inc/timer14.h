#include "stm32f4xx.h"
#include "stdint.h"
#ifndef __TİMER14_DRIVER_H
#define __TİMER14_DRIVER_H

void timer14_init(void);
void timer14_enable(void);
void timer14_disable(void);
void timer_14_capture_set_period(uint16_t ms);

#endif
