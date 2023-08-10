/*
 * DCM_private.h
 *
 *     Created on: Jun 25, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) pre-build configurations, through which user can configure before using the DCM peripheral.
 */


#ifndef DCM_PRIVATE_H_
#define DCM_PRIVATE_H_

 /*******************************************************************************************************************************************************************/
 /* DCM Macros */
 /*******************************************************************************************************************************************************************/

  /********************* Motor_0 Configurations ***********************/
#define	    MOT0_EN_PIN_NUMBER_0	  2
#define		MOT0_EN_PIN_NUMBER_1	  3	
#define		MOT0_PWM_PIN_NUMBER		  0
#define		MOT0_EN_PORT_NUMBER		  GPIO_PORTA 
#define		MOT0_PWM_PORT_NUMBER	  GPIO_PORTA 
 /********************* Motor_1 Configurations ***********************/
#define	    MOT1_EN_PIN_NUMBER_0	  6
#define		MOT1_EN_PIN_NUMBER_1	  7
#define		MOT1_PWM_PIN_NUMBER		  1
#define		MOT1_EN_PORT_NUMBER		  GPIO_PORTA 
#define		MOT1_PWM_PORT_NUMBER	  GPIO_PORTA 

/* End of Configurations */

/*******************************************************************************************************************************************************************/

#endif /* DCM_PRIVATE_H_ */


