#include <iostream>
#include <cstring>
#include "node.h"
#include "binarytree.h"

using namespace std; 

void add(node* head, node* first, node* last);
void push(char val, node* head);
char pop(node* head);
void peek();
void enqueue(char valn node* first, node* last);
void dequeue(node* first, node* last);
void pushBT(binarytree* bthead, node* current);
void popBT(binarytree* bthead); 
void printPost();
void printPre();
void printIn(); 

int main()
{
    node* first = NULL;
    node* last = NULL; 
    node* head = NULL;
    
    char equation[50]; 
    cout << "enter an equation" << endl;
    cin >> equation; 
    
    add(head, first, last);
    
    
}
//shunting yard algorithm 
void add(node* head, node* first, node* last) {
   for(int i = 0; i<strlen(equation); i++) {
       if(isdigit(equation[i])) {
           enqueue(equation[i], first, last); 
           
       }
       //if its an operator
       else if(equation[i] = '+' || equation[i] = '-' || equation[i] = '*' || equation[i] = '/' || equation[i] = '^') {
             while (head != NULL && head != data != '(') {
                if(precedence(head->data) >= precedence(equation[i])) {
                    node* popcorn = pop(head); 
                    enqueue(val, first, popcorn); 
                     
                }
                
                else{
                    break;    
                }
                push(equation[i], head);
                
                }
            //if the operator is not a left parenthesis
            if(equation[i] != '(') {
               node* popcorn = pop(head);
               enqueue(val, first, popcorn); 

            }
            //if operatior is a right parenthesis
            else if(equation[i] == '(') {
                push(equation[i], head);
                
            }
            //if operator is a left parenthesis
            else if(equation[i] == ')') {
                while(head->data != '(') {
                    if(head == NULL) {
                        break; 
                        return; 
                    }
                    else { 
                    node* popcorn = pop(head);
                    enqueue(val, first, popcorn);
                    
                    }
                    
                }
                if(head == NULL) {
                    cout << "there are not matching parenthesis" << endl; 
                    break;
                     
                }
                else if(head->data == '(') {
                    node* pop = pop(head);
                    delete pop; 
                    
                }
                
            }
       }
               
       
       while(head != NULL) {
           if (head->data == '(' || head->data == ')') {
               cout << "mismatched paranthetis" << endl;
               break;
           }
           else {
               node* popped = pop(head);
               enqueue(val, first, popcorn);
               if(head == NULL) {
                   break;
                   return; 
                   
               }
           }
           
           
       }
       
       }
       
   }
   
   
}


void addToBT(node* &first, binarytree* &head) {
    //if the queue is empty
    while(first == NULL) {
        //creates new binary tree
        binarytree* newBT = new binarytree(first); 
        //if its a number push to stack
        if(isdigit(first->data)) {
          pushBT(bthead, first); 
          dequeue(first);
       }
        //if its an operator
        else {
            binarytree* right = popBT(bthead);
            binarytree* left = popBT(bthead);
            newtree->right = right; 
            newtree->left = left;
            pushBT(bthead, )
            
        }
    
    }
}

void pushBT(binarytree* &bthead, node* n) { //resume here
   // binarytree*  = 
   newBT->next = bthead;
   bthead = newBT; 
}

binarytree* popBT(binarytree* &bthead) {
    if(bthead == NULL) {
        return NULL;
    }
    binarytree* temp = bthead;
    node* current = bthead->current; 
    bthead = bthead->next; 
    delete temp; 
    return current; 
    
}

//adds node into stack 
void push(char val, node* head){ 
    node* newNode = new Node(val);
    newNode->nextNode = head; 
    head = newNode; 
}
//deletes head value in the stack and moves up the next value to head 
char pop(node* head) {
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
void peek(node* head) {
    if(head ==  NULL) {
        return 0;        
     }
    char data = head->data;
    cout << "data: " << data << endl; 
        
}
    
    //adds a node to the end of the queue
void enqueue(char val, node* first, node* last) {
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
void dequeue(node* first, node* last) {
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
    
void printPost() {
    
    
}

void printPre() {
    
    
}

void printIn() {
    
    
}