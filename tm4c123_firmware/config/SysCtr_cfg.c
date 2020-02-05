/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include"../mcal/SysCtr/SysCtr_types.h"
#include"SysCtr_cfg.h"


const uint8 au8_Opened_gates_for_peripherals[NO_OF_GATES_FOR_PHERIPHERALS]={/*Gate_Peripheral_WD*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_TIMER*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_GPIO*/Open_All_Gates_Of_GPIO_Peripheral_Value
                                                                            ,/*Gate_Peripheral_DMA*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_HIB*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_UART*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_SSI*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_I2C*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_USB*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_CAN*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_ADC*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_ACMP*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_PWM*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_QEI*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_EEPROM*/Close_Gate_Peripheral_Value
                                                                            ,/*Gate_Peripheral_WTIMER*/Close_Gate_Peripheral_Value
                                                                           };



const SysCtr_cfg_t gSysCtr_cfg={  au8_Opened_gates_for_peripherals
                                 ,u8_Main_Oscillator
                                 ,u8_System_Clock_50_MHz
                                };
