/* Bubble sort code */
#include <stdio.h>

int main()
{
  int arr[22]={29,21,81,11,31,16,54,83,66,45,76,55,68,78,93,96,92,10,23,18,56,12};
  int swap;
 
  int length=(sizeof(arr)/4);
  for (int a = 0 ; a < (length-1) ; a++)
  
      for (int c = 0 ; c < (length-1-a) ; c++)
         {
           
          if (arr[c] > arr[c+1])
         {
           /* Swapping */
          swap = arr[c];
          arr[c] = arr[c+1];
          arr[c+1] = swap;
         }
         }
  
 
  printf("Sorted list in ascending order:\n");
 
  for (int i = 0 ; i < length ; i++ )
  
     printf("%d\n", arr[i]);
 
  return 0;
}
