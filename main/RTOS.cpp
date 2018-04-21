//
//  RTOS.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "RTOS.hpp"
#include <assert.h>


RTOS::RTOS(node * &taskList,Task::FUNCTION function,int prior, node *init_link): node(init_link) {
    listHead = taskList;
    priority = prior;
    Task_list_head_insert(listHead,function , prior);
}

RTOS:: RTOS(node * &taskList, node *init_link, int prior): node(init_link) {
    listHead = taskList;
    priority = prior;
}

RTOS:: ~RTOS(){}

void RTOS::createTask(Task::FUNCTION function, int priority){
    Task_list_insert(listHead, function, priority);
    return;
}

RTOS::node* RTOS::Scheduler(){
    base = 0;
    taskPointer = NULL;
    for(cursor =listHead; cursor->link() != NULL; cursor = cursor->link()) {
        if((cursor->getReady() == 1) && (cursor->getPriority() >= base)) {
            base = cursor->getPriority();
            taskPointer = cursor;
        }
    }
    
    return taskPointer;
}

void RTOS:: task() {
    startOS();
    return;
}

void RTOS:: startTask(node* taskCursor) {
    if (taskCursor != NULL) {
        taskCursor->task();
    }
    return;
}

int RTOS:: getReady() {
    return ready;
}

int RTOS::getPriority() {
    return priority;
}
void RTOS:: startOS() {
    wait();
    for(node* taskCursor = Scheduler(); taskCursor != NULL ; taskCursor = Scheduler()) {
        startTask(taskCursor);
        for(long i = 0; i < 1000000; i++) {
            for(short d = 0; d < 100; d++);
        }
    }
}

void RTOS::wait(){
    Timer(listHead);
}

void RTOS::insertTimerFunction(RTOS::FUNCTION function) {
    Timer = function;
    return;
}


