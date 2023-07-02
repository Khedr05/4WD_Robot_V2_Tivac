
#include "app.h"

uint8_t           u8_gl_stop_or_rotate = FALSE;
boolean           bool_gl_is_timeOut   = FALSE;
boolean           bool_gl_lock_state   = FALSE;
boolean           bool_gl_idle_stop    = FALSE;
enu_car_states_t  enu_gl_car_state     = IDLE ;



str_GPT_configs_t str_gl_timer       =
{
	.enu_GPT_timer_select   = GPT_WIDE_TIMER1_SELECT,
	.enu_GPT_mode           = GPT_ONE_SHOT_MODE,
	.enu_GPT_type           = GPT_INDIVIDUAL_TYPE,
	.bool_use_interrupt     = TRUE,
	.ptrf_call_back         = timeOut
};

void app_init(void)
{
	(void)PUSH_BTN_intialize(&a_pushBtnCfgPins[STOP_BTN_INDX],stopSystem);
	(void)PUSH_BTN_intialize(&a_pushBtnCfgPins[START_BTN_INDX],PTR_NULL);
	(void)LED_initialize    (&a_ledCfgPins[LONG_SIDE_INDX]);
	(void)LED_initialize    (&a_ledCfgPins[SHORT_SIDE_INDX]);
	(void)LED_initialize    (&a_ledCfgPins[STOP_LED_INDX]);
	(void)HANDLER_init      (&str_gl_timer);
  (void)DCM_init          (str_g_carMotors);
}

/* call this function in super loop*/
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
			/* do nothing*/
		}
		
		read_start_btn();
	}
	else if (enu_gl_car_state == FORWARD_LONG_SIDE)
	{
		if((bool_gl_lock_state == FALSE) && (bool_gl_is_timeOut == TRUE))
		{ 
			u8_gl_stop_or_rotate = FIRST_STOP;
			bool_gl_lock_state   = TRUE;
			bool_gl_is_timeOut   = FALSE ;
			car_forward_long();
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FIRST_STOP))
		{
			u8_gl_stop_or_rotate = ROTATEING;
			bool_gl_is_timeOut   = FALSE;
			car_stop();			
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == ROTATEING))
    {
			u8_gl_stop_or_rotate = SECOND_STOP;
			bool_gl_is_timeOut   = FALSE;
			car_rotate();
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == SECOND_STOP))
    {
			u8_gl_stop_or_rotate = FALSE;
			bool_gl_is_timeOut   = FALSE;
			car_stop();  
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FALSE))
    {
		  enu_gl_car_state = FORWARD_SHORT_SIDE;
			bool_gl_lock_state = FALSE;
    }
		else
		{
			/* do nothing*/
		}
		
	}
	else if (enu_gl_car_state == FORWARD_SHORT_SIDE)
	{
		if((bool_gl_lock_state == FALSE) && (bool_gl_is_timeOut == TRUE))
		{
			u8_gl_stop_or_rotate = FIRST_STOP;
			bool_gl_lock_state   = TRUE;
			bool_gl_is_timeOut   = FALSE;
			car_forward_short(); 
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FIRST_STOP))
		{
			u8_gl_stop_or_rotate = ROTATEING;
			bool_gl_is_timeOut   = FALSE;
			car_stop();
		}
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == ROTATEING))
    {
			u8_gl_stop_or_rotate = SECOND_STOP;
			bool_gl_is_timeOut   = FALSE;
			car_rotate();
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == SECOND_STOP))
    {
			u8_gl_stop_or_rotate = FALSE;
			bool_gl_is_timeOut   = FALSE;
			car_stop();
    }
		else if ((bool_gl_is_timeOut == TRUE) && (u8_gl_stop_or_rotate == FALSE))
    {
		  enu_gl_car_state = FORWARD_LONG_SIDE;
			bool_gl_lock_state = FALSE;
    }
		else
		{
			/* do nothing*/
		}
	}
	else
	{
		/* do nothing*/
	}	
	
}


