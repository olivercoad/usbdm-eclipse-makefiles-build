/**
 * @file queue.h (180.ARM_Peripherals/Project_Headers/queue.h)
 *
 *  Created on: 12Nov.,2016
 *      Author: podonoghue
 */

#ifndef PROJECT_HEADERS_QUEUE_H_
#define PROJECT_HEADERS_QUEUE_H_

#include "system.h"

/**
 * Simple queue implementation
 *
 * @tparam T          Type of queue items
 * @tparam QUEUE_SIZE Size of queue
 */
template<class T, int QUEUE_SIZE>
class Queue {
   T        fBuff[QUEUE_SIZE];
   T        *fHead, *fTail;
   int      fNumberOfElements;
//   uint32_t fLock;

public:
   /*
    * Create empty Queue
    */
   Queue() : fHead(fBuff), fTail(fBuff), fNumberOfElements(0) {
   }

   /**
    * Clear queue i.e. make empty
    */
   void clear() {
//      lock(&fLock);
      fHead             = fBuff;
      fTail             = fBuff;
      fNumberOfElements = 0;
//      unlock(&fLock);
   }
   /*
    * Check if empty
    *
    * @return true => empty
    */
   bool isEmpty() {
      return fNumberOfElements == 0;
   }
   /*
    * Check if full
    *
    * @return true => full
    */
   bool isFull() {
      return fNumberOfElements == QUEUE_SIZE;
   }
   /*
    * Add element to queue
    *
    * @param[in]  element Element to add
    */
   void enQueue(T element) {
      bool success = enQueueDiscardOnFull(element);
      (void)success;
      usbdm_assert(success, "Queue full");
   }
   /*
    * Add element to queue. Discards on full.
    *
    * @param[in]  element Element to add
    *
    * @return true  => Element enqueued
    * @return false => Queue full, element not added
    */
   bool enQueueDiscardOnFull(T element) {
//      lock(&fLock);
      bool hasSpace = !isFull();
      if (hasSpace) {
         *fTail++ = element;
         fNumberOfElements++;
         if (fTail>=(fBuff+QUEUE_SIZE)) {
            fTail = fBuff;
         }
      }
//      unlock(&fLock);
      return hasSpace;
   }
   /*
    * Remove & return element from queue
    *
    * @param[in]  element Element to add
    */
   T deQueue() {
//      lock(&fLock);
      usbdm_assert(!isEmpty(), "Queue empty");
      uint8_t t = *fHead++;
      fNumberOfElements--;
      if (fHead>=(fBuff+QUEUE_SIZE)) {
         fHead = fBuff;
      }
//      unlock(&fLock);
      return t;
   }

};

#endif /* PROJECT_HEADERS_QUEUE_H_ */
