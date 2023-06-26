/*
 * dio_config.c
 *
 *  Created on: 15 Jun 2023
 *      Author: 20101
 */


#include "gpio_interface.h"



extern void callback(void);


ST_dio_pinCfg_t a_cfgPins[PINS_CFG_ARRAY_SIZE] = 
{
	{
		  .pinMode				  =		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				  =		 GPIO_LOGIC_HIGH,
		  .portNumber       =		 GPIO_PORTE ,
		  .pinNumber			  =		 GPIO_PIN2  ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL                      
		},
		{
		  .pinMode				=		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTE ,
		  .pinNumber			=		 GPIO_PIN3  ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL
		},
		{
		  .pinMode				=		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_HIGH,
		  .portNumber			=		 GPIO_PORTE ,
		  .pinNumber			=		 GPIO_PIN4 ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL
		},
		{
		  .pinMode				=		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTE ,
		  .pinNumber			=		 GPIO_PIN5  ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL
		},
		{
		  .pinMode				  =		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				  =		 GPIO_LOGIC_HIGH,
		  .portNumber       =		 GPIO_PORTB ,
		  .pinNumber			  =		 GPIO_PIN7 ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL                      
		},
		{
		  .pinMode				  =		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				  =		 GPIO_LOGIC_HIGH,
		  .portNumber       =		 GPIO_PORTF ,
		  .pinNumber			  =		 GPIO_PIN0 ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL                      
		},
		{
		  .pinMode				  =		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				  =		 GPIO_LOGIC_HIGH,
		  .portNumber       =		 GPIO_PORTF ,
		  .pinNumber			  =		 GPIO_PIN1 ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL                      
		},
};

