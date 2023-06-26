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

enu_dcm_flag_t DCM_g_stopFlag = FLAG_FALSE;


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
	if( DCM_a_ptrToConfig == PTR_NULL )
	{
		error_state = DCM_WRONG;	
	}
	else
	{
		for( dcm_loc_loopCounter = FALSE ; dcm_loc_loopCounter < DCM_USED_PINS_NUM; dcm_loc_loopCounter++)
		{
			error_state = (enu_dcm_error_t) GPIO_init(&DCM_a_ptrToConfig[dcm_loc_loopCounter].gpio_for_dcm_confige); 
			if(error_state != DCM_OK)
			{
				error_state = DCM_WRONG;
				break;
			}	
			else if( ( DCM_a_ptrToConfig-> gpio_for_dcm_confige.pinDirection )==  DCM_LOW)
	    {
	    	error_state = DCM_WRONG;
	    }	
			else
			{
				// do nothing
			}

		}
		
		 PWM_init_all_channels();
		
	}	
	
	// (void)PWM_init();  /*Call the PWM_init function*/
	return (enu_dcm_error_t)error_state;
}

/*******************************************************************************************************************************************/
enu_dcm_error_t DCM_changeDCMDirection(str_dcm_confige_t *DCM_a_ptrToConfig, enu_dcm_motor_side_t DCM_a_motorNum)
{
	
	uint8_t error_state = DCM_OK;
	uint8_t dcm_loc_loopCounter = FALSE + (DCM_a_motorNum * DCM_MAX_PIN_NUM);
	if( DCM_a_ptrToConfig == PTR_NULL)
	{
		error_state = DCM_WRONG;	
	}
	else
	{

		for( dcm_loc_loopCounter ; dcm_loc_loopCounter < (DCM_MAX_PIN_NUM + (DCM_a_motorNum * DCM_MAX_PIN_NUM)); dcm_loc_loopCounter++)
		{
			
			error_state = (enu_dcm_error_t) GPIO_toggleLogic( &DCM_a_ptrToConfig[dcm_loc_loopCounter].gpio_for_dcm_confige); 
			break;
			
		}
	}
	
	return (enu_dcm_error_t)error_state;		
}
/****************************************************************************************************************************************/
enu_dcm_error_t DCM_stopMotor(str_dcm_confige_t* DCM_a_ptrToConfig, enu_dcm_motor_side_t DCM_a_motorNum)
{

	uint8_t error_state = DCM_OK;
	uint8_t dcm_loc_loopCounter = FALSE;
	if( DCM_a_ptrToConfig == PTR_NULL)
	{
		error_state = DCM_WRONG;	
	}
	else
	{

		for( dcm_loc_loopCounter = FALSE ; dcm_loc_loopCounter < (DCM_MAX_PIN_NUM + (DCM_a_motorNum * DCM_MAX_PIN_NUM)); dcm_loc_loopCounter++ )
		{
			error_state = (enu_dcm_error_t) GPIO_writeLogic( &DCM_a_ptrToConfig[dcm_loc_loopCounter].gpio_for_dcm_confige, GPIO_LOGIC_LOW); 
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
enu_dcm_error_t DCM_u8SetDutyCycleOfPWM(Uint8_t DCM_a_dutyCycleValue)
{
	uint8_t error_state = DCM_OK;
	if (DCM_a_dutyCycleValue > MAX_DUTY_CYCLE)
	{
		error_state = DCM_WRONG;
		
	}
	else
	{
		// fixed duration based on motor freg
		PWM_set_Duty(1000,DCM_a_dutyCycleValue);
		// Call a PWM function to generate the desired pwm signal with the desired duty Cycle
	}
	return (enu_dcm_error_t)error_state;
}

/****************************************************************************************************************************************/
void DCM_updateStopFlag(void)
{
	DCM_g_stopFlag = FLAG_TRUE;
}
/****************************************************************************************************************************************you need to specify which motor you want to rotate */
enu_dcm_error_t DCM_rotateDCM(enu_dcm_motor_side_t DCM_l_motorNumber)
{
	uint8_t error_state = DCM_OK;
	if(DCM_l_motorNumber == MOTOR_RIGHT)
	{
		DCM_changeDCMDirection(str_g_carMotors, MOTOR_RIGHT);
		// High delay to see it on simulation
		// gpt asynch_delay --> TMR_intDelay_ms(620);
		//Call a PWM function to generate the desired pwm signal with the desired duty Cycle -->
 		DCM_u8SetDutyCycleOfPWM(ROTATION_DUTY_CYCLE);
	//	while(u8_g_timeOut == 0);
		// gpt_stop--> TIMER0_stop();
		//u8_g_timeOut = 0;
		//DCM_changeDCMDirection(str_g_carMotors, MOTOR_RIGHT);	
	}
	else
	{
		DCM_changeDCMDirection(str_g_carMotors, MOTOR_LEFT);
		// High delay to see it on simulation
		// gpt asynch_delay --> TMR_intDelay_ms(620);
		//Call a PWM function to generate the desired pwm signal with the desired duty Cycle -->
		DCM_u8SetDutyCycleOfPWM(ROTATION_DUTY_CYCLE);
		//while(u8_g_timeOut == 0);
		// gpt_stop--> TIMER0_stop();
		//u8_g_timeOut = 0;
		//DCM_changeDCMDirection(str_g_carMotors, MOTOR_LEFT);	
	}
	
	return (enu_dcm_error_t)error_state;
}

/****************************************************************************************************************************************/

enu_dcm_error_t DCM_MoveForward(Uint8_t u8_a_speed)
{

	uint8_t error_state = DCM_OK;
	uint8_t dcm_loc_loopCounter = FALSE;
DCM_u8SetDutyCycleOfPWM(u8_a_speed);
	for( dcm_loc_loopCounter = FALSE ; dcm_loc_loopCounter < DCM_USED_PINS_NUM; dcm_loc_loopCounter++ )
	{
		if( ( dcm_loc_loopCounter % DCM_MAX_PIN_NUM ) == FALSE)
		{
			error_state = (enu_dcm_error_t) GPIO_writeLogic( &str_g_carMotors[dcm_loc_loopCounter].gpio_for_dcm_confige, GPIO_LOGIC_HIGH); 
	
		}
		else
		{
			error_state = (enu_dcm_error_t) GPIO_writeLogic( &str_g_carMotors[dcm_loc_loopCounter].gpio_for_dcm_confige, GPIO_LOGIC_LOW); 
		}			
		
	}	
	//Call a PWM function to generate the desired pwm signal with the desired duty Cycle --> 
	
	return (enu_dcm_error_t)error_state;

}
/****************************************************************************************************************************************/

enu_dcm_error_t DCM_MoveBackward(Uint8_t u8_a_speed)
{

	uint8_t error_state = DCM_OK;
	uint8_t dcm_loc_loopCounter = FALSE;
	for( dcm_loc_loopCounter = FALSE ; dcm_loc_loopCounter < DCM_USED_PINS_NUM; dcm_loc_loopCounter++ )
	{
		if( ( dcm_loc_loopCounter % DCM_MAX_PIN_NUM ) == FALSE)
		{
			error_state = (enu_dcm_error_t) GPIO_writeLogic( &str_g_carMotors[dcm_loc_loopCounter].gpio_for_dcm_confige, GPIO_LOGIC_LOW); 
		}
		else
		{
			error_state = (enu_dcm_error_t) GPIO_writeLogic( &str_g_carMotors[dcm_loc_loopCounter].gpio_for_dcm_confige, GPIO_LOGIC_HIGH); 
		}			
		
	
	}
	//Call a PWM function to generate the desired pwm signal with the desired duty Cycle -->
	DCM_u8SetDutyCycleOfPWM(u8_a_speed);	
	return (enu_dcm_error_t)error_state;
}




