/* Source code of simple selection sort implementation using array in ascending order in c programming language*/
#include <stdio.h>

int main()
{
  /* Example array*/
  int arr[22]={29,21,81,11,31,16,54,83,66,45,76,55,68,78,93,96,92,10,23,18,56,12};
  int temp=0;
  int cell=0;
  int low;
  int i;
  int length=(sizeof(arr)/4);
  

  
  for(int a=0;a<length;a++){
   
     low=arr[a];
 
     for(i=a;i<length;i++){
   
         if(low>=arr[i]){
     
         low=arr[i];//find the lowest value in array
        
         cell=i;//find the cell lowest value in array
   }
   
 }
 temp=arr[a];
 arr[a]=low;
 arr[cell]=temp;
 }
 
 
 
  printf("Sorted list in ascending order:\n");
 
  for (int i = 0 ; i < length ; i++ )
  
     printf("%d\n", arr[i]);
 
  return 0;
}

