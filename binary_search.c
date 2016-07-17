#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){



int arr[10]={4,10,18,23,34,61,62,75,89,90};
int p;
printf("Enter number :\n");
scanf("%i",&p);

int mid=round(sizeof(arr)/(2*4));

if(p > arr[mid]){
 
for(int i=mid;i<10;i++){
   if(p==arr[i]){
   printf("found number!!! arr[%d]=%d \n",i,arr[i]);
   }
   else if(i==9){ 
   printf("not found number!!!\n");
   }
   }
}else if(p < arr[mid]){
    
 
   for(int i=0;i<mid;i++){
   if(p==arr[i]){
   printf("found number!!! arr[%d]=%d \n",i,arr[i]);
   }
   else if(i==mid-1){ 
   printf("not found number!!!\n");
   }
   }
    
    
}else if(p == arr[mid]){
   
   printf("found number!!! arr[%d]=%d \n",mid,arr[mid]);
  
}







return 0;
}
