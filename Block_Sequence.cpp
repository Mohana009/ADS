//	https://codeforces.com/contest/1881/problem/E
#include<bits/stdc++.h>
using namespace std;
void Solve(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	vector<int>dp(n + 1, 0);
	
	//State -> dp[i] = max no. of elements can retain from i to n - 1
	
	for(int i = n - 1; i >= 0; i--){
		//Transition
		int pick = 0, skip = 0;
		//skip
		skip = dp[i + 1];
		//pick
		if(i + A[i] <= n - 1){
			pick = dp[i] = 1 + A[i] + dp[i + A[i] + 1];
		}
		dp[i] = max(pick, skip);
		
	}
	cout << n - dp[0] << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Solve();
	}
}