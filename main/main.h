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
#include "RTOS.hpp"
#include "Task.hpp"
#include <string>

using namespace std;
time_t time0;
time_t time1;
long start = 0;
bool first = true;
long  heartTimeStamp = 0;
long lungTimeStamp = 0;
void timeInit();

long timerRandom;
double getStartTime();
void zeroOut();
void timeFunction(node* head_ptr);
void adjustTime(time_t &hearttime);
#endif /* main_h */


void timeInit() {
    time0 = clock();
    srand(clock());
    timerRandom = rand();
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
    long clockTime = (clock())/(CLOCKS_PER_SEC / 1000);
    long timepass = clockTime - start;
    if(clockTime - start > 3000){
        first = true;
    }
    if(first){
        timeInit();
        first = false;
        start = getStartTime();
        heartTimeStamp = 0;
        lungTimeStamp = 0;
        return;
    }
   // cout << "TIMEPASSED : "<< timepass  << endl;
    for(node *cursor = head_ptr; cursor->link() != NULL; cursor = cursor->link()) {
       //cout << timepass << endl;
        if(timepass - heartTimeStamp + timerRandom%350 > 500 &&  cursor->getPriority() > 199) {
            heartTimeStamp = timepass;
            cursor->setReady(1);
        }
        if(timepass - lungTimeStamp > 1000 &&  cursor->getPriority() > 99) {
            heartTimeStamp = timepass;
            cursor->setReady(1);
        }
    }
    return;
}


void zeroOut() {
    time1 = 0;
    time0 = 0;
    return;
}

