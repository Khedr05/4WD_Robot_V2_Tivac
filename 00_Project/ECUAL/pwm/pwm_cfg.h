/*
**@file     : pwm_cfg.h
**@brief    : this is header file for pwm configuration
**@author   : sharpel
**@date     : 25 june 2023
**@version  : 0.1
*/



#ifndef PWM_CFG_H_
#define PWM_CFG_H_


#include "gpio_interface.h"

#define MAX_PWM_PINS    2

typedef enum
{
	PWM_CHANNEL_0  = 0 ,
	PWM_CHANNEL_1      ,
	PWM_CHANNEL_2      ,
	PWM_CHANNEL_3      ,

}enu_pwm_channels_t;

typedef struct
{
	enu_pwm_channels_t enu_pwm_channel;
	ST_dio_pinCfg_t    str_dio_cfg;
}str_pwm_congigs_t;

#endif




