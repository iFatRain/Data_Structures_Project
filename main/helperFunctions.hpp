//
//  helperFunctions.hpp
//  main
//
//  Created by Michael Emperador on 4/11/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#ifndef helperFunctions_hpp
#define helperFunctions_hpp

#include <stdio.h>
#include <assert.h>
#include "RTOS.hpp"



#endif /* helperFunctions_hpp */
typedef void (*FUNCTION )(void);


void Task_list_head_insert( node* &head_ptr,FUNCTION func,const int & init_data);
void Task_list_insert(node* previous_ptr, FUNCTION func,const node::value_type& entry);
node* list_findLast(node* previous_ptr);
void RTOS_list_head_insert(node*& taskList,node* &head_ptr, int priority);
void RTOS_list_insert(node* taskList, node* previous_ptr,int priority);
void insert ( int key ,Task::FUNCTION funct, node* &current );
void printTree(node *root);
