/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../utils/processor/processor.h"
#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"


extern NVIC_CfgType NVIC_CfgArr[];


void NVIC_init(void)
{

    /*TODO : switch to privilege mode - use switch function in processor.h*/
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);

    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     */
    /*Adjust how many group and subgroup */
    APINT_REG.APINT_ALL=APINT_REG_KEY|HOW_MANY_GROUP_AND_SUBGROUP<<8;

    uint8 u8_index=0;
    for(;u8_index<NVIC_NUM_OF_ENABLED_INT;u8_index++)
    {

        /*Check if Interrupt is enabled*/
        if(NVIC_CfgArr[u8_index].u8_Enable_Or_Diable==INT_Enable)
        {
            /*INTERRUPT ENABLE*/
            NVIC_EN_INT(NVIC_CfgArr[u8_index].u8_InterruptNum);
            /*Configure group and subgroup of interrupt*/
            if(HOW_MANY_GROUP_AND_SUBGROUP==EIGH_GROUP_ONE_SUBGROUP)
            {
                NVIC_SET_INT_GROUP(NVIC_CfgArr[u8_index].u8_InterruptNum,NVIC_CfgArr[u8_index].u8_Priority_Group);
            }
            else if(HOW_MANY_GROUP_AND_SUBGROUP==ONE_GROUP_EIGHT_SUBGROUP)
            {
                NVIC_SET_INT_SUBGROUP(NVIC_CfgArr[u8_index].u8_InterruptNum,NVIC_CfgArr[u8_index].u8_Sub_Priority_Group);
            }
            else if((HOW_MANY_GROUP_AND_SUBGROUP==FOUR_GROUP_TWO_SUBGROUP)||(HOW_MANY_GROUP_AND_SUBGROUP==TWO_GROUP_FOUR_SUBGROUP))
            {
                NVIC_SET_INT_GROUP(NVIC_CfgArr[u8_index].u8_InterruptNum,NVIC_CfgArr[u8_index].u8_Priority_Group);
                NVIC_SET_INT_SUBGROUP(NVIC_CfgArr[u8_index].u8_InterruptNum,NVIC_CfgArr[u8_index].u8_Sub_Priority_Group);
            }
            else
            {

            }
        }
        else
        {
            /*Do Nothing*/
        }

    }
    /*TODO : return to non-privilege mode */
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}



