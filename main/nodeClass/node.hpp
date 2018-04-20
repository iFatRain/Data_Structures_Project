
// FILE: node.h

#ifndef MAIN_CONTAINERS_H
#define MAIN_CONTAINERS_H
#include <cstdlib>  // Provides size_t
#include <iostream>


using namespace std;

class node {
    public:
        typedef int value_type;
        node(node* init_link = NULL);
        virtual  ~node() {}
        void set_link(node* new_link);
        node* link();
        node* link() const;
        void setLink(node *next_ptr);
        virtual void task();
        virtual int getReady();
        virtual int getPriority();
    protected:
        node* link_field = NULL;
};
    
  
    

#endif


