#include<stdio.h>
void Bubble_sort(int arr[],int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i] > arr[j])	{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
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
	Bubble_sort(arr, n);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
}