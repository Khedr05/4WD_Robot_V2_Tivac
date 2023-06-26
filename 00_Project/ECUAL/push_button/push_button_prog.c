
#include "push_button_interface.h"

ENU_PUSH_BTN_systemState_t PUSH_BTN_intialize(const ST_PUSH_BTN_pinCfg_t *btn,void (*ptrf)(void))
{
	ENU_PUSH_BTN_systemState_t error = PUSH_BTN_INIT_OK ;
	ENU_GPIO_systemState_t GPIO_RET;
	
	if(ptrf == PTR_NULL)
	{
			ST_dio_pinCfg_t dio_pinCfg = {GPIO_MODE_DIGITAL , GPIO_CUR_8MA , GPIO_DIR_INPUT , GPIO_LOGIC_DISABLED,
            btn->pushBtnConnection, GPIO_INTERRUPT_DISABLE ,
            GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
            GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL , btn->portNumber , btn->pinNumber};
			GPIO_RET = GPIO_init(&dio_pinCfg);
	}
	else
	{
		ST_dio_pinCfg_t  dio_pinCfg = {GPIO_MODE_DIGITAL , GPIO_CUR_8MA , GPIO_DIR_INPUT , GPIO_LOGIC_DISABLED,
																	 btn->pushBtnConnection, GPIO_INTERRUPT_ENABLE ,
																	 GPIO_INTERRUPT_SENSE_EDGES ,GPIO_INTERRUPT_EVENT ,
																	 GPIO_TRIGGER_LOW_EDGE_LOW_LEVEL , ptrf , btn->portNumber , btn->pinNumber};
		GPIO_RET = GPIO_init(&dio_pinCfg);
	}
           

    if (GPIO_RET == GPIO_INIT_OK)
    {
        error= PUSH_BTN_INIT_OK;
    }
    else
    {
        error= PUSH_BTN_INIT_NOK;
    }
		return error;
}
ENU_PUSH_BTN_systemState_t PUSH_BTN_read_state(const ST_PUSH_BTN_pinCfg_t *btn, ENU_PUSH_BTN_state_t *btn_state)
{
	ENU_PUSH_BTN_systemState_t error;
     ENU_GPIO_logic_t btnLogic;

    	ST_dio_pinCfg_t  dio_pinCfg =
           {GPIO_MODE_DIGITAL , GPIO_CUR_8MA , GPIO_DIR_INPUT , GPIO_LOGIC_DISABLED,
            btn->pushBtnConnection, GPIO_INTERRUPT_DISABLE ,
            GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
            GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL , btn->portNumber , btn->pinNumber};


    GPIO_readLogic( &dio_pinCfg , &btnLogic);

    if (btn->pushBtnConnection == GPIO_PULL_UP)
    {
        if (btnLogic == GPIO_LOGIC_HIGH)
        {
            *btn_state = PUSH_BTN_STATE_RELEASED;
        }
        else
        {
            *btn_state = PUSH_BTN_STATE_PRESSED;
        }
    }
    else if (btn->pushBtnConnection == GPIO_PULL_DOWN)
    {
        if (btnLogic == GPIO_LOGIC_LOW)
        {
            *btn_state = PUSH_BTN_STATE_PRESSED;
        }
        else
        {
            *btn_state = PUSH_BTN_STATE_RELEASED;
        }
    }
    else
    {
        error= PUSH_BTN_NULL_PTR;  // Return error for invalid connection type
    }

    error= PUSH_BTN_READ_OK;  // Return success
		return error;
}






