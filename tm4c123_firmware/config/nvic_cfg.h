/*
 * nvic_cfg.h
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */

#ifndef E15_ARM_REPO_CONFIG_NVIC_CFG_H_
#define E15_ARM_REPO_CONFIG_NVIC_CFG_H_

#include "../utils/Std_Types.h"

/*TODO Configure Number of Enabled Interrupts*/
#define NVIC_NUM_OF_ENABLED_INT                     5
#define EIGH_GROUP_ONE_SUBGROUP                     4
#define FOUR_GROUP_TWO_SUBGROUP                     5
#define TWO_GROUP_FOUR_SUBGROUP                     6
#define ONE_GROUP_EIGHT_SUBGROUP                    7

#define INT_Enable                                  1
#define INT_Disable                                 0
/*It is configure Pre-linked configuration**/
#define HOW_MANY_GROUP_AND_SUBGROUP                     EIGH_GROUP_ONE_SUBGROUP

#endif /* E15_ARM_REPO_CONFIG_NVIC_CFG_H_ */

