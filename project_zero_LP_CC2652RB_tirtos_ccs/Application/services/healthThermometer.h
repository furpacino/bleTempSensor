/**********************************************************************************************
 * Filename:       healthThermometer.h
 *
 * Description:    This file contains the healthThermometer service definitions and
 *                 prototypes.
 *
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *************************************************************************************************/


#ifndef _HEALTHTHERMOMETER_H_
#define _HEALTHTHERMOMETER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
* CONSTANTS
*/

// Service UUID
#define HEALTHTHERMOMETER_SERV_UUID 0x1809

//  Characteristic defines
#define HEALTHTHERMOMETER_TEMPERATUREMEASUREMENT_ID   0
#define HEALTHTHERMOMETER_TEMPERATUREMEASUREMENT_UUID 0x2A1C
#define HEALTHTHERMOMETER_TEMPERATUREMEASUREMENT_LEN  2

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * Profile Callbacks
 */

// Callback when a characteristic value has changed
typedef void (*healthThermometerChange_t)(uint16_t connHandle, uint8_t paramID, uint16_t len, uint8_t *pValue);

typedef struct
{
  healthThermometerChange_t        pfnChangeCb;  // Called when characteristic value changes
  healthThermometerChange_t        pfnCfgChangeCb;
} healthThermometerCBs_t;



/*********************************************************************
 * API FUNCTIONS
 */


/*
 * HealthThermometer_AddService- Initializes the HealthThermometer service by registering
 *          GATT attributes with the GATT server.
 *
 */
extern bStatus_t HealthThermometer_AddService( uint8_t rspTaskId);

/*
 * HealthThermometer_RegisterAppCBs - Registers the application callback function.
 *                    Only call this function once.
 *
 *    appCallbacks - pointer to application callbacks.
 */
extern bStatus_t HealthThermometer_RegisterAppCBs( healthThermometerCBs_t *appCallbacks );

/*
 * HealthThermometer_SetParameter - Set a HealthThermometer parameter.
 *
 *    param - Profile parameter ID
 *    len - length of data to right
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate
 *          data type (example: data type of uint16 will be cast to
 *          uint16 pointer).
 */
extern bStatus_t HealthThermometer_SetParameter(uint8_t param, uint16_t len, void *value);

/*
 * HealthThermometer_GetParameter - Get a HealthThermometer parameter.
 *
 *    param - Profile parameter ID
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate
 *          data type (example: data type of uint16 will be cast to
 *          uint16 pointer).
 */
extern bStatus_t HealthThermometer_GetParameter(uint8_t param, uint16_t *len, void *value);

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _HEALTHTHERMOMETER_H_ */
