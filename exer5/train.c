#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void insert(NodePtr*); 
void sort(NodePtr*);
int add(NodePtr,int,int);
void print(NodePtr,int,int);

int main(void){
  char *f="fh",*c="ck",*t="tc";
  char type[5];
  int from,to;
  int sumfh,sumck,sumtc,counter=1;
  NodePtr fh=NULL,ck=NULL,tc=NULL;
fh=create(1,365,0,0);
ck=create(1,365,0,0);
tc=create(1,365,0,0);
  while(scanf("%s",type)!=EOF){
    if(strcmp(type,f)==0){
      insert(&fh);
      sort(&fh);
    }//if     
    else if(strcmp(type,c)==0){
      insert(&ck);
      sort(&ck);
    }//ck
    else if(strcmp(type,t)==0){
      insert(&tc);
      sort(&tc);
    }//tc
    else{
      from=atoi(type);
      scanf("%d",&to);
      sumfh=add(fh,from,to);
      sumck=add(ck,from,to);
      sumtc=add(tc,from,to);
     if((sumfh<sumck)&&(sumfh<sumtc)){
        printf("Case%d %d to %d:\nfh %d\n",counter,from,to,sumfh);
	print(fh,from,to);
      }
      if((sumck<sumfh)&&(sumck<sumtc)){
        printf("Case%d %d to %d:\nck %d\n",counter,from,to,sumck);
        print(ck,from,to);
      }
      if((sumtc<sumck)&&(sumtc<sumfh)){
        printf("Case%d %d to %d:\ntc %d\n",counter,from,to,sumtc);
	print(tc,from,to);
      }
     counter++;
    puts("");
    }//routing
  
  }//while
deleteList(&fh);
deleteList(&tc);
deleteList(&ck);
return 0;
}

void insert(NodePtr *main){
  NodePtr tmp=NULL,head=NULL,tail=NULL;
  NodePtr new=NULL;
  int seat,from,to,fee;
 
scanf("%d %d %d %d",&from,&to,&seat,&fee);
      head=create(from,to,seat,fee);
      tmp=*main;
      while(head->from >= tmp->to){
	   tmp=tmp->next;
      }
      while(head!=NULL){
         if(head->to < tmp->to){
	     if((tmp->price==0)||(head->price < tmp->price)){
	        tail=create(head->to,tmp->to,tmp->seat,tmp->price);
	        tail->next=tmp->next;
	        if(head->from == tmp->from){
	           tmp->next=tail;
	           tmp->seat=head->seat;
		   tmp->price=head->price;
		   tmp->to=head->to;
	           head->from=head->to;
		}
	        else{
	           new=create(head->from,head->to,head->seat,head->price);
		   new->next=tail;
		   tmp->to=from;
		   tmp->next=new;
		   head->from=head->to;
	        }
	     }
	     else{
	        head->from=head->to;
	     }
        }//end in one period
        else{
	    if((tmp->price==0)||(head->price < tmp->price)){
	         if(head->from == tmp->from){
	              tmp->seat=head->seat;
		      tmp->price=head->price;
		      head->from=tmp->to;
	              tmp=tmp->next;
		 }
	         else{
	             tail=create(head->from,tmp->to,head->seat,head->price);
	             tail->next=tmp->next;
	             tmp->to=head->from;
		     tmp->next=tail;
	             tmp=tail->next;
		     head->from=tail->to;
		 }
	        }
	    else{
	        tmp=tmp->next;
	        head->from=tmp->to;
	     }
	  }//big else
        if(head->from==head->to){
	    free(head);
	    head=NULL;
	}
	}//while
}//end insert

void sort(NodePtr* main){      
  NodePtr tmp=NULL,tmp2=NULL;     
      tmp=*main;
      while(tmp->next!=NULL){
        if((tmp->seat==(tmp->next)->seat)&&(tmp->price==(tmp->next)->price)){
           tmp->to=(tmp->next)->to;
	   tmp2=tmp->next;
	   tmp->next=tmp2->next;
	   free(tmp2);
        }
        else{tmp=tmp->next;}
      }
}

int add(NodePtr main,int from,int to){
  NodePtr tmp=main;
  int tot=0;
  while(from >= tmp->to){
    tmp=tmp->next;
  }
  while(from!=to){
    if(to <= tmp->to){
       tot+=(to-from)*tmp->price;
       from=to;
    }
    else{
       tot+=(tmp->to-from)*tmp->price;
       from=tmp->to;
       tmp=tmp->next;
    }
  }//while
return tot;
}//add

void print(NodePtr main,int from,int to){
  NodePtr tmp=main;
  while(from >= tmp->to){
    tmp=tmp->next;
  }
  while(from!=to){
    if(to <= tmp->to){
       printf("%d ~ %d class %d NTD%d\n",from,to,tmp->seat,tmp->price);
       from=to;
    }
    else{
       printf("%d ~ %d class %d NTD%d\n",from,tmp->to,tmp->seat,tmp->price);
       from=tmp->to;
       tmp=tmp->next;
    }
  }//while
}
