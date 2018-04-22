//
// Created by Evan on 4/21/18.
//

#ifndef BINARYTREE_BINTREE_H
#define BINARYTREE_BINTREE_H

#include <iostream>

using namespace std;

class node{

public:
    int x;
    node *left;
    node *right;
    node(int data)
    {
        x=data;
        left = NULL;
        right = NULL;
    }

};

class BinTree{
    node *head;
    int maxheight;
    void delete_tree(node *root);
public:
    BinTree(){head=0;maxheight=-1;}
    void insert ( int key , node* &current );
    void printTree(node *root);
};


#endif //BINARYTREE_BINTREE_H
