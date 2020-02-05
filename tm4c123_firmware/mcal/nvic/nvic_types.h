/*
 * nvic_types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny#DE
 */
#include "../../utils/Std_Types.h"
#ifndef TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_

typedef struct
{
    /*TODO create types to contain Configuration parameters for each Interrupts
     * make sure the following parameters should be visible to static code
     * InterruptNum*/
      uint8 u8_InterruptNum;
     /* ENable\Disable*/
      uint8 u8_Enable_Or_Diable;
     /* Priority Group*/
      uint8 u8_Priority_Group;
     /* Sub-priority Group*/
      uint8 u8_Sub_Priority_Group;

}NVIC_CfgType;



#endif /* TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_ */
