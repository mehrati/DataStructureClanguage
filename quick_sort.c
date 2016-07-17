/** Divide  : Partition the array A[low....high] into two sub-arrays
  *           A[low....j-1] and A[j+1...high] such that each element
  *           of A[low....j-1] is less than or equal to A[j], which
  *           in turn is is less than or equal to A[j+1...high]. Compute
  *           the index j as part of this partitioning procedure.
  * Conquer : Sort the two sub-arrays A[low....j-1] and A[j+1....high]
  *           by recursive calls to quicksort
  **/

#include<stdio.h>

int main()
{
  
  int arr[22]={29,21,81,11,31,16,54,83,66,45,76,55,68,78,93,96,92,10,23,18,56,12};
  int length=(sizeof(arr)/sizeof(arr[0]));

  quicksort(arr,length);

  printf("Sorted array\n");
  
  for(int i = 0; i < length; i++)
  
    printf("%d ", arr[i]);

  return 0;
}
void quicksort(int *arr, int length)
{
  int pivot, temp;
  
  int i,j,r;
  
  r=0;
  i=0;
  j=length-1;
  pivot=arr[r];
  
  while(arr[i]>pivot[r] && i < length) i++;
  while(arr[j]<pivot[r] && i > =0) j--;
  
  temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp
  
}
