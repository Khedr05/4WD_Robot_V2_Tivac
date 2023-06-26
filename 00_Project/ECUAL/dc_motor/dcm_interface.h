/*
 * DCM_Interface.h
 *
 *     Created on: Jun 24, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *    Description: This file contains all Direct Current Motor (DCM) functions' prototypes and definitions (Macros) to avoid magic numbers.
 */

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

 /*******************************************************************************************************************************************************************/
 /* DCM Includes */
#include "dcm_cfg.h"

/* LIB */

#include "bit_math.h"
#include "std_types.h"

/*******************************************************************************************************************************************************************/
/* DCM Macros */
/*******************************************************************************************************************************************************************/
#define MOTORS_NUMBER                 2
#define ZERO_SPEED					  0
#define MAX_DUTY_CYCLE			      100
#define PERIOD_TIME			          10
#define ROTATION_DUTY_CYCLE           50

#define DCM_MAX_PIN_NUM				  2
#define DCM_USED_PINS_NUM			  4
/*type definition*/

typedef enum {
	DCM_OK,
	DCM_WRONG
}enu_dcm_error_t;

typedef enum {
	MOTOR_RIGHT,
	MOTOR_LEFT
}enu_dcm_motor_side_t;

typedef enum {
	FLAG_FALSE,
	FLAG_TRUE
}enu_dcm_flag_t;

/**
 * Defines the possible states for a the DCM pin.
 */
typedef enum
{
	DCM_LOW, /** Defines digital state ground */
	DCM_HIGH, /** Defines digital state power */
}enu_led_state_t;

extern str_dcm_confige_t str_g_carMotors[4];

/*******************************************************************************************************************************************************************/
/* DCM Functions' Prototypes */

enu_dcm_error_t DCM_init(str_dcm_confige_t* DCM_a_ptrToConfig);

/*******************************************************************************************************************************************************************/
enu_dcm_error_t DCM_changeDCMDirection(str_dcm_confige_t* DCM_a_ptrToConfig, enu_dcm_motor_side_t DCM_a_motorNum);
/****************************************************************************************************************************************/

enu_dcm_error_t DCM_stopMotor(str_dcm_confige_t* DCM_a_ptrToConfig, enu_dcm_motor_side_t DCM_a_motorNum);

/************************************************************************************************************************************/

enu_dcm_error_t DCM_u8SetDutyCycleOfPWM(Uint8_t DCM_a_dutyCycleValue);
/****************************************************************************************************************************************/
void DCM_updateStopFlag(void);
/****************************************************************************************************************************************/
/* you need to specify which motor you want to rotate*/
enu_dcm_error_t DCM_rotateDCM(enu_dcm_motor_side_t DCM_l_motorNumber);

/****************************************************************************************************************************************/

enu_dcm_error_t DCM_MoveForward(Uint8_t u8_a_speed);

enu_dcm_error_t DCM_MoveBackward(Uint8_t u8_a_speed);

/**************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************/

#endif /* DCM_INTERFACE_H_ */



