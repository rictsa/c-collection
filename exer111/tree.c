#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  char ele;
  struct Node* next;
}node;
typedef node* nodeptr;


void post(nodeptr,nodeptr);


int main(void){
nodeptr pre_head=NULL,pre_tail=NULL,in_tail=NULL,in_head=NULL,pre_left=NULL,pre_right=NULL,in_right=NULL,in_left=NULL;
nodeptr new,tmp;
char a;

while((a=getchar())!=EOF){
   new=malloc(sizeof(node));
   new->ele=a;
   new->next=NULL;
   pre_head=new;
   pre_tail=new;  
   while((a=getchar())!=' '){
      new=malloc(sizeof(node));
      new->ele=a;
      new->next=NULL;
      pre_tail->next=new;
      pre_tail=new;
   }//pre

   a=getchar();
   new=malloc(sizeof(node));
   new->ele=a;
   new->next=NULL;
   in_head=new;
   in_tail=new;
   while((a=getchar())!='\n'){
      new=malloc(sizeof(node));
      new->ele=a;
      new->next=NULL;
      in_tail->next=new;
      in_tail=new;
   }//in

   post(pre_head,in_head);
puts("");
}//eof


return 0;
}



void post(nodeptr pre,nodeptr in){
nodeptr pre_left=NULL,pre_right=NULL,in_right=NULL,in_left=NULL;
nodeptr tmp;
int counter=0;
if(pre==NULL){
  return;
}

else if(pre->next==NULL){
  printf("%c",pre->ele);
  return;
}
else{ 
 tmp=in;
 while(tmp->ele != pre->ele){
    tmp=tmp->next;
    counter++;
 }
 if(counter==0){
   pre_left=NULL;
   in_left=NULL;
   pre_right=pre->next;
   pre->next=NULL;
   in_right=in->next;
   in->next=NULL;
 }
 else{
   in_left=in;
   while(in->next!=tmp){
      in=in->next;
   }
   in->next=NULL;
   in=tmp;
   in_right=in->next;
   in->next=NULL;

   pre_left=pre->next;
   tmp=pre;
   for(;counter!=0;counter--){
      tmp=tmp->next;
   }
   pre_right=tmp->next;
   tmp->next=NULL;
 }  
   post(pre_left,in_left);
   post(pre_right,in_right);
   printf("%c",pre->ele);
   free(pre);
   free(in);
 
}//else



}







