/*
 * dio_interface.h
 *
 *  Created on: 14 Jun 2023
 *      Author: 20101
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "TM4C123.h"
#include "std_types.h"
#include "bit_math.h"
#include "gpio_config.h"
#include "gpio_private.h"

extern void callback(void);


ENU_GPIO_systemState_t GPIO_init(ST_dio_pinCfg_t  *arg_pincfg);

ENU_GPIO_systemState_t GPIO_portDeinit(ST_dio_pinCfg_t  *arg_pincfg);

ENU_GPIO_systemState_t GPIO_interruptPortEnable(ST_dio_pinCfg_t  *arg_pincfg);

ENU_GPIO_systemState_t GPIO_interruptPortDisable(ST_dio_pinCfg_t  *arg_pincfg);


ENU_GPIO_systemState_t GPIO_writeLogic(ST_dio_pinCfg_t  *arg_pincfg , ENU_GPIO_logic_t arg_logicValue);

ENU_GPIO_systemState_t GPIO_readLogic(ST_dio_pinCfg_t  *arg_pincfg , ENU_GPIO_logic_t *arg_logicValue);

ENU_GPIO_systemState_t GPIO_toggleLogic(ST_dio_pinCfg_t  *arg_pincfg);

ENU_GPIO_systemState_t GPIO_setDirection(ST_dio_pinCfg_t  *arg_pincfg , ENU_GPIO_direction_t arg_diractionValue);

ENU_GPIO_systemState_t GPIO_setPinCallbackHandelr(ST_dio_pinCfg_t  *arg_pincfg);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
