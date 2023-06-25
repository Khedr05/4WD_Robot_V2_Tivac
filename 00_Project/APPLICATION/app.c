#include "app.h"

boolean           bool_gl_is_start   = FALSE;
boolean           bool_gl_is_timeOut = FALSE;
boolean           bool_gl_lock_state = FALSE;
enu_car_states_t  enu_gl_car_state   = IDLE ;
str_GPT_configs_t str_gl_timer       =
{
	.enu_GPT_timer_select   = GPT_TIMER0_SELECT,
	.enu_GPT_mode           = GPT_ONE_SHOT_MODE,
	.enu_GPT_type           = GPT_CONCATENATED_TYPE,
	.bool_use_interrupt     = TRUE,
	.ptrf_call_back         = timeOut
};
void app_init(void)
{
	PUSH_BTN_intialize(&a_pushBtnCfgPins[0],stopSystem);
	PUSH_BTN_intialize(&a_pushBtnCfgPins[1],PTR_NULL);
	LED_initialize(&a_ledCfgPins[0]);
	LED_initialize(&a_ledCfgPins[1]);
	LED_initialize(&a_ledCfgPins[2]);
	HANDLER_init(&str_gl_timer);
	//INIT MOTORS -->INIT PWM
}
void app_start(void)
{
	if(enu_gl_car_state == IDLE)
	{
		read_start_btn();
	}
	else if (enu_gl_car_state == FORWARD_LONG_SIDE)
	{
		if (bool_gl_is_start == FALSE)
		{
			Led_stop();
	    HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_SYNC,1,TIME_IN_SECONDS);
			bool_gl_is_start = TRUE;
		}
		else
		{
			// do nothing
		}
		if(bool_gl_lock_state == FALSE)
		{
			car_forward_long(); 
			bool_gl_lock_state = TRUE;
		}
		else if (bool_gl_is_timeOut == TRUE)
		{
			car_stop();
			car_rotate();
			car_stop();
			enu_gl_car_state = FORWARD_SHORT_SIDE;
			bool_gl_lock_state = FALSE;
			bool_gl_is_timeOut = FALSE;
		}
		else
    {
			//do nothing
    }
		
	}
	else if (enu_gl_car_state == FORWARD_SHORT_SIDE)
	{
		if(bool_gl_lock_state == FALSE)
		{
			car_forward_short(); 
			bool_gl_lock_state = TRUE;
		}
		else if (bool_gl_is_timeOut == TRUE)
		{
			car_stop();
			car_rotate();
			car_stop();
			enu_gl_car_state = FORWARD_LONG_SIDE;
			bool_gl_lock_state = FALSE;
			bool_gl_is_timeOut = FALSE;
		}
		else
    {
			//do nothing
    }
	}
	else
	{
		// do nothing
	}	
}


void timeOut(void)
{
	bool_gl_is_timeOut = TRUE;
}


void read_start_btn(void)
{
	ENU_PUSH_BTN_state_t ENU_PUSH_BTN_state = PUSH_BTN_STATE_RELEASED;
	PUSH_BTN_read_state(&a_pushBtnCfgPins[1],&ENU_PUSH_BTN_state);
	if( ENU_PUSH_BTN_state == PUSH_BTN_STATE_PRESSED)
	{
		HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_SYNC,200,TIME_IN_MILLIOSECONDS);
		enu_gl_car_state = FORWARD_LONG_SIDE;
	}
	else
	{
		//do nothing
	}
}


void Led_forward_long_side(void)
{
	LED_turnOn(&a_ledCfgPins[0]);
	LED_turnOff(&a_ledCfgPins[1]);
	LED_turnOff(&a_ledCfgPins[2]);
}
void Led_rotate(void)
{
	LED_turnOn(&a_ledCfgPins[0]);
	LED_turnOn(&a_ledCfgPins[1]);
	LED_turnOn(&a_ledCfgPins[2]);
}
void Led_stop(void)
{
	LED_turnOn(&a_ledCfgPins[2]);
	LED_turnOff(&a_ledCfgPins[0]);
	LED_turnOff(&a_ledCfgPins[1]);
}
void Led_forward_short_side(void)
{
	LED_turnOn(&a_ledCfgPins[1]);
	LED_turnOff(&a_ledCfgPins[0]);
	LED_turnOff(&a_ledCfgPins[2]);
}


void car_forward_long(void)
{
	// MOTOR MOVE FORWARD WITH 50 % SPEED FOR 3 SEC
	Led_forward_long_side();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,3,TIME_IN_SECONDS);
}
void car_forward_short(void)
{
	Led_forward_short_side();
	// MOTOR MOVE FORWARD WITH 30 % SPEED FOR 2 SEC
		HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,2,TIME_IN_SECONDS);
}
void car_stop(void)
{
	Led_stop();
	// STOP MOTOR 0.5 SECOND
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_SYNC,500,TIME_IN_MILLIOSECONDS);
}
void car_rotate(void)
{
	Led_rotate();
	// ROTATE 90 DEGREE RIGHT 
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_SYNC,3000,TIME_IN_MILLIOSECONDS);
}


void stopSystem(void)
{
	Led_stop();
	enu_gl_car_state = IDLE;
}






