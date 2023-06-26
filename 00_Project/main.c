
#include "app.h"
//#include "gpio_interface.h"
//#include "pwm_interface.h"

extern ST_dio_pinCfg_t a_cfgPins[PINS_CFG_ARRAY_SIZE];
int main()
{
	//PWM_init_all_channels();
	//PWM_set_Duty(1000,30);
	app_init();
	  /*GPIO_init(&a_cfgPins[6]);
		GPIO_init(&a_cfgPins[0]);
	GPIO_init(&a_cfgPins[1]);
		GPIO_init(&a_cfgPins[2]);
	   GPIO_init(&a_cfgPins[3]);
*/	while(1)
	{
		app_start();
	}
		
}



