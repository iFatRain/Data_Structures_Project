//
//  RTOS.hpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#ifndef RTOS_hpp
#define RTOS_hpp
#include <stdio.h>
#include "Task.hpp"
#include "helperFunctions.hpp"
#include <cassert>

class RTOS : public node {
    
    public:
        RTOS(node * &taskList, node *init_link = NULL, int prior = 0);
        RTOS(node * &taskList,Task::FUNCTION function,int prior = 0, node *init_link = NULL);
        node* Scheduler();
        void wait();
        void startTask(node* taskCursor);
        void task();
        void startOS();
        void createTask(Task::FUNCTION function, int priority = 0);
        int getReady();
        int getPriority();
        void insertTimerFunction(Task::FUNCTION function);
        ~RTOS();
    
    private:
        node *listHead;
        node *cursor;
        node *taskPointer;
        int base;
        int priority;
        int ready = 1;
        Task::FUNCTION Timer;
        
};
#endif /* RTOS_hpp */
