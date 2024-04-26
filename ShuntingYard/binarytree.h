#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std; 

class binarytree {
    public: 
    binarytree(node* n);
    binarytree* left; 
    binarytree* right;
    binarytree* next;
    node* current;
    
    
    
};

#endif