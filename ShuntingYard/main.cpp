#include <iostream>
#include <cstring>
#include "node.h"
#include "binarytree.h"

using namespace std; 
/* Shunting yard takes an equation and puts it into a binary tree and can print it 
out in postfix, prefix, and infix notation
Author: Rowan Miller
04/26/24
*/

void add(node* &head, node* &first, node* &last, char* equation);
void push(char val, node* &head);
node* pop(node* &head);
void peek();
void enqueue(node* &first, node* &last, node* &newNode);
void dequeue(node* &first, node* &last);
void addToBT(node* &first, node* &last, binarytree* &bthead);
void pushBT(binarytree* &bthead, binarytree* &newBT);
binarytree* popBT(binarytree* &bthead); 
void printPost(binarytree* bthead, int count);
void printPre(binarytree* bthead, int count);
void printIn(binarytree* bthead, int count); 
int precedence(char n);
void checkPrint(node* head);

int main()
{
    node* first = NULL;
    node* last = NULL; 
    node* head = NULL;
    int count = 0; 
    binarytree* bthead = NULL;
    
    char* equation = new char[50]; 
    cout << "enter an equation" << endl;
    cin >> equation; 
    
    add(head, first, last, equation);
    
    cout << first->data << endl;
    
    checkPrint(first);
    
    addToBT(first, last, bthead); 
    
    bthead = popBT(bthead); 
    
    cout << "bthead:" << bthead->next << endl;
    
    char input[20];
    cout << "how would you like the print the binary expression tree? PRE, IN, or POST" << endl;
    cin >> input; 
    
    if(strcmp(input, "PRE")==0) {
        printPre(bthead, count);
    }
    else if(strcmp(input, "IN")==0) {
        printIn(bthead, count);
        
    }
    else if(strcmp(input, "POST")==0) {
        printPost(bthead, count);
    }
    else {
        cout << "I don't know what that means" << endl; 
    }
}
//shunting yard algorithm 
void add(node* &head, node* &first, node* &last, char* equation) { //write couts and see where the code dies
   cout << "adding" << endl;
    for(int i = 0; i<strlen(equation); i++) {
       if(isdigit(equation[i])) {
            cout << "isdigit" << endl;
           node* current = new node(equation[i]); 
           enqueue(first, last, current); 
           
       }
       //if its an operator
       else if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '^') {
             
             cout << "not a digit" << endl;
             
             while (head != NULL && head->data != '(') {
                if(precedence(head->data) >= precedence(equation[i])) {
                    node* popcorn = pop(head); 
                    enqueue(first, last, popcorn); 
                     
                }
                
                else{
                    
                    break;    
                }
             }
                push(equation[i], head);
                
        }
            //if the operator is not a left parenthesis
        /* else if(equation[i] != '(') {
            cout << "not a left (" << endl; 
              node* popcorn = pop(head);
                enqueue(first, last, popcorn); 

        } */ 
        //if operatior is a left parenthesis
         else if(equation[i] == '(') {
            cout << "is  a left )" << endl; 
            push(equation[i], head);
                
        }
        //if operator is a right parenthesis
         else if(equation[i] == ')') {
             
            while(head->data != '(') {
                if(head == NULL) {
                    break; 
                    return; 
                }
                else { 
                    node* popcorn = pop(head);
                    enqueue(first, last, popcorn);
                    
                    }
                    
                }
                //if head is null
                if(head == NULL) {
                    cout << "there are not matching parenthesis" << endl; 
                    break;
                     
                }
                //if head has a right parenthesis
                else if(head->data == '(') {
                    node* popcorn = pop(head);
                    delete popcorn; 
                    
                }
               
            }
        }   
               
       //while head is not null
       while(head != NULL) {
           cout << "head is not null" << endl;
           //if head is a right or left parenthesis
           if (head->data == '(' || head->data == ')') {
               cout << "mismatched paranthetis" << endl;
               break;
           }
           else {
               node* popcorn = pop(head);
               cout << "about to enqueue" << endl;
               enqueue(first, last, popcorn);
               //cout << "head: " << head->data << endl;
               if(head == NULL) {
                   cout << "Head is null" << endl;
                   break;
                   return; 
                   
               }
           }
           
           
       }
       
        
 } 
   
   



