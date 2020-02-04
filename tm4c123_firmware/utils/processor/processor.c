/*
 * processor.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "processor.h"

 PROCESSOR_ModeType  gPROCESSOR_ModeType_Mode_Buffer;

void PROCESSOR_enableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_disableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{

     gPROCESSOR_ModeType_Mode_Buffer=Mode;
    /* TODO use Svc assembly instruction to switch to handler mode*/
    __asm("    SVC #1   \n");
}

/*TODO: Put the following function address in Vector table */
void PROCESSOR_SvcHandler(void)
{
    /*TODO use TMPL bit field in CONTROL Register to switch between
     * privilege and non-privilege modes.See page(88) */

     if(gPROCESSOR_ModeType_Mode_Buffer==PROCESSOR_ModePrivilege)
    {
        __asm("    MOV   R0,#0\n");
    }
    else if(gPROCESSOR_ModeType_Mode_Buffer==PROCESSOR_ModeNonPrivilege)
    {
        __asm("    MOV   R0,#1\n");
    }
    else
    {

    }
    __asm("    MSR   CONTROL,R0  \n");

}

