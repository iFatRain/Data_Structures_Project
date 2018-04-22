//
// Created by Evan on 4/21/18.
//

#include "BinTree.h"

void BinTree::insert(int key,node* &current){
    if(current==NULL)
    {
        current = new node(key);
    }
    else{
        if(key<(current)->x)
            insert(key,current->left);
        else
            insert(key,current->right);
    }
    return;
}

void BinTree::printTree(node *root){
    if(root!=NULL)
    {
        cout<<root->x<<" ";
        printTree(root->left);
        printTree(root->right);
    }
}