//
//  RTOS.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "RTOS.hpp"
#include <assert.h>




RTOS::node* RTOS::Scheduler(){
    base = 0;
    for(cursor =listHead; cursor->link() != NULL; cursor = cursor->link()) {
        if((cursor->getReady() == 1) && (cursor->getPriority() >= base)) {
            base = cursor->getPriority();
            taskPointer = cursor;
        }
    }
    assert(taskPointer != NULL);
    return taskPointer;
}

void RTOS:: task() {
        startTask();
    return;
}

void RTOS:: startTask() {
    node* schedule = Scheduler();
    cout << "TaskList: " << listHead << endl;
    cout <<"SCHEDULE: "<< schedule << endl;
    schedule->task();
    return;
}

//void RTOS:: startOS() {
//    while() {
//
//    }
//}
