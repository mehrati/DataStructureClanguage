/*
 * C Program to sort an array using Shell Sort technique
 */
#include <stdio.h>

int main()
{
  /* Example*/
  int arr[22]={29,21,81,11,31,16,54,83,66,45,76,55,68,78,93,96,92,10,23,18,56,12};
  int temp=0;
  int cell=0;
  int low;
  int i,j;
  int length=(sizeof(arr)/4);
  
    for (i = length / 2; i > 0; i = i / 2)
    {
        for (j = i; j < length; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    temp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = temp;
                }
            }
        }
    }



 
 
  printf("Sorted list in ascending order:\n");
 
  for (int i = 0 ; i < length ; i++ )
  
     printf("%d\n", arr[i]);
 
  return 0;
}

