#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
   return (*(int*)a-*(int*)b);
}
int main(void){
  int tot;  
  while(scanf("%d",&tot)!=EOF){
     int mode=0,i,j,list[tot];
     double mean=0,median=0,sd=0;
     for(i=0;i<tot;i++){
        scanf("%d",&list[i]);
	mean+=(double)list[i];
     }
     mean=mean/tot;
     qsort(list,tot,sizeof(int),compare);
     if(tot%2==0){
        median=((double)list[tot/2-1]+(double)list[tot/2])/2;
     }
     else{
        median=(double)list[(tot-1)/2];
     }
     for(i=0;i<tot;i++){
        sd+=pow(list[i]-mean,2);
     }
     sd=sqrt(sd/tot);
     struct{
       int num;
       int freq;
     }counter[tot];
     for(i=0;i<tot;i++){
        counter[i].num=-1,counter[i].freq=0;
     }
     for(i=0;i<tot;i++){
        for(j=0;j<tot;j++){
	   if(list[i]==counter[j].num){
	      counter[j].freq++;
	      break;
	   }
	   else if(counter[j].num==-1){
	      counter[j].num=list[i];
	      counter[j].freq++;
	      break;
	   }
	}
     }
     int tmp=0;
     for(i=1;i<tot;i++){
	if(counter[i].freq > counter[tmp].freq){
	  tmp=i;
        }
     }
     mode=counter[tmp].num;
     printf("%-7s: %f\n%-7s: %f\n%-7s: %d\n%-7s: %f\n","Mean",mean,"Median",median,"Mode",mode,"SD",sd);
  }//eof

return 0;
}

