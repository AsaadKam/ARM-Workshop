
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6
#include "../../utils/processor/processor.h"
#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};
void PORT_init(void)
{
    uint8 CfgArrIndex;
    Port_IdType PortId;
    Port_ChIdType ChannelId;
    uint8 ChannelPosInPort;
    volatile PORT_RegType* BaseAddr;


    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {

        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;

        /*get PORTId using ChannelId*/
        PortId = ChannelId / MAX_NUM_OF_CH_IN_PORT;

        /*get baseAddress using PortId*/
        BaseAddr = BaseAddrArr[PortId];

        /*get Channel Position in PortGroup using ChannelId */
        ChannelPosInPort = ChannelId / MAX_NUM_OF_CH_IN_PORT;

        /*NOTE use channel position in Group to write in corresponding bit in Desired Register */
        if( (PortId==Port_Id_C )&&( ChannelId<=Port_Channel_C3))
        {

            GPIO_APB(PortId).GPIOLOCK=GPIO_COMMIT_LOCK;
            GPIO_APB(PortId).GPIOCR|=ChannelId;

        }
        else if( (PortId==Port_Id_D) &&( ChannelId==Port_Channel_D7))
        {

            GPIO_APB(PortId).GPIOLOCK=GPIO_COMMIT_LOCK;
            GPIO_APB(PortId).GPIOCR|=ChannelId;

        }
        else if(  (PortId==Port_Id_F) &&( ChannelId==Port_Channel_F0))
        {

            GPIO_APB(PortId).GPIOLOCK=GPIO_COMMIT_LOCK;
            GPIO_APB(PortId).GPIOCR|=ChannelId;

        }
        else
        {
            /*Do nothing*/
        }
        /*TODO: set channel direction */
        if(PortCfgArr[CfgArrIndex].Dir==port_Dir_Input)
        {
            CLR_BIT(GPIO_APB(PortId).GPIODIR,ChannelId);
        }
        else if(PortCfgArr[CfgArrIndex].Dir==port_Dir_Output)
        {
            SET_BIT(GPIO_APB(PortId).GPIODIR,ChannelId);
        }
        else
        {
            /*Do nothing*/
        }
        /*TODO: set channel mode */

        if(PortCfgArr[CfgArrIndex].Mode==PORT_MODE_PIN_X_DIO)
        {
            CLR_BIT(GPIO_APB(PortId).GPIOAFSEL,ChannelId);
        }
        else if((PortCfgArr[CfgArrIndex].Mode!=PORT_MODE_PIN_X_DIO) &&(PortCfgArr[CfgArrIndex].Mode<PORT_NO_MODE_POSSIBLITY))
        {
            SET_BIT(GPIO_APB(PortId).GPIOAFSEL,ChannelId);
            GPIO_APB(PortId).GPIOPCTL|=PortCfgArr[CfgArrIndex].Mode;
        }
        else
        {
            /*Do nothing*/
        }
        /*TODO: set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {

        }
        else
        {


        }

        /*TODO: set Internal Attachment configuration */


        /*TODO: set current strength configuration */


        /*Check if analog functionality is required*/
        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
        {
            /*TODO: enable digital and disable ADC  */


        }
        else
        {
            /*TODO: disable digital and enable ADC */

        }
    }

}
