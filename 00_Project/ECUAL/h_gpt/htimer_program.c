
#include "std_types.h"
#include "htimer_interface.h"


enu_handler_error_status_t HANDLER_init(str_GPT_configs_t *str_GPT_configs)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	enu_GPT_status_return = GPT_init(str_GPT_configs);
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		/*do nothing*/
	}
	
	return enu_handler_error_status;
}


enu_handler_error_status_t HANDLER_start_timer(enu_GPT_timer_select_t enu_arg_GPT_timer_select ,enu_timer_delay_t enu_timer_delay,Uint32_t u32_arg_time,enu_time_unit_t enu_arg_time_unit)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	if(enu_timer_delay == TIMER_SYNC)
	{
		enu_GPT_status_return = GPT_disable_interrupt(enu_arg_GPT_timer_select);
	}
	else
	{
		enu_GPT_status_return = GPT_enable_interrupt(enu_arg_GPT_timer_select);
	}
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		enu_GPT_status_return = GPT_start_timer(enu_arg_GPT_timer_select,u32_arg_time,enu_arg_time_unit);
		if(enu_GPT_status_return != GPT_OKAY)
		{
			enu_handler_error_status = HANDLER_ERROR;
		}
		else
		{
			/*do nothing*/
		}
	}
	return enu_handler_error_status;
}
enu_handler_error_status_t HANDLER_enable_interrupt(enu_GPT_timer_select_t enu_arg_GPT_timer_select)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	enu_GPT_status_return = GPT_enable_interrupt(enu_arg_GPT_timer_select);
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		/*do nothing*/
	}
	
	return enu_handler_error_status;
}
enu_handler_error_status_t HANDLER_disable_interrupt(enu_GPT_timer_select_t enu_arg_GPT_timer_select)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	enu_GPT_status_return = GPT_disable_interrupt(enu_arg_GPT_timer_select);
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		/*do nothing*/
	}
	
	return enu_handler_error_status;
}
enu_handler_error_status_t HANDLER_stop_timer(enu_GPT_timer_select_t enu_arg_GPT_timer_select)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	enu_GPT_status_return = GPT_stop_timer(enu_arg_GPT_timer_select);
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		/*do nothing*/
	}
	
	return enu_handler_error_status;
}

enu_handler_error_status_t HANDLER_get_elapsed_time(enu_GPT_timer_select_t enu_arg_GPT_timer_select , Uint32_t *u32_ptr_time)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	enu_GPT_status_return = GPT_get_elapsed_time(enu_arg_GPT_timer_select,u32_ptr_time);
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		/*do nothing */
	}
	
	return enu_handler_error_status;
}
enu_handler_error_status_t HANDLER_get_remaining_time (enu_GPT_timer_select_t enu_arg_GPT_timer_select , Uint32_t *u32_ptr_time)
{
	enu_handler_error_status_t enu_handler_error_status = HANDLER_OK;
	enu_GPT_status_t enu_GPT_status_return              = GPT_OKAY;
	enu_GPT_status_return = GPT_get_remaining_time(enu_arg_GPT_timer_select,u32_ptr_time);
	if(enu_GPT_status_return != GPT_OKAY)
	{
		enu_handler_error_status = HANDLER_ERROR;
	}
	else
	{
		//do nothing
	}
	
	return enu_handler_error_status;
}



