/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_

#include"../mcal/SysCtr/SysCtr_types.h"
#include"../utils/STD_types.h"

#define Gate_Peripheral_WD                      0
#define Gate_Peripheral_TIMER                   1
#define Gate_Peripheral_GPIO                    2
#define Gate_Peripheral_DMA                     3
#define Gate_Peripheral_HIB                     4
#define Gate_Peripheral_UART                    5
#define Gate_Peripheral_SSI                     6
#define Gate_Peripheral_I2C                     7
#define Gate_Peripheral_USB                     8
#define Gate_Peripheral_CAN                     9
#define Gate_Peripheral_ADC                     10
#define Gate_Peripheral_ACMP                    11
#define Gate_Peripheral_PWM                     12
#define Gate_Peripheral_QEI                     13
#define Gate_Peripheral_EEPROM                  14
#define Gate_Peripheral_WTIMER                  15
#define NO_OF_GATES_FOR_PHERIPHERALS            16
#define Open_All_Gates_Of_GPIO_Peripheral_Value ((uint8)(0X3F))
#define Close_Gate_Peripheral_Value             ((uint8)(0   ))


/**System Clock Source**/
#define u8_Main_Oscillator                                             0
#define u8_Precision_Internal_Oscillator                               1

/**System Clock Frequency**/
#define u8_System_Clock_66_P_67_MHz                                    2
#define u8_System_Clock_50_MHz                                         3

#define ENABLE_CONFIG_USING_RCC2                                       1
#define RCC2_USING_PHASE_LOCKED_LOOP                                   0

/*TODO implement suitable container to store the followings
 *
 * which Gate_Peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 * */
typedef struct
{
    uint8 *pu8a_Gate_Peripheral;
    uint8 u8_System_Clock_Source;
    uint8 u8_System_Clock_Frequency;
}SysCtr_cfg_t;

extern const SysCtr_cfg_t gSysCtr_cfg;

#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
