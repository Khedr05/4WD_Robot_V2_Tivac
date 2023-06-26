/*
**@file     : pwm_cfg.c
**@brief    : this file contain pwm global config array 
**@author   : sharpel
**@date     : 25 june 2023
**@version  : 0.1
*/


#include "pwm_cfg.h"


str_pwm_congigs_t arr_str_gconst_pwm_configs[MAX_PWM_PINS] =
{
	{
     .enu_pwm_channel = PWM_CHANNEL_0 ,
	   .str_dio_cfg      = 
		 {
	     .pinMode                = GPIO_MODE_DIGITAL              ,
       .currentLevel           = GPIO_CUR_8MA                   ,
       .pinDirection           = GPIO_DIR_OUTPUT                ,
       .pinLogic               = GPIO_LOGIC_HIGH                ,
       .pinInternalAttach      = GPIO_PULL_UP                   ,
       .interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
       .portNumber             = GPIO_PORTB                     ,
       .pinNumber              = GPIO_PIN7                      ,
			.ptrFucnPinIrqCallback   = PTR_NULL
	  }
	},
	{
	   .enu_pwm_channel = PWM_CHANNEL_1 ,
	   .str_dio_cfg     = 
	  {
	     .pinMode                = GPIO_MODE_DIGITAL              ,
       .currentLevel           = GPIO_CUR_8MA                   ,
       .pinDirection           = GPIO_DIR_OUTPUT                ,
       .pinLogic               = GPIO_LOGIC_HIGH                ,
       .pinInternalAttach      = GPIO_PULL_UP                   ,
       .interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
       .portNumber             = GPIO_PORTF                     ,
       .pinNumber              = GPIO_PIN0                      ,
			 .ptrFucnPinIrqCallback  = PTR_NULL                      
	  }
	},

};
































































