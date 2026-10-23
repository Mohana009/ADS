//WRONG

#include<stdio.h>
int Find(int arr[], int key, int low, int high){
	if(low<=high){
		int mid = (low + high)/2;
		if(arr[mid] == key)	return 1;
		else if(arr[mid] > key)	return Find(arr, key, low, mid-1);
		else if(arr[mid] < key)	return Find(arr, key, mid+1, high);
	}
	return 0;
}
int main(){
	int n;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter array elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int key;
	printf("\nEnter element to search: ");
	scanf("%d", &key);
	int res = Find(arr, key, 0, n-1);
	if(res == 1)	printf("\nElement found");
	else	printf("\nNot found");
}