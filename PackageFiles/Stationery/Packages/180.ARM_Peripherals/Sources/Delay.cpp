/*
 * @file delay.cpp
 * @brief Very simple delay routine using SysTick timer
 *
 *  Created on: 5 Jul 2015
 *      Author: podonoghue
 */
#include "derivative.h"
#include "delay.h"

static unsigned timer;
static unsigned ticks;

/**
 * SysTick handler
 *
 * This routine is called approximately every millisecond
 */
void SysTick_Handler(void) {
   ticks++;
   if (timer>0) {
      timer--;
   }
}

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 */
void waitMS(unsigned msToWait) {
   // 1 ms tick
   SysTick_Config(SystemBusClock/1000);

   timer = msToWait;
   while (timer>0) {
      __WFI();
   }
}

/**
 * Very <b>approximate</b> 10us delay routine
 * This is only provided for LCD interface etc where
 * some pulses have a minimum duration
 */
void wait10us() {
   int i = SystemBusClock/1000000;
   while (i-->0) {
      __asm__("nop");
      __asm__("nop");
      __asm__("nop");
      __asm__("nop");
      __asm__("nop");
      __asm__("nop");
      __asm__("nop");
   }
}

/**
 * Get count of timer ticks
 *
 * @return ticks since arbitrary epoch
 */
unsigned getTicks() {
   return ticks;
}
