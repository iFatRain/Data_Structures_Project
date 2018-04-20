//
//  RTOS.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "RTOS.hpp"
#include <assert.h>


RTOS:: RTOS(node * &taskList, node *init_link, int prior): node(init_link) {
    listHead = taskList;
    priority = prior;
}

RTOS:: ~RTOS(){}

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

int RTOS:: getReady() {
    return ready;
}

int RTOS::getPriority() {
    return priority;
}
//void RTOS:: startOS() {
//    while() {
//
//    }
//}
