//
//  Task.hpp
//  List
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp
#include <string>
#include <stdio.h>
#include "node.hpp"

class Task : public node {
public:
    typedef void (*FUNCTION )(void);
    typedef int value_type;
    Task(FUNCTION func,const value_type& init_data = value_type(), node* init_link = NULL);
    ~Task();
    virtual void task();
    int getPriority();
    int getReady();
    void setReady(int newReady);

private:
    FUNCTION state;
    int Priority;
    int Ready = 1;
};

// FUNCTIONS for the linked list toolkit

//void list_head_insert( node* &head_ptr,Task::FUNCTION func,const int & init_data = int( ));
//void list_insert(node* previous_ptr, Task::FUNCTION func,const node::value_type& entry);
//node* list_findLast(node* previous_ptr);
#endif /* Task_hpp */


