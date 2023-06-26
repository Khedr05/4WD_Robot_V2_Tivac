/*
 * DCM_cfg.c
 *
 *     Created on: Jun 25, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 */




 /**********************************************************************
 * Includes
 **********************************************************************/
#include "dcm_cfg.h" /* For this modules definitions */

 /*******************************************************************************************************************************************************************/
 /* Declaration and Initialization */


str_dcm_confige_t str_g_carMotors[4] =
{

	{
		{
		  .pinMode				  =		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				  =		 GPIO_LOGIC_LOW,
		  .portNumber       =		 GPIO_PORTE ,
		  .pinNumber			  =		 GPIO_PIN2  ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL                      
		},
		  DCM0_PIN_0
	},

	{
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
		  DCM0_PIN_1
	},

	{
		{
		  .pinMode				=		 GPIO_MODE_DIGITAL,
		  .currentLevel			=		 GPIO_CUR_8MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTE ,
		  .pinNumber			=		 GPIO_PIN4 ,
			.interruptStatus        = GPIO_INTERRUPT_DISABLE         ,
       .interruptSenseControl  = GPIO_INTERRUPT_SENSE_DISABLED  ,
       .interruptEvent         = GPIO_INTERRUPT_EVENT_DISABLED  , 
       .triggerStatus          = GPIO_INTERRUPT_TRIGGER_DISABLED,
			 .ptrFucnPinIrqCallback  = PTR_NULL
		},
		  DCM1_PIN_0
	},

	{
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
		  DCM1_PIN_1
	}
};


/*******************************************************************************************************************************************************************/
/****************************************************************************************************************************************/

