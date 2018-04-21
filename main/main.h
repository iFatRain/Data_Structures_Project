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
#include <ctime>
#include "TimersandUpdates.hpp"
#include "RTOS.hpp"
#include "Task.hpp"

using namespace std;
clock_t time0;
clock_t time1;
clock_t hearttime;
bool first = true;
void timeInit();
double getElapsedTime();
void timeFunction(node* head_ptr);

#endif /* main_h */


void timeInit() {
    time0 = clock();
    return;
}

double getElapsedTime() {
    time1 = clock();
    double seconds =  (time1 - time0)/CLOCKS_PER_SEC;
   // time0 = time1;
    return seconds;
}

void timeFunction(node* head_ptr) {
    if(first){
        timeInit();
        first = false;
        return;
    }
    double timePassed = getElapsedTime();
    cout << "TIMEPASSED: " << timePassed << endl;
    for(node *cursor = head_ptr; cursor->link() != NULL; cursor = cursor->link()) {
        if(timePassed/10000 > .0001 &&  cursor->getPriority() > 4) {
            cursor->setReady(1);
        }
    }
    return;
}


