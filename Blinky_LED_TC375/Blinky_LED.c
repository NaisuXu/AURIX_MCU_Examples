/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort.h"
#include "Bsp.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

//#define LED                  &MODULE_P00,5                                   /* LED: Port, Pin definition            */
#define LED_PORT             MODULE_P00
#define LED_PIN              5
#define LED_PORT_MODE        IfxPort_Mode_outputPushPullGeneral
#define LED_PORT_PAD_DRIVER  IfxPort_PadDriver_cmosAutomotiveSpeed2

#define WAIT_TIME            500                                             /* Wait time constant in milliseconds   */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

/* This function initializes the port pin which drives the LED */
void initLED(void)
{
//    IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinMode(&LED_PORT, LED_PIN, LED_PORT_MODE);
    IfxPort_setPinPadDriver(&LED_PORT, LED_PIN, LED_PORT_PAD_DRIVER);

//    IfxPort_setPinHigh(LED);
    IfxPort_setPinState(&LED_PORT, LED_PIN, IfxPort_State_high);
}

/* This function toggles the port pin and wait 500 milliseconds */
void blinkLED(void)
{
//    IfxPort_togglePin(LED);                                                   /* Toggle the state of the LED      */
    IfxPort_setPinState(&LED_PORT, LED_PIN, IfxPort_State_toggled);

    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    /* Wait 500 milliseconds            */
}
