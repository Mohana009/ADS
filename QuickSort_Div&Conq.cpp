//Divide&Conquer
//quicksort
#include<bits/stdc++.h>
using namespace std;
int Arrange(vector<int>&A, int low, int high){
	int key = A[low];	//pivot element
	int i = low;
	int j = high;
	while(i < j){	//i and j do not cross each other
		while(A[i] <= key && i <= high){
			i++;	//Finds the element that is greater than the key from the start
		}
		while(A[j] > key && j >= low){
			j--;	//Finds the element that is smaller than the key from the end
		}
		if(i < j){	//If i and j do not cross each other in above loops
			swap(A[i], A[j]);	//swaps them
		}
	}
	swap(A[low], A[j]);	//Finally placing the pivot element in its correct position
						//and returning pivot of next recursive part
	return j;	//New pivot index
	
}
void QuickSort(vector<int>&A, int low,  int high){
	if(low >= high)	return;
	int pivot = Arrange(A, low, high);	//Finding pivot for the recursive parts
	QuickSort(A, low, pivot - 1);	//To sort the left part to the pivot element
	QuickSort(A, pivot + 1, high);	//To sort the right part to the pivot element
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	QuickSort(A, 0, n - 1);
	for(int i = 0; i < n; i++)	cout << A[i] << " ";
		
}