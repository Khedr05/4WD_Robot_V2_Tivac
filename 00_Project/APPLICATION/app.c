#include "app.h"

uint8_t           u8_gl_stop_or_rotate = FALSE;
boolean           bool_gl_is_timeOut   = FALSE;
boolean           bool_gl_lock_state   = FALSE;
boolean           bool_gl_idle_stop    = FALSE;
enu_car_states_t  enu_gl_car_state     = IDLE ;



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
  DCM_init(str_g_carMotors);
}
void app_start(void)
{
	
	if(enu_gl_car_state == IDLE)
	{
		if(bool_gl_idle_stop == TRUE)
		{
			 Led_stop();
			 bool_gl_idle_stop = FALSE;
		}
		else
		{
			// do nothing
		}
		read_start_btn();
	}
	else if (enu_gl_car_state == FORWARD_LONG_SIDE)
	{
		if((bool_gl_lock_state == FALSE) && (bool_gl_is_timeOut == TRUE))
		{
			car_forward_long(); 
			u8_gl_stop_or_rotate = FIRST_STOP;
			bool_gl_lock_state   = TRUE;
			bool_gl_is_timeOut   = FALSE ;
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FIRST_STOP))
		{
			car_stop();
			u8_gl_stop_or_rotate = ROTATEING;
			bool_gl_is_timeOut   = FALSE;
			
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == ROTATEING))
    {
			car_rotate();
			u8_gl_stop_or_rotate = SECOND_STOP;
			bool_gl_is_timeOut   = FALSE;
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == SECOND_STOP))
    {
			car_stop();
			u8_gl_stop_or_rotate = FALSE;
			bool_gl_is_timeOut   = FALSE;
			  
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FALSE))
    {
		  enu_gl_car_state = FORWARD_SHORT_SIDE;
			bool_gl_lock_state = FALSE;
    }
		else
		{
			// do nothing
		}
		
	}
	else if (enu_gl_car_state == FORWARD_SHORT_SIDE)
	{
		if((bool_gl_lock_state == FALSE) && (bool_gl_is_timeOut == TRUE))
		{
			car_forward_short(); 
			u8_gl_stop_or_rotate = FIRST_STOP;
			bool_gl_lock_state   = TRUE;
			bool_gl_is_timeOut   = FALSE ;
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FIRST_STOP))
		{
			car_stop();
			u8_gl_stop_or_rotate = ROTATEING;
			bool_gl_is_timeOut   = FALSE;
			
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == ROTATEING))
    {
			car_rotate();
			u8_gl_stop_or_rotate = SECOND_STOP;
			bool_gl_is_timeOut   = FALSE;
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == SECOND_STOP))
    {
			car_stop();
			u8_gl_stop_or_rotate = FALSE;
			bool_gl_is_timeOut   = FALSE;
			  
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FALSE))
    {
		  enu_gl_car_state = FORWARD_LONG_SIDE;
			bool_gl_lock_state = FALSE;
    }
		else
		{
			// do nothing
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
		// for handling debouncing
		HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_SYNC,200,TIME_IN_MILLIOSECONDS);
		
		// first stop one second after pressing start
		Led_stop();
	  HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,1,TIME_IN_SECONDS);
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
	LED_turnOn(&a_ledCfgPins[2]);
	LED_turnOn(&a_ledCfgPins[0]);
	LED_turnOn(&a_ledCfgPins[1]);
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
  DCM_MoveForward(50);
	Led_forward_long_side();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,3,TIME_IN_SECONDS);
}
void car_forward_short(void)
{
	// MOTOR MOVE FORWARD WITH 30 % SPEED FOR 2 SEC
	DCM_MoveForward(30);
	Led_forward_short_side();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,2,TIME_IN_SECONDS);
}
void car_stop(void)
{
	// STOP MOTOR 0.5 SECOND
	DCM_stopMotor(str_g_carMotors,MOTOR_RIGHT);
	DCM_stopMotor(str_g_carMotors,MOTOR_LEFT);
	Led_stop();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,500,TIME_IN_MILLIOSECONDS);
}
void car_rotate(void)
{
	// ROTATE 90 DEGREE RIGHT 
	DCM_rotateDCM(MOTOR_RIGHT);
	Led_rotate();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,620,TIME_IN_MILLIOSECONDS);
}


void stopSystem(void)
{
	car_stop();
	bool_gl_idle_stop = TRUE;
	enu_gl_car_state  = IDLE;
}






