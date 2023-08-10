/*
**@file     : pwm_interface.h
**@brief    : this is header file to interface with pwm
**@author   : sharpel
**@date     : 25 june 2023
**@version  : 0.1
*/



#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#include "pwm_cfg.h"

typedef enum
{
	PWM_OK = 0,
	PWM_ERROR
}enu_pwm_error_status_t;


enu_pwm_error_status_t PWM_init_channel     (enu_pwm_channels_t enu_arg_pwm_channel);
enu_pwm_error_status_t PWM_init_all_channels(void);
enu_pwm_error_status_t PWM_set_Duty         (Uint16_t u16_arg_signal_duration_ms ,Uint8_t u8_arg_duty_cycle);
enu_pwm_error_status_t PWM_stop             (void);


#endif




