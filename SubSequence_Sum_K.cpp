#include<bits/stdc++.h>
using namespace std;
//with data structure
int sub_sequence(int i, int n, vector<int>&A, vector<int>&ds, int k){
	//base case
	if(i == n){
		int sum = 0;
		for(int i = 0; i < ds.size(); i++){
			sum += ds[i];
		}
		//Checking sum
		if(sum == k){
			for(int i = 0; i < ds.size(); i++)	cout << ds[i] << " ";
			cout << endl;
			return 1;
		}
		return 0;
	}
	int c1 = 0, c2 = 0;
	//pick
	ds.push_back(A[i]);
	int c1 = sub_sequence(i + 1, n, A, ds, k);
	ds.pop_back();
	
	//non-pick
	int c2 = sub_sequence(i + 1, n, A, ds, k);
	
	return c1 + c2;
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	int k;
	cin >> k;
	vector<int>ds;
	int ans = sub_sequence(0, n, A, ds, k);
	cout << ans;
}