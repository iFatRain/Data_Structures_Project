
// FILE: node.h

#ifndef MAIN_CONTAINERS_H
#define MAIN_CONTAINERS_H
#include <cstdlib>  // Provides size_t
#include <iostream>


using namespace std;

class node {
    public:
        typedef int value_type;
        node(node* init_link = NULL) {
            link_field = init_link;
        }
        
        virtual  ~node() {}
        

        void set_link(node* new_link) {
            link_field = new_link;
        }
        
        node* link( ){
            return link_field;
        }
    
        node* link( ) const {
            return link_field;
        }

        void setLink(node *next_ptr ){
            link_field = next_ptr;
        }
        
        virtual void task() {
            return;
        }

        virtual int getReady() {
            return 0;
        }

        virtual int getPriority() {
            return 0;
        }

    protected:
        node* link_field = NULL;
};
    
  
    

#endif


