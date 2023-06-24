/*
 * DCM_Program.c
 *
 *     Created on: Jun 24, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 */


/**********************************************************************
* Includes
**********************************************************************/
 /* HAL */
#include "dcm_cfg.h"
#include "dcm_interface.h"
#include "pwm_interface.h"
#include "gpt_interface.h"

/*********************************************************************
* Module Variable Definitions
**********************************************************************/

enu_dcm_flag_t DCM_g_stopFlag = FALSE;

extern Uchar8_t u8_g_timeOut;
/*********************************************************************
* Module Functions Definitions
**********************************************************************/

/**********************************************************************
* Function Definitions
**********************************************************************/
/**********************************************************************
* Function : DCM_init()
*//**
* \b Description:
*
* This function is used to initialize the DCM based on the configuration
* table defined in dcm_cfg module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the
* configuration table will be returned.
*
* @return An enumeration the indicates the error_status of the dcm module.
*
* \b Example Example:
* @code
*  uint8_t error_state = DCM_init(str_dcm_confige_t);
*
* @endcode
*
* @see DCM_changeDCMDirection
* @see DCM_stopMotor
* @see DCM_u8SetDutyCycleOfPWM
* @see DCM_rotateDCM
* @see DCM_MoveForward
* @see DCM_MoveBackward
*
**********************************************************************/

enu_dcm_error_t DCM_init(str_dcm_confige_t* DCM_a_ptrToConfig)
{
	uint8_t dcm_loc_loopCounter = FALSE;
	uint8_t error_state = DCM_OK;
	if( DCM_a_ptrToConfig == NULL )
	{
		error_state = DCM_WRONG;	
	}
	else if( ( DCM_a_ptrToConfig-> gpio_for_dcm_confige.enu_pin_mode )==  DCM_LOW)
	{
		error_state = DCM_WRONG;
	}	
	else
	{
		for( dcm_loc_loopCounter ; dcm_loc_loopCounter < DCM_USED_PINS_NUM; dcm_loc_loopCounter++)
		{
			error_state = (enu_dcm_error_t) GPIO_init( DCM_a_ptrToConfig-> gpio_for_dcm_confige ); 
			if(error_state != DCM_OK)
			{
				error_state = DCM_WRONG;
				break;
			}	
			else
			{
				//Do nothing
			}

		}	
	}	
	
	// (void)PWM_init();  /*Call the PWM_init function*/
	return (enu_dcm_error_t)error_state;
}

/*******************************************************************************************************************************************/
enu_dcm_error_t DCM_changeDCMDirection(str_dcm_confige_t* DCM_a_ptrToConfig, enu_dcm_motor_side_t DCM_a_motorNum)
{
	
	uint8_t error_state = DCM_OK;
	uint8_t dcm_loc_loopCounter = FALSE + (DCM_a_motorNum * DCM_MAX_PIN_NUM);
	if( DCM_a_ptrToConfig == NULL)
	{
		error_state = DCM_WRONG;	
	}
	else
	{

		for( dcm_loc_loopCounter ; dcm_loc_loopCounter < (DCM_MAX_PIN_NUM + (DCM_a_motorNum * DCM_MAX_PIN_NUM)); dcm_loc_loopCounter++)
		{
			
			error_state = (enu_dcm_error_t) GPIO_toggle( DCM_a_ptrToConfig[dcm_loc_loopCounter]-> gpio_for_dcm_config); 
			if(error_state != DCM_OK)
			{
				error_state = DCM_WRONG;
			}
			else
			{
				//Do nothing
			}
			
		}
	}
	
	return (enu_dcm_error_t)error_state;		
}
/****************************************************************************************************************************************/
enu_dcm_error_t DCM_stopMotor(str_dcm_confige_t* DCM_a_ptrToConfig, enu_dcm_motor_side_t DCM_a_motorNum)
{

	uint8_t error_state = DCM_OK;
	uint8_t dcm_loc_loopCounter = FALSE;
	if( DCM_a_ptrToConfig == NULL)
	{
		error_state = DCM_WRONG;	
	}
	else
	{

		for( dcm_loc_loopCounter ; dcm_loc_loopCounter < (DCM_MAX_PIN_NUM + (DCM_a_motorNum * DCM_MAX_PIN_NUM)); dcm_loc_loopCounter++ )
		{
			error_state = (enu_dcm_error_t) GPIO_writeLogic( DCM_a_ptrToConfig[dcm_loc_loopCounter]-> gpio_for_dcm_config, DCM_LOW); 
			if(error_state != DCM_OK)
			{
				error_state = DCM_WRONG;
			}	
			else
			{
				//Do nothing
			}	
		}
	}
	// (void)PWM_stop();  /*Call the PWM_stop function*/
	return (enu_dcm_error_t)error_state;		
	
}

/************************************************************************************************************************************/
enu_dcm_error_t DCM_u8SetDutyCycleOfPWM(Uchar8_t DCM_a_dutyCycleValue)
{
	uint8_t error_state = DCM_OK;
	if (DCM_a_dutyCycleValue > MAX_DUTY_CYCLE)
	{
		error_state = DCM_WRONG;
		
	}
	else
	{
		// Call a PWM function to generate the desired pwm signal with the desired duty Cycle
	}
	return (enu_dcm_error_t)error_state;
}

/****************************************************************************************************************************************/