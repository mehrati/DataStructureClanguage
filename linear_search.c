#include <stdio.h>


int main(){



int arr[10]={23,34,61,90,18,62,29,85,10,67};
int p;
printf("Enter number :\n");
scanf("%i",&p);
for(int i=0;i<10;i++){
   if(p==arr[i]){
   printf("found number!!! arr[%d]=%d \n",i,arr[i]);
   }
   else if(i==9){ 
   printf("not found number!!!\n");
   }
   }








return 0;
}
