#include "cpp_main.hpp"
#include <stdio.h>
#include "stm32h7xx_hal.h"

int cpp_main()
{
    while(1) {
         printf("cpp_main_run...\n");
         HAL_Delay(500);
    }
}