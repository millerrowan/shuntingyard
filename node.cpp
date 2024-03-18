#include <iostream>
#include <cstring>
#include "node.h"

using namespace std; 

node::node(char value) {
    nextNode = nullptr;    
    data = value;    
}