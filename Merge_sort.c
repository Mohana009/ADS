#include<stdio.h>
void Merge(int arr[], int s, int mid, int e){
	int b[e];
	int i = s;	//for left half
	int j = mid + 1;	//for right half
	int k = 0;
	while(i <= mid && j <= e){
		if(arr[i] < arr[j]){
			b[k++] = arr[i++];
		}
		else{
			b[k++] = arr[j++];
		}
	}
	while(i <= mid){
		b[k++] = arr[i++];
	}
	while(j <= e){
		b[k++] = arr[j++];
	}
	for(int i = s, k = 0; i <= e; i++, k++){
		arr[i] = b[k];
	}
}
void Merge_sort(int arr[], int s, int e){
	if(s < e){
		int mid = (s+e)/2;
		
		Merge_sort(arr, s, mid);
		Merge_sort(arr, mid+1, e);
		
		Merge(arr, s, mid, e);
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
	int A[n];
	for(int i = 0; i < n; i++)	scanf("%d", &A[i]);
	Merge_sort(A, 0, n - 1);
	Print_array(A, n);
}