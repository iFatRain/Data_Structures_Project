//
//  helperFunctions.cpp
//  main
//
//  Created by Michael Emperador on 4/11/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#include "helperFunctions.hpp"


void insertTree(int key,Task::FUNCTION function, node* &current){
    if(current==NULL) {
        cout << "inserting " << endl;
        current = new Task(function,key);
    }
    else{
        if(key<(current)->x) {
            cout << "inserting left" << endl;
            insertTree(key,function,current->left);
        }
        else {
            insertTree(key,function,current->right);
            cout << "inserting right" << endl;
        }
    }
    return;
}

void printTree(node *root){
    if(root!=NULL)
    {
        cout<<root->getPriority()<< endl;
        printTree(root->left);
        printTree(root->right);
    }
    return;
}

//
//void RTOS_list_head_insert(node*& taskList,node* &head_ptr, int priority) {
//    head_ptr = new RTOS(taskList,head_ptr, priority);
//    return;
//}
//
//void RTOS_list_insert(node* taskList, node* previous_ptr, int priority) {
//    node *insert_ptr = NULL;
//    insert_ptr = new RTOS(taskList, previous_ptr->link(), priority);
//    previous_ptr->set_link(insert_ptr);
//    return;
//}
//
//    void list_head_remove(node*& head_ptr) {
//        node *remove_ptr;
//        remove_ptr = head_ptr;
//        head_ptr = head_ptr->link( );
//        delete remove_ptr;
//    }
//
//    void list_remove(node* previous_ptr) {
//        node *remove_ptr;
//        remove_ptr = previous_ptr->link( );
//        previous_ptr->set_link(remove_ptr->link());
//        delete remove_ptr;
//    }
//
//    void list_clear(node*& head_ptr) {
//        while (head_ptr != NULL)
//            list_head_remove(head_ptr);
//    }
//

//node* list_findLast(node* previous_ptr) {
//    node* cursor;
//    if(previous_ptr->link() == NULL){
//        return previous_ptr;
//    }
//    for(cursor = previous_ptr; cursor->link() != NULL; cursor = cursor->link()) {
//    }
//    return cursor;
//}
////
////
////
//
//
//
