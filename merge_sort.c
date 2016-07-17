/* merge sort in C */
#include <stdio.h>
#include<stdlib.h>

void merge_sort(int *arr,int length);

int main() {

	
	/* Example*/
    int arr[22]={29,21,81,11,31,16,54,83,66,45,76,55,68,78,93,96,92,10,23,18,56,12};
    int length=(sizeof(arr)/sizeof(arr[0]));
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	 
	
	merge_sort(arr,length);

	
	for(int i = 0;i < length;i++) 
	
	  printf("%d \n",arr[i]);
	
	return 0;
}


void merge(int *arr,int *left_arr,int left_length,int *right_arr,int right_length) {
	int i,j,k;

    
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while( i < left_length && j < right_length) {
		
		if(left_arr[i]  < right_arr[j]) arr[k++] = left_arr[i++];
		
		else arr[k++] = right_arr[j++];
	}
	while(i < left_length) arr[k++] = left_arr[i++];
	
	while(j < right_length) arr[k++] = right_arr[j++];
}

 
void merge_sort(int *arr,int length) {
	int middle,*left_arr, *right_arr;
	
	if(length < 2) return; // base condition. If the array has less than two element, do nothing.
	
	middle = length/2;  // find the middle index. 

	// create left and right subarrays
	// middle elements (from index 0 till middle-1) should be part of left sub-array 
	// and (n-middle) elements (from middle to n-1) will be part of right sub-array
	left_arr = (int*)malloc(middle*sizeof(int)); 
	right_arr = (int*)malloc((length - middle)*sizeof(int)); 
	
	for(int i = 0 ; i < middle ; i++ ) left_arr[i] = arr[i]; // creating left subarray
	for(int i = middle ; i < length ; i++) right_arr[i-middle] = arr[i]; // creating right subarray

	merge_sort(left_arr,middle);  // sorting the left subarray
	
	merge_sort(right_arr,(length - middle));  // sorting the right subarray
	
	merge(arr,left_arr,middle,right_arr,(length - middle));  // Merging L and R into A as sorted list.
	
    free(left_arr);
    free(right_arr);
		
}
