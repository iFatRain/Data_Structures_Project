#include "node.hpp"

node::node(node* init_link) {
    link_field = init_link;
}

void node::set_link(node* new_link) {
    link_field = new_link;
    return;
}

node* node::link( ){
    return link_field;
}

node* node::link( ) const {
    return link_field;
}

void node::setLink(node *next_ptr ){
    link_field = next_ptr;
    return;
}

void node:: task() {
    return;
}

int node::getReady() {
    return 0;
}

int node::getPriority() {
    return 0;
}

void node::setReady(int newReady){
    return;
}



