#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std; 

class node {
    public: 
    char data[]; 
    node* nextNode; 
    node();   
};

#endif