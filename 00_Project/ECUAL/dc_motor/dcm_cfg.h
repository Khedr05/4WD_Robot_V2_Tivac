/*
 * DCM_cfg.h
 *
 *     Created on: Jun 25, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *    Description: This file contains all Direct Current Motor (DCM) functions' prototypes and definitions (Macros) to avoid magic numbers.
 */

#ifndef DCM_CFG_H_
#define DCM_CFG_H_



 /*******************************************************************************************************************************************************************/
 /* DCM Includes */
/*******************************************************************************************************************************************************************/
#include "std_types.h"
#include "gpio_config.h" /* For this modules definitions */
/*******************************************************************************************************************************************************************/



typedef struct ST_DCM_g_Config_t {
	Uint8_t DCM_g_motEnPinNumber0;
	Uint8_t DCM_g_motEnPinNumber1;
	Uint8_t DCM_g_motEnPortNumber;
}ST_DCM_g_Config_t;

/**
 * Defines an enumerated list of the DCM_PINs.
 * The last element is used to specify the maximum number of
 * enumerated labels.
 */
typedef enum LED_ID {
	DCM0_PIN_0 = 0,
	DCM0_PIN_1,
	DCM1_PIN_0,
	DCM1_PIN_1
}enu_dcm_pin_id_t;

/**
 * Defines the DCM configuration table's elements that are used
 * by DCM_Init to configure the DC_Motors.
 */
typedef struct dcm {
	ST_dio_pinCfg_t 	 gpio_for_dcm_confige;
	enu_dcm_pin_id_t	 dcm_pin_id;
}str_dcm_confige_t;

#endif /* DCM_CFG_H_ */







