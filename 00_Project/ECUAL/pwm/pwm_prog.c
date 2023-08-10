#include "std_types.h"
#include "gpt_interface.h"
#include "pwm_interface.h"

extern str_pwm_congigs_t arr_str_gconst_pwm_configs[MAX_PWM_PINS];

boolean      bool_gl_is_init[MAX_PWM_PINS] = {FALSE};
boolean      bool_gl_is_timer_init         =  FALSE ;
boolean      bool_gl_is_high               =  TRUE;
Uint16_t     u16_gs_high_period            =  FALSE;
Uint16_t     u16_gs_low_period             =  FALSE;
static void  PWM_logic(void);
str_GPT_configs_t gl_str_GPT_config        =
 {
	 .enu_GPT_timer_select = GPT_WIDE_TIMER0_SELECT,
	 .enu_GPT_mode         = GPT_ONE_SHOT_MODE,
	 .enu_GPT_type         = GPT_INDIVIDUAL_TYPE,
	 .bool_use_interrupt   = TRUE,
	 .ptrf_call_back       = PWM_logic
};   
static void  PWM_logic(void)
{
	Uint8_t u8_loc_counter = 0 ;
	for(u8_loc_counter = 0 ; u8_loc_counter < MAX_PWM_PINS;u8_loc_counter++)
	{
		if(bool_gl_is_init[u8_loc_counter] == TRUE)
		{
			if(bool_gl_is_high == TRUE)
			{
				GPIO_writeLogic(&arr_str_gconst_pwm_configs[u8_loc_counter].str_dio_cfg, GPIO_LOGIC_LOW);
			}
			else
			{
				GPIO_writeLogic(&arr_str_gconst_pwm_configs[u8_loc_counter].str_dio_cfg, GPIO_LOGIC_HIGH);
			}
		}
		else
    {
			/*do nothing*/
    }
	}
	
	if(bool_gl_is_high == TRUE)
	{
	  GPT_start_timer(gl_str_GPT_config.enu_GPT_timer_select,u16_gs_low_period,TIME_IN_MILLIOSECONDS);
		bool_gl_is_high = FALSE;
	}
	else
	{
	  GPT_start_timer(gl_str_GPT_config.enu_GPT_timer_select,u16_gs_high_period,TIME_IN_MILLIOSECONDS);
		bool_gl_is_high = TRUE;
	}
}

	
static void pwm_init_timer(void)
{
	if(bool_gl_is_timer_init == FALSE)
	{
		GPT_init(&gl_str_GPT_config);
		bool_gl_is_timer_init = TRUE;
	}
	else
	{
		/*Do nothing*/
	}
}
enu_pwm_error_status_t PWM_init_channel(enu_pwm_channels_t enu_arg_pwm_channel)
{
	Uint8_t u8_loc_counter = 0;
	for(u8_loc_counter = 0 ; u8_loc_counter < MAX_PWM_PINS ; u8_loc_counter++)
	{
		if(arr_str_gconst_pwm_configs[u8_loc_counter].enu_pwm_channel==enu_arg_pwm_channel)
		{
			GPIO_init(&arr_str_gconst_pwm_configs[u8_loc_counter].str_dio_cfg);
			bool_gl_is_init[u8_loc_counter] = TRUE;
			break;
		}
	}
	pwm_init_timer();
	
	return PWM_OK;
}
enu_pwm_error_status_t PWM_init_all_channels(void)
{
	Uint8_t u8_loc_counter = 0;
	for(u8_loc_counter = 0 ; u8_loc_counter < MAX_PWM_PINS ; u8_loc_counter++)
	{
		
			GPIO_init(&arr_str_gconst_pwm_configs[u8_loc_counter].str_dio_cfg);
			bool_gl_is_init[u8_loc_counter] = TRUE;
	}
	pwm_init_timer();
	return PWM_OK;
}
enu_pwm_error_status_t PWM_set_Duty         (Uint16_t u16_arg_signal_duration_ms ,Uint8_t u8_arg_duty_cycle)
{
	  GPT_enable_interrupt(gl_str_GPT_config.enu_GPT_timer_select);
		u16_gs_high_period = (u16_arg_signal_duration_ms*u8_arg_duty_cycle)/100;
		u16_gs_low_period  = u16_arg_signal_duration_ms - u16_gs_high_period;
	  GPT_start_timer(gl_str_GPT_config.enu_GPT_timer_select,u16_gs_low_period,TIME_IN_MILLIOSECONDS);
	
	return PWM_OK;
}
enu_pwm_error_status_t PWM_stop(void)
{
	GPT_stop_timer(gl_str_GPT_config.enu_GPT_timer_select);
	return PWM_OK;
}






