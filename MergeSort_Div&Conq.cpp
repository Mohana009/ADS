#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>&A, int low, int mid, int high){
	int i = low;
	int j = mid + 1;
	int k = 0;
	int B[high + 1];
	while(i <= mid && j <= high){
		if(A[i] <= A[j]){
			B[k++] = A[i++];
		}
		else{
			B[k++] = A[j++];
		}
	}
	while(i <= mid){
		B[k++] = A[i++];
	}
	while(j <= high){
		B[k++] = A[j++];
	}
	for(i = 0; i < k; i++){
		A[i + low] = B[i];
	}
}
void MergeSort(vector<int>&A, int low, int high){
	if(low >= high)	return;
	int mid = (low + high) / 2;
	MergeSort(A, low, mid);
	MergeSort(A, mid + 1, high);
	Merge(A, low, mid, high);
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i= 0; i < n; i++){
		cin >> A[i];
	}
	MergeSort(A, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
}