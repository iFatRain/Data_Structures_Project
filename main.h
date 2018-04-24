//
//  main.h
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#ifndef main_h
#define main_h
#include <stdlib.h>
#include <iostream>
#include "TimersandUpdates.hpp"
#include "helperFunctions.hpp"
#include "voidFuctionLibrary.hpp"
#include "RTOS.hpp"
#include "Task.hpp"
#include "hashtable.h"
#include <string>
#include <limits.h>
/**
 * FIRST: All Functions on this page are needed for the Timers.
 * the one That needs to be changed in particular is time function
 * It needs another type of mechanism to visit all of the nodes
 *
 * NEXT GOAL: to move these files into the TimersandUpdates page.
 * I got errors (LINKER) for some reason when I tried maybe you can figure it out.
 *
 * LAST GOAL:
 * ADD INTERVAL time to the rtos that will lengthen the amount of time in between
 * calls to consult all the timers. THIS TIME SHOULD BE LESS THAN THE LOWEST TIMER INTERVAL
 */
using namespace std;
time_t time0;
time_t time1;
long timepass;
long start = 0;
bool first = true;
long  heartTimeStamp = 0;
long lungTimeStamp = 0;
void timeInit();

long timerRandom;
double getStartTime();
void zeroOut();
void timeFunction(node* head_ptr);
void traverse(node* &root);
void adjustTime(time_t &hearttime);
#endif /* main_h */


void timeInit() {
    time0 = clock();
    srand(clock());
    return;
}

double getStartTime() {
    clock_t milliseconds =  (clock())/(CLOCKS_PER_SEC/ 1000);
    if(milliseconds > LONG_MAX){
        zeroOut();
    }
    return milliseconds;
}

void timeFunction(node* head_ptr) {
    long clockTime = (clock()) / (CLOCKS_PER_SEC / 1000);
    timepass = clockTime - start;
    if (clockTime - start > 3000) {
        first = true;
    }
    if (first) {
        timeInit();
        first = false;
        start = getStartTime();
        heartTimeStamp = 0;
        lungTimeStamp = 0;
        return;
    }

    traverse(head_ptr);
    // cout << "TIMEPASSED : "<< timepass  << endl;
//    for(node *cursor = head_ptr; cursor->link() != NULL; cursor = cursor->link()) {
//       //cout << timepass << endl;
//       if(timepass - heartTimeStamp + timerRandom%350 > 500 &&  cursor->getPriority() > 199) {
//            heartTimeStamp = timepass;
//            cursor->setReady(1);
//        }
//        if(timepass - lungTimeStamp > 1000 &&  cursor->getPriority() > 99) {
//            heartTimeStamp = timepass;
//            cursor->setReady(1);
//        }
//    }
    return;
}
// called whe you need to traverse through all the nodes. I took the same if statemnets from the old traversal when it
// was only node class.
void  traverse(node* &root) {
    if(root!=NULL)
    {
        //root->setReady(1);
        //cout << root->getPriority() << endl;
        if(timepass - heartTimeStamp   > 500 &&  root->getPriority() > 199  ) {
            heartTimeStamp = timepass;
            root->setReady(1);
        }
        if(timepass - lungTimeStamp> 1000 && root->getPriority() > 99 && root-> getPriority() < 200) {
           lungTimeStamp = timepass;
            root->setReady(1);
        }

        traverse(root->left);
        traverse(root->right);

    }

    return ;
}


void zeroOut() {
    time1 = 0;
    time0 = 0;
    return;
}