#include<bits/stdc++.h>
using namespace std;
//Recursion
void SubSeq(int i, vector<int>&A, int n, vector<int>&ds){
	//Base case
	if(i == n){
		for(int i = 0; i < ds.size(); i++)	cout << ds[i] << " ";
		cout << endl;
		return;
	}
	//Pick
	ds.push_back(A[i]);
	SubSeq(i + 1, A, n, ds);
	ds.pop_back();
	//Dont pick
	SubSeq(i + 1, A, n, ds);
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	vector<int>ds;
	SubSeq(0, A, n, ds);
}