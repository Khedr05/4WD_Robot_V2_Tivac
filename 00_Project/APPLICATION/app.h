#ifndef APP_H_
#define APP_H_



#include "std_types.h"
#include "led_interface.h"
#include "push_button_interface.h"
#include "htimer_interface.h"
#include "pwm_interface.h"

extern  ST_PUSH_BTN_pinCfg_t a_pushBtnCfgPins[PUSH_BTN_PIN_CFG_ARRAY_SIZE] ;
extern  ST_led_pinCfg_t a_ledCfgPins[LED_PIN_CFG_ARRAY_SIZE] ;
//include motor



#define FIRST_STOP    1
#define ROTATEING     2
#define SECOND_STOP   3
typedef enum 
{
	FORWARD_LONG_SIDE,
	FORWARD_SHORT_SIDE,
	IDLE
}enu_car_states_t;



void app_init              (void);
void app_start             (void);
void stopSystem            (void);
void timeOut               (void);
void read_start_btn        (void);
void Led_forward_long_side (void);
void Led_rotate            (void);
void Led_stop              (void);
void Led_forward_short_side(void);
void car_forward_long      (void);
void car_forward_short     (void);
void car_stop              (void);
void car_rotate            (void);



#endif




