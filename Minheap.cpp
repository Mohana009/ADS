//minheap
#include<bits/stdc++.h>
using namespace std;
void HeapifyUp(vector<int> &Minheap, int child){
	while(child > 1){
		int parent = child / 2;
		if(Minheap[child] < Minheap[parent]){
			swap(Minheap[child], Minheap[parent]);
			child = parent;
		}
		else{
			break;
		}
	}
}
void Insert(vector<int> &Minheap, int val, int idx){
	Minheap[idx] = val;
	//Bringing the min element to the root (bottom to up)
	HeapifyUp(Minheap, idx);
}
void HeapifyDown(vector<int> &Minheap, int idx, int n){
	while(1){
		int left = 2 * idx;
		int right= 2 * idx + 1;
		int smallest = idx;
		if(left < n && Minheap[left] < Minheap[smallest]){
			smallest = left;
		}
		if(right < n && Minheap[right] < Minheap[smallest]){
			smallest = right;
		}
		if(idx != smallest){
			swap(Minheap[idx], Minheap[smallest]);
			
			
			idx = smallest;
		}
		else{
			break;
		}
	}	
}
void Delete(vector<int> &Minheap){
	int n = Minheap.size();
	if(n <= 0){
		cout << "Minheap is empty to delete\n";
		return;
	}
	Minheap[1] = Minheap[n - 1];
	Minheap.pop_back();
	//Bringing down the max element from root (Top to bottom)
	HeapifyDown(Minheap, 1, n - 1);
}
void printheap(vector<int> &Minheap){
	for(int i = 0; i < Minheap.size(); i++)	cout << Minheap[i] << " ";
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	vector<int>Minheap(n + 1);
	for(int i = 0; i < n; i++){
		Insert(Minheap, A[i], i + 1);
	}
	printheap(Minheap);
	Delete(Minheap);
	printheap(Minheap);
}