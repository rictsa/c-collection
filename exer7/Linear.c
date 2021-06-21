#include<stdio.h>
#include<stdlib.h>
  typedef struct ANS{
    int x;
    int y;
  }ans;
 
int compare(const void *a,const void *b){
  ans *h1 = (ans*)a, *h2 = (ans*)b;
  if(h1->x > h2->x){
     return 1;
  }
  else if(h1->x < h2->x){
     return -1;
  }
  else{
    if(h1->y > h2->y){
       return 1;
    }
    else return -1;
  }
}
int main(void) {
  int tot;
  while(scanf("%d",&tot)!=EOF){
    double a[tot],b[tot],k[tot];
    int i,j,o,counter=0;
    double tmp_x,tmp_y,equ1,equ2,equ3;
    int t_x,t_y;
    i=(tot+1)*tot/2;
    ans array[i];
  for(i=0;i<tot;i++){
    scanf("%lf %lf %lf",&a[i],&b[i],&k[i]);
  }
  for(i=0;i<tot-1;i++){
     for(j=i+1;j<tot;j++){
	   equ3=a[i]*b[j]-b[i]*a[j];
	   if(equ3!=0){
	     equ2=a[i]*k[j]-a[j]*k[i];
	     equ1=k[i]*b[j]-b[i]*k[j];
	   
	     tmp_x=equ1/equ3;
	     tmp_y=equ2/equ3;
	     if(tmp_x>=0){
	        t_x=(int)(tmp_x*100+1e-4); 
             }
	     else{
	        t_x=(int)(tmp_x*100-1e-4);
	     }
	     if(tmp_y>=0){
	        t_y=(int)(tmp_y*100+1e-4);
	     }
	     else{
	        t_y=(int)(tmp_y*100-1e-4);
	     }
            
      	   if(counter==0){
	     array[0].x=t_x;
	     array[0].y=t_y;
             counter++;
	   }
	   else{
	     for(o=0;o<=counter;o++){
               if(t_x==array[o].x && t_y==array[o].y){
	          break;
	       }
             }
	     if(o>counter){
  	       array[counter].x=t_x;
	       array[counter].y=t_y;
               counter++; 
	     }
	   }
          }
       }
     }
  qsort(array,counter,sizeof(ans),compare);
  printf("%d\n",counter);
  if(counter!=0){
   for(i=0;i<counter;i++){
     printf("(%.2f, %.2f)\n",(float)0.01*array[i].x,(float)0.01*array[i].y);
  }}
  }//eof
    return 0;
}
