#ifndef EX_INCLUDE_TIRTOS_H
#define EX_INCLUDE_TIRTOS_H


#include <ti/devices/DeviceFamily.h>
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>
#include DeviceFamily_constructPath(driverlib/aux_adc.h)
#include "ti_drivers_config.h"


// Handle renaming between SDK releases
#ifndef Board_LED_ON
    #define Board_LED_ON    CONFIG_GPIO_LED_ON
#endif
#ifndef Board_LED_OFF
    #define Board_LED_OFF   CONFIG_GPIO_LED_OFF
#endif
#ifndef Board_UART
    #define Board_UART      CONFIG_UART_0
#endif


#endif
