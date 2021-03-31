/*
 * lab_00_nvic.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/nvic/nvic.h"
#include "../mcal/SysCtr/SysCtr.h"
#include "../mcal/dio/dio_types.h"
#include "../mcal/PortDriver/port.h"
#include "../mcal/dio/dio.h"
#include "../mcal/mcu_hw.h"
void main(void)
{
    /***We need to estimate every step ***/
    /*TODO Write code to test Clock init driver*/
    SysCtr_init();
    /*TODO Write code to test nvic driver*/
    NVIC_init();


    while(1)
    {


    }

}



