

#ifndef HANDLER_H_
#define HANDLER_H_

#include "gpt_interface.h"


typedef enum
{
	HANDLER_OK = 0,
	HANDLER_ERROR
}enu_handler_error_status_t;	

typedef enum
{
	TIMER_SYNC = 0,
	TIMER_ASYNC
}enu_timer_delay_t;


enu_handler_error_status_t HANDLER_init(str_GPT_configs_t *str_GPT_configs);
enu_handler_error_status_t HANDLER_start_timer(enu_GPT_timer_select_t enu_arg_GPT_timer_select ,enu_timer_delay_t enu_timer_delay,Uint32_t u32_arg_time,enu_time_unit_t enu_arg_time_unit);
enu_handler_error_status_t HANDLER_enable_interrupt(enu_GPT_timer_select_t enu_arg_GPT_timer_select);
enu_handler_error_status_t HANDLER_disable_interrupt(enu_GPT_timer_select_t enu_arg_GPT_timer_select);
enu_handler_error_status_t HANDLER_stop_timer(enu_GPT_timer_select_t enu_arg_GPT_timer_select);
enu_handler_error_status_t HANDLER_get_elapsed_time   (enu_GPT_timer_select_t enu_arg_GPT_timer_select , Uint32_t *u32_ptr_time);
enu_handler_error_status_t HANDLER_get_remaining_time (enu_GPT_timer_select_t enu_arg_GPT_timer_select , Uint32_t *u32_ptr_time);

#endif










