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
time_t time0;
time_t time1;
void timeInit();
time_t getElapsedTime();

#endif /* main_h */


void timeInit() {
    std::time(&time0);
    return;
}

time_t getElapsedTime() {
    time_t seconds =  time(NULL) - time0;
    time0 = time1;
    return seconds;
}

