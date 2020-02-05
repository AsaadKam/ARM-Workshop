/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"

#include "../mcu_hw.h"
/*TODO: include the header file that contains register definitions */

#include "dio.h"

Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Return the level value of given Channel */
    return GET_BIT(GPIO_APB(PortId).GPIODATA,ChannelPos);
}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Write the input value in the corresponding ChannelId */
    if(Level==STD_low)          CLR_BIT(GPIO_APB(PortId).GPIODATA,ChannelPos);
    else if(Level==STD_high)    SET_BIT(GPIO_APB(PortId).GPIODATA,ChannelPos);
    else
    {
        /*Do nothing*/
    }
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{

    /*TODO: Return the Port Value*/
    return GPIO_APB(PortId).GPIODATA;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /*TODO: Write the input value in the corresponding PortId */
    GPIO_APB(PortId).GPIODATA=value;
}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    /* TODO: toggle the corresponding ChannelId */
    TOGGLE_BIT(GPIO_APB(PortId).GPIODATA,ChannelPos);

}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODO: toggle the port value */

}



