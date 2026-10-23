//maxheap
#include<bits/stdc++.h>
using namespace std;
//Should be a binary tree and max element should be at root
void HeapifyUp(vector<int> &Maxheap, int child){
	while(child > 1){
		int parent = child / 2;
		if(Maxheap[child] > Maxheap[parent]){
			swap(Maxheap[child], Maxheap[parent]);
			child = parent;
		}
		else{
			break;
		}
	}
}
void Insert(vector<int> &Maxheap, int val, int idx){
	Maxheap[idx] = val;
	//Bringing max value to the root (bottom to down)
	HeapifyUp(Maxheap, idx);
}

void HeapifyDown(vector<int> &Maxheap, int idx, int n){
	while(1){
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int largest = idx;
		if(left < n && Maxheap[left] > Maxheap[largest]){
			largest = left;
		}
		if(right < n && Maxheap[right] > Maxheap[largest]){
			largest = right;
		}
		if(largest != idx){
			swap(Maxheap[idx], Maxheap[largest]);
			idx = largest;
		}
		else{
			break;
		}
	}
}
void Delete(vector<int> &Maxheap){
	int n = Maxheap.size();
	//if heap is empty (0th index is not considered)
	if(n <= 0){
		cout << "Heap is empty to delete\n";
		return;
	}
	Maxheap[1] = Maxheap[n - 1];
	Maxheap.pop_back();
	//Bringing down the min element from root
	HeapifyDown(Maxheap, 1, n - 1);
}
void printheap(vector<int> &Maxheap){
	for(int i = 0; i < Maxheap.size(); i++)	cout << Maxheap[i] << " ";
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	vector<int>Maxheap(n + 1);
	for(int i = 0; i < n; i++){
		Insert(Maxheap, A[i], i + 1);
	}
	printheap(Maxheap);
	Delete(Maxheap);
	printheap(Maxheap);
}