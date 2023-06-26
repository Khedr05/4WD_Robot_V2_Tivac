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


str_dcm_confige_t ST_g_carMotors[4] =
{

	{
		{
		  .pinMode				=		 GPIO_MODE_GPIO,
		  .currentLevel			=		 GPIO_CUR_2MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTA ,
		  .pinNumber			=		 GPIO_PIN0
		},
		  DCM0_PIN_0
	},

	{
		{
		  .pinMode				=		 GPIO_MODE_GPIO,
		  .currentLevel			=		 GPIO_CUR_2MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTA ,
		  .pinNumber			=		 GPIO_PIN1
		},
		  DCM0_PIN_1
	},

	{
		{
		  .pinMode				=		 GPIO_MODE_GPIO,
		  .currentLevel			=		 GPIO_CUR_2MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTA ,
		  .pinNumber			=		 GPIO_PIN2
		},
		  DCM1_PIN_0
	},

	{
		{
		  .pinMode				=		 GPIO_MODE_GPIO,
		  .currentLevel			=		 GPIO_CUR_2MA,
		  .pinDirection			=		 GPIO_DIR_OUTPUT,
		  .pinLogic				=		 GPIO_LOGIC_LOW,
		  .portNumber			=		 GPIO_PORTA ,
		  .pinNumber			=		 GPIO_PIN3
		},
		  DCM1_PIN_1
	}
};


/*******************************************************************************************************************************************************************/
/****************************************************************************************************************************************/

