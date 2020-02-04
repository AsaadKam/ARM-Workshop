/*
 * lab_00_nvic.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/nvic/nvic.h"
#include "../mcal/SysCtr/SysCtr.h"


void main(void)
{
    /*TODO Write code to test Clock init driver*/
    SysCtr_init();
    /*TODO Write code to test nvic driver*/
    NVIC_init();


    while(1)
    {


    }

}



