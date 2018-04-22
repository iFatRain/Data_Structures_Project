//
// Created by Evan on 4/21/18.
//

#ifndef BINARYTREE_BINTREE_H
#define BINARYTREE_BINTREE_H
#include "Task.hpp"
#include <iostream>

using namespace std;
/**
 *The member functions into "helperFuncions"
 *RTOS now calls these instead of the other helper functions when we create tasks.
 *
 *I also replaced the old node with your node and changed the inheritance constructors to work with yours since we
 *no longer need to store the node within them. 
 */
class BinTree{
    node *head;
    int maxheight;
    void delete_tree(node *root);
public:
    BinTree(){head=0;maxheight=-1;}
    void insert ( int key ,Task::FUNCTION funct, node* &current );
    void printTree(node *root);
};


#endif //BINARYTREE_BINTREE_H
