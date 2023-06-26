
#include "push_button_cfg.h"

ST_PUSH_BTN_pinCfg_t a_pushBtnCfgPins[PUSH_BTN_PIN_CFG_ARRAY_SIZE] =
{
   {GPIO_PORTB , GPIO_PIN6 , GPIO_PULL_DOWN},
	 {GPIO_PORTF , GPIO_PIN4 , GPIO_PULL_UP}
};
