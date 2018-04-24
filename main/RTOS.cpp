//
//  RTOS.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "RTOS.hpp"
#include <assert.h>


RTOS::RTOS(unsigned int TIMEDELAY,unsigned int mode, int prior): node(prior) {
    listHead = NULL;
    priority = prior;
    delay = TIMEDELAY;
    operationMode = mode;
}

RTOS:: ~RTOS(){}

void RTOS::createTask(Task::FUNCTION function, int priority){
        insertTree(priority,function,listHead);
    return;
}
void RTOS::print(){
    printTree(listHead);
}

RTOS::node* RTOS::Scheduler(){
    base = 0;
    char character = NULL;
    taskPointer = NULL;
    switch(operationMode) {
        case 0:
            for ( cursor = listHead; cursor != NULL;) {
                if (cursor->getReady() == 1) {
                    character = 'R';
                    taskPointer = cursor;
                    cursor = navigate(cursor, 'R');
                } else if (cursor->getReady() == 0) {
                    character = 'L';
                    cursor = navigate(cursor, 'L');
                }
            }
            break;
        default:
            for(;cursor != NULL; ) {
              if(cursor->right != NULL) {
                  cursor = cursor->right;
              }
              else if (cursor -> left != NULL) {
                  cursor = cursor->left;
              }
                if(cursor -> getReady() == 1) {
                    taskPointer = cursor;
                }
            }
            break;
    }
    if (taskPointer != NULL && taskPointer->getReady() == 1) {
        return taskPointer;
    }
    else {
        return NULL;
    }
}

node* RTOS::navigate(node*& pointer, char side){
    switch (side) {
        case 'R':
        case 'r':
            pointer = pointer->right;
            break;
        case 'L':
        case 'l':
            pointer = pointer->left;
            break;
        default:
            break;
    }
    return pointer;
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
    }
}

void RTOS::wait(){
    //delay is in MicroSECONDS
    usleep(delay);
    Timer(listHead);
    return;
}

void RTOS::insertTimerFunction(RTOS::FUNCTION function) {
    Timer = function;
    return;
}


