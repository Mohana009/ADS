#include<bits/stdc++.h>
using namespace std;
int sub_sequence(int i, int n, vector<int>&A, int k){
	//base case
	if(i == n){
		if(k == 0)	return 1;
		return 0;
	}
	//pick
	int c1 = sub_sequence(i + 1, n, A, k - A[i]);
	
	//non-pick
	int c2 = sub_sequence(i + 1, n, A, k);
	
	return c1 + c2;
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	int k;
	cin >> k;
	int ans = sub_sequence(0, n, A, k);
	cout << ans;
}