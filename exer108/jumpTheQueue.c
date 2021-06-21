#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  struct node* prevptr;
  int data;
  struct node* nextptr;
}Node;
typedef Node* nodeptr;

void insert(nodeptr*,nodeptr*,int,int);
void delete(nodeptr*,nodeptr*,int);

int main(void){
char *comm[4]={"insert","delete","head","tail"};
char order[10];
int num;
nodeptr headptr=NULL;
nodeptr tailptr=NULL;

while(scanf("%s",order)!=EOF){
 
 if(strcmp(order,comm[0])==0){
   scanf("%s %d",order,&num);
   if(strcmp(order,comm[2])==0){
    insert(&headptr,&tailptr,num,1);
   }//head
   if(strcmp(order,comm[3])==0){
    insert(&headptr,&tailptr,num,2);
   }//tail
 }//insert
 
 if(strcmp(order,comm[1])==0){
  scanf("%s",order);
  if(strcmp(order,comm[2])==0){
    delete(&headptr,&tailptr,1);
   }//head
   if(strcmp(order,comm[3])==0){
    delete(&headptr,&tailptr,2);
   }//tail
 }//delete

}//end eof

nodeptr tmp;
for(tmp=headptr;tmp!=NULL;tmp=tmp->nextptr){
 printf("%d",tmp->data);
 if(tmp!=tailptr){printf(" ");}
}
printf("\n");

return 0;
}

void insert(nodeptr* head,nodeptr* tail,int num,int order){
if(*head==NULL){
  *head=malloc(sizeof(Node));
  *tail=*head;
  (*head)->data=num;
  (*head)->prevptr=NULL;
  (*head)->nextptr=NULL;
  }

else{
  if(order==1){
    nodeptr tmp;
    tmp=malloc(sizeof(Node));
    tmp->data=num;
    tmp->nextptr=*head;
    tmp->prevptr=NULL;
    (*head)->prevptr=tmp;
    *head=tmp;
  }//head
 
  if(order==2){
    nodeptr tmp;
    tmp=malloc(sizeof(Node));
    tmp->data=num;
    tmp->prevptr=*tail;
    tmp->nextptr=NULL;
    (*tail)->nextptr=tmp;
    *tail=tmp;
  }//tail

}//else
}//insert

void delete(nodeptr* head,nodeptr* tail,int order){
if(*head==NULL){return;}
else{
  if(order==1){
   if((*head)->nextptr!=NULL){
    nodeptr tmp;
    tmp=*head;
    *head=(*head)->nextptr;
    (*head)->prevptr=NULL;
    free(tmp);
    }
  
    else{
    nodeptr tmp;
    tmp=*head;
    *head=NULL;
    *tail=NULL;
    free(tmp);
    }
  }//head

  if(order==2){
    if((*tail)->prevptr!=NULL){
    nodeptr tmp;
    tmp=*tail;
    *tail=(*tail)->prevptr;
    (*tail)->nextptr=NULL;
    free(tmp);
    }

    else{
    nodeptr tmp;
    tmp=*tail;
    *head=NULL;
    *tail=NULL;
    free(tmp);
    }
  }//tail

}
}//delete









