#include <iostream>

#include "BinTree.cpp"


int main() {
    BinTree tTree;
    node * root;
    root = NULL;
    tTree.insert(2, root);
    tTree.insert(4,root);
    tTree.insert(6, root);
    tTree.insert(25, root);
    tTree.insert(1,root);
    tTree.insert(17, root);
    tTree.printTree(root);

}