void addToBT(node* &first, node* &last, binarytree* &bthead) {
    cout << "adding to bt" << endl;
    cout << "first:" << first << endl;
    //if the queue is empty
    while (first != NULL) {
        cout << "currently on: " << first->data << endl;
        //creates new tree
         binarytree* newBT = new binarytree(first);
         cout << newBT->current->data << endl;
        //if its a number push to stack
        if(isdigit(first->data)) {
          pushBT(bthead, newBT); 
          cout << "after pushbtm the new head is: " << bthead->current->data << endl;
          dequeue(first, last);
          cout << "after dequeue the new head is: " << bthead->current->data << endl;
       }
        //if its an operator
        else {
            cout << "its an operator:   " << first->data << endl;
            cout << bthead->current->data << endl;
            binarytree* right = popBT(bthead);
            cout << bthead->current->data << endl;
            binarytree* left = popBT(bthead);
            //cout << bthead->current->data << endl;
            cout << "RIGHT: " << right->current->data << endl;
            newBT->right = right; 
            newBT->left = left;
            pushBT(bthead, newBT);
            dequeue(first, last); 
        }
    }
    
}

//pushes binary tree
void pushBT(binarytree* &bthead, binarytree* &newBT) { 
   cout << "pushbt" << endl;
   cout << "PUSHING: " << newBT->current->data << endl;
   binarytree* temp = bthead; 
   newBT->next = temp;
   bthead = newBT; 
   cout << "SETTING BT HEAD TO: " << bthead->current->data << endl;
}

//pop function for binary tree
binarytree* popBT(binarytree* &bthead) {
    cout << "popbt" << endl;
    if(bthead == NULL) {
        return NULL;
    }
    cout << "POPPING: " << bthead->current->data << endl; 
    binarytree* temp = bthead;
    node* current = bthead->current; 
    bthead = bthead->next; 
    //cout << "NEW BT: " << bthead->current->data << endl;
    if (bthead==NULL) {
        cout << "BT HEAD IS NULL !!! " << endl;
    }
    return temp; 
    
}

//adds node into stack 
void push(char val, node* &head){
    cout << "push" << endl;
    node* newNode = new node(val);
    newNode->nextNode = head; 
    head = newNode; 
}
//deletes head value in the stack and moves up the next value to head 
node* pop(node* &head) {
    cout << "pop" << endl;
    if(head == NULL) {
        return 0;    
            
    }
    node* temp = head;
    char data = head->data; 
    head = head->nextNode; 
    return temp;
}
//prints out head value in the stack
void peek(node* head) {
    cout << "peek" << endl;
    if(head ==  NULL) {
        return;        
     }
    char data = head->data;
    cout << "data: " << data << endl; 
        
}
    
    //adds a node to the end of the queue
void enqueue(node* &first, node* &last, node* &newNode) {
    cout << "enqueue" << endl;
    //if there is nothing in the queue
    if(last == NULL) {
        first = newNode;  
        last = newNode; 
    }
    //updating current last pointer to the new last node
    cout << "putting it in" << endl;
    last->nextNode = newNode;
    last = newNode;
    cout << "exiting enqueue" << endl;
        
}
//removes a node from the beginning of the queue
void dequeue(node* &first, node* &last) {
    cout << "dequeue" << endl;
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
            //delete temp;
            return;
        }
    }
    
//prints in postfix notation
void printPost(binarytree* bthead, int count) {
    //cout << "postfix" << endl;
    if(bthead->left != NULL) {
        printPost(bthead->left, count+1);
    }
    if(bthead->right != NULL) {
        printPost(bthead->right, count+1);
    }
    cout << bthead->current->data;
    
    
}

//prints in prefix notation
void printPre(binarytree* bthead, int count) {
    //cout << "prefix" << endl;
    cout << bthead->current->data; 
    if(bthead->left != NULL) {
        printPre(bthead->left, count+1);
    }
    if(bthead->right != NULL) {
        printPre(bthead->right, count+1);
    }
    
    
}

//prints in infix notation
void printIn(binarytree* bthead, int count) {
    //cout << "infix" << endl;
     if(bthead->left != NULL) {
        printIn(bthead->left, count+1);
    }
    cout << bthead->current->data; 
    if(bthead->right != NULL) {
        printIn(bthead->right, count+1);
    }
    
}

//order of operations 
int precedence(char n) {
    if(n == '^') {
        return 3;
    }
    else if (n =='/' || n =='*') {
     return 2;
   }
   else if (n =='+' || n =='-') {
     return 1;
   }

   return 0;
 }
 
void checkPrint(node* head) {
   cout << "checking print" << endl;
    node* n = head;
    while(n->nextNode != NULL) {
        cout << n->data << " ";
        n= n->nextNode;
    }
    cout << n->data << endl; 
    
}