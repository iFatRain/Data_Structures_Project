//
// Created by Evan on 4/21/18.
//

#include "BinTree.h"

void BinTree::insert(int key,Task::FUNCTION function, node* &current){
    if(current==NULL)
    {
        current = new node(key);
    }
    else{
        if(key<(current)->x)
            insert(key,function,current->left);
        else
            insert(key,function,current->right);
    }
    return;
}

void BinTree::printTree(node *root){
    if(root!=NULL)
    {
        printTree(root->left);
        printTree(root->right);
    }
}

