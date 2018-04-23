
// FILE: node.h

#ifndef MAIN_CONTAINERS_H
#define MAIN_CONTAINERS_H
#include <cstdlib>  // Provides size_t
#include <iostream>


using namespace std;

class node{
    public:
    typedef int value_type;
        int x;
        node *left = NULL;
        node *right = NULL;
    
    node(int data) {
        x=data;
        left = NULL;
        right = NULL;
    }
        virtual void task();
        virtual int getReady();
        virtual int getPriority();
        virtual void setReady(int newReady);

};


    
  
    

#endif


