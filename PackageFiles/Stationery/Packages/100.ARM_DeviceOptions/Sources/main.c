/*
 ============================================================================
 * @file main.c (100.ARM_DeviceOptions/main.c)
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */

#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "delay.h"

int main(void) {

   volatile int count = 0;

//   printf("SystemBusClock  = %ld\n", SystemBusClock);
//   printf("SystemCoreClock = %ld\n", SystemCoreClock);

   // Real programs never die!
   for(;;) {
      count++;
//      printf("Count = %d\n", count);
      waitMS(100);
   }
   return 0;
}
