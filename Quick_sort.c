#include<stdio.h>
//Similar to divide and conquer
//Taking last element as pivot
/* 1. Select the pivot element
   2. Partition of the array
   3.Calling Quick sort for the left part and right part of the pivot separately
*/

/*In partition,
	we'll compare each element with the pivot(i.e, last) element
	and place the small elements than pivot to the starting by swapping
	*Swaping doesnot takes place between the pivot element and small elements
	Here idx -> creates place for swapping
	  and j  -> takes care of the iterations
*/
int Partition(int arr, int start, int end){
	int idx = start - 1;
	int pivot = end;
	
	for(int j = start; j < end; j++){
		if(arr[j] <= arr[pivot]){
			idx++;
			int temp = arr[j];
			arr[j] = arr[idx];
			arr[idx] = temp;
		}
	}
	int temp = arr[idx];
	arr[idx] = arr[end];
	arr[end] = temp;
	
	return idx;
}
	//Placing the pivot element in its correct position
	//After the loop ends the smallest elements than pivot are place before the largest elements
	//Now the correct position of pivot element is between the small part and large part of elements
	//idx is at the last element of the smallest elements part and j is at pivot element
	//So we just increment idx and swap j and idx
	
	
	
}
void Quick_sort(int arr[], int start, int end){
	if(start < end){
		int pivot = partition(arr, start, end);
		Quick_sort(arr, start, pivot - 1);	//	For left half of the pivot
		Quick_sort(arr, pivot + 1, end);	//For right half of the pivot
	}
}
void Print_array(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)	scanf("%d", &arr[i]);
	Quick_sort(arr, 0, n);
	Print_array(arr, n);
	
}