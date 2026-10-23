#include<stdio.h>
int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter array elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("\nReversed array: ");
	for(int i = n - 1; i >= 0;  i--){
		printf("%d ", arr[i]);
	}
}