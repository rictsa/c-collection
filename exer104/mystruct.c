#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

int isEqual(Node node1, Node node2){
    return node1.element == node2.element;
}

NodePtr createNode(int ele){
    NodePtr ptr = malloc(sizeof(Node));
    ptr -> element = ele;
    ptr -> next = NULL;
    return ptr;
}

