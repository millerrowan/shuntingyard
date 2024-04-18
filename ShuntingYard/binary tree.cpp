#include <iostream>
#include <cstring>
#include "binarytree.h"

using namespace std; 

binarytree::binarytree(node* n) {
    left = NULL; 
    right = NULL; 
    current = n; 
    next = NULL; 
}

/* void binarytree::setRight(binarytree* nright) {
    right = nright; 
    
}

binarytree* binarytree::getRight() {
    return right; 
}

void binarytree::setLeft(binarytree* nleft) {
    left = nleft;
}

binarytree* binarytree::getLeft() {
    return left; 
}

void binarytree::setNext() {
    
} */