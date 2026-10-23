#include<bits/stdc++.h>
using namespace std; 

void heapifyUp(vector<int>&Maxheap, int child){
	while(child > 0){
		//find parent
		int p = child / 2;
		if(Maxheap[p] < Maxheap[child]){
			swap(Maxheap[p], Maxheap[child]);
			child = p;
		}
		else{
			break;
		}
	}
}
void Insert(vector<int>&Maxheap, int val, int idx){
	
	//Inserting element at the end
	Maxheap[idx] = val;
	
	//To keep max element at root(top) ->at first
	heapifyUp(Maxheap, idx);
}
//WRONG
//void Delete(vector<int>&Maxheap){
//	int last = Maxheap.size() - 1;
//	Maxheap[0] = Maxheap[last];
//	Maxheap.pop_back();
//	int i = 0;
//	while(i < Maxheap.size()){
//		//Finding the childs 
//		int c1 = Maxheap[2 * i + 1];
//		int c2 = Maxheap[2 * i + 2];
//		Maxheap[i] = max(c1, c2);
//		i++;
//	}
//}
void printHeap(vector<int>&Maxheap){
	for(int i = 0; i < Maxheap.size(); i++)	cout << Maxheap[i] << " ";
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);	//using vector instead of array
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	vector<int>Maxheap(n+1);
	Maxheap[0] = 0;
	for(int i = 0; i < n; i++){
		Insert(Maxheap, A[i], i+1);
	}
	cout << Maxheap[0] << endl;
	printHeap(Maxheap);
	Delete(Maxheap);
	cout << Maxheap[0] << endl;
	printHeap(Maxheap);	
}