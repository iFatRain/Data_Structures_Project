//
//  RTOS.cpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "RTOS.hpp"
#include <assert.h>


RTOS::RTOS(Task::FUNCTION function,int prior, node *init_link): node(prior) {
    listHead = NULL;
    priority = prior;
    cout <<endl<< "CREATED" << endl;
    insertTree(prior,function,listHead);
}

RTOS:: ~RTOS(){}

void RTOS::createTask(Task::FUNCTION function, int priority){
    cout << "INSERTED" << endl;
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
        for(cursor = listHead; cursor != NULL ;){
            if(cursor->getReady() == 1 ) {
                character = 'R';
                taskPointer = cursor;
                cursor = navigate(cursor,'R');
            }
            else if(cursor->getReady() == 0) {
                character = 'L';
                cursor = navigate(cursor,'L');
            }
        }
    if (taskPointer != NULL && taskPointer-> getReady() == 1) {
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
        cout << counter++ <<" "<< endl;
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


