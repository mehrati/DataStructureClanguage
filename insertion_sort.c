/* Source code of simple insertion sort implementation using array in ascending order in c programming language*/
#include <stdio.h>

int main()
{
  int arr[22]={29,21,81,11,31,16,54,83,66,45,76,55,68,78,93,96,92,10,23,18,56,12}; 
  int temp;
  int i=1;
  int length=(sizeof(arr)/4);
  goto iter;
  
  for(i=1;i<length;i++){
      
      if(arr[i]>arr[i+1] && (i+1)<length){
        temp=arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=temp;
      }
      iter:{
      if(arr[i]<arr[i-1] && (i-1)>=0){
        temp=arr[i-1];
        arr[i-1]=arr[i];
        arr[i]=temp;
        i--;
      goto iter;
       }   }
      
  }
 
  printf("Sorted list in ascending order:\n");
 
  for (int i = 0 ; i < length ; i++ )
  
     printf("%d\n", arr[i]);
 
  return 0;
}