void timeOut(void)
{
	bool_gl_is_timeOut = TRUE;
}


void read_start_btn(void)
{
	ENU_PUSH_BTN_state_t ENU_PUSH_BTN_state = PUSH_BTN_STATE_RELEASED;
	PUSH_BTN_read_state(&a_pushBtnCfgPins[START_BTN_INDX],&ENU_PUSH_BTN_state);
	if( ENU_PUSH_BTN_state == PUSH_BTN_STATE_PRESSED)
	{
		// for handling debouncing
		HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_SYNC,DEBOUNCING_DELAY,TIME_IN_MILLIOSECONDS);
		
		// first stop one second after pressing start
		Led_stop();
		bool_gl_is_timeOut   = FALSE;
	  HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,ONE_SECOND,TIME_IN_SECONDS);
		enu_gl_car_state = FORWARD_LONG_SIDE;
	}
	else
	{
		//do nothing
	}
}


void Led_forward_long_side(void)
{
	LED_turnOff(&a_ledCfgPins[STOP_LED_INDX]);
	LED_turnOff(&a_ledCfgPins[SHORT_SIDE_INDX]);
	/* TURN ON LONG SIDE LED*/
	LED_turnOn(&a_ledCfgPins[LONG_SIDE_INDX]);
}
void Led_rotate(void)
{
	/* TURN ON RGB LED FOR ROTATION*/
	LED_turnOn(&a_ledCfgPins[STOP_LED_INDX]);
	LED_turnOn(&a_ledCfgPins[LONG_SIDE_INDX]);
	LED_turnOn(&a_ledCfgPins[SHORT_SIDE_INDX]);
}
void Led_stop(void)
{
	LED_turnOff(&a_ledCfgPins[LONG_SIDE_INDX]);
	LED_turnOff(&a_ledCfgPins[SHORT_SIDE_INDX]);
	/* TURN ON STOP LED*/
	LED_turnOn(&a_ledCfgPins[STOP_LED_INDX]);
}
void Led_forward_short_side(void)
{
	LED_turnOff(&a_ledCfgPins[LONG_SIDE_INDX]);
	LED_turnOff(&a_ledCfgPins[STOP_LED_INDX]);
	/* TURN ON SHORT SIDE LED*/
	LED_turnOn(&a_ledCfgPins[SHORT_SIDE_INDX]);
}


void car_forward_long(void)
{
	// MOTOR MOVE FORWARD WITH 50 % SPEED FOR 3 SEC
  DCM_MoveForward(SPEED_50);
	Led_forward_long_side();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,THREE_SECONDS,TIME_IN_SECONDS);
}
void car_forward_short(void)
{
	// MOTOR MOVE FORWARD WITH 30 % SPEED FOR 2 SEC
	DCM_MoveForward(SPEED_30);
	Led_forward_short_side();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,TWO_SECONDS,TIME_IN_SECONDS);
}
void car_stop(void)
{
	// STOP MOTOR 0.5 SECOND
	DCM_stopMotor(str_g_carMotors,MOTOR_RIGHT);
	DCM_stopMotor(str_g_carMotors,MOTOR_LEFT);
	Led_stop();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,HALF_SECOND,TIME_IN_MILLIOSECONDS);
}
void car_rotate(void)
{
	// ROTATE 90 DEGREE RIGHT 
	DCM_rotateDCM(MOTOR_LEFT);
	Led_rotate();
	HANDLER_start_timer(str_gl_timer.enu_GPT_timer_select,TIMER_ASYNC,ONE_SECOND,TIME_IN_SECONDS);
}


void stopSystem(void)
{
	car_stop();
	bool_gl_idle_stop  = TRUE;
	bool_gl_lock_state = FALSE;
	bool_gl_is_timeOut = FALSE;
	enu_gl_car_state   = IDLE;
}






