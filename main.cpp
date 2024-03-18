#include <iostream>
#include <cstring>
#include "node.h"

using namespace std; 

void add();
void push(char val);
char pop();
void peek();
void enqueue(char val);
void dequeue();

int main()
{
    node* first = NULL;
    node* last = NULL; 
    node* head = NULL;
    
    
    
}
//shunting yard algorithm 
void add() {
   while there are tokens to be read:
    read a token
    if the token is:
    - a number:
        put it into the output queue
    - a function:
        push it onto the operator stack 
    - an operator o1:
        while (
            there is an operator o2 at the top of the operator stack which is not a left parenthesis, 
            and (o2 has greater precedence than o1 or (o1 and o2 have the same precedence and o1 is left-associative))
        ):
            pop o2 from the operator stack into the output queue
        push o1 onto the operator stack
    - a ",":
        while the operator at the top of the operator stack is not a left parenthesis:
             pop the operator from the operator stack into the output queue
    - a left parenthesis (i.e. "("):
        push it onto the operator stack
    - a right parenthesis (i.e. ")"):
        while the operator at the top of the operator stack is not a left parenthesis:
            {assert the operator stack is not empty}
            /* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
            pop the operator from the operator stack into the output queue
        {assert there is a left parenthesis at the top of the operator stack}
        pop the left parenthesis from the operator stack and discard it
        if there is a function token at the top of the operator stack, then:
            pop the function from the operator stack into the output queue
/* After the while loop, pop the remaining items from the operator stack into the output queue. */
while there are tokens on the operator stack:
    /* If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses. */
    {assert the operator on top of the stack is not a (left) parenthesis}
    pop the operator from the operator stack onto the output queue 
    
}



//adds node into stack 
void push(char val){ 
    node* newNode = new Node(val);
    newNode->nextNode = head; 
    head = newNode; 
}
//deletes head value in the stack and moves up the next value to head 
char pop() {
    if(head == NULL) {
        return 0;    
            
    }
    node* temp = head;
    char data = head->data; 
    head = head->nextNode; 
    delete temp; 
    return data;
}
//prints out head value in the stack
void peek() {
    if(head ==  NULL) {
        return 0;        
     }
    char data = head->data;
    cout << "data: " << data << endl; 
        
}
    
    //adds a node to the end of the queue
void enqueue(char val) {
    node* newNode = new Node(); 
    //if there is nothing in the queue
    if(last == NULL) {
        first = newNode;  
        last = newNode; 
    }
    //updating current last pointer to the new last node
    last->nextNode = newNode;
    last = newNode;
        
}
void dequeue() {
    if(first == NULL) {
        cout << "there is no first" << endl;    
    }
    else {
        node* temp = first; 
        char data = first->data;  
        first = first->nextNode;  
            if(first == nullptr) {
                last = nullptr;    
                
            }
            delete temp;
        }
    }