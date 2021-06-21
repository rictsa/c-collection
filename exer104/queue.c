#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"

void enqueue(NodePtr ptr, Queue* queue){
 insertNode(ptr,NULL,queue);
}

void dequeue(Queue* queue){
 deleteNode(first(*queue),queue);
}

NodePtr first(Queue queue){
 if(isEmpty(queue)){return NULL;}
 else{NodePtr tmp=queue;
 while(!isLast(tmp)){
  tmp=tmp->next;
 }
 return tmp;}
}//question

int isQueueEmpty(Queue queue){
 if(queue==NULL){return 1;}
 else {return 0;}
}

void deleteQueue(Queue* queue){
 deleteList(queue);
}

int queueSize(Queue q){
 return(listSize(q));
}

