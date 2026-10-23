#include<stdio.h>
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
	int f = 0;
	printf("\nEnter element to search: ");
	scanf("%d", &key);
	for(int i = 0; i < n; i++){
		if(arr[i] == key){
			f == 1;
			break;
		}
			
	}
	if(f == 1)	printf("\nElement found");
	else	printf("\nNot found");
	
}