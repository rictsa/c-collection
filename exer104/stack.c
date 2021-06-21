#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"

void push(NodePtr ptr, Stack* stack){
 insertNode(ptr,NULL,stack);
}

void pop(Stack* stack){
 deleteNode(*stack,stack);
}

NodePtr top(Stack stack){
 return stack; 
}

int isStackEmpty(Stack stack){
 if(stack==NULL){return 1;}
 else {return 0;}
}

void deleteStack(Stack* stack){
 deleteList(stack);
}

int stackSize(Stack s){
 return(listSize(s));
}
