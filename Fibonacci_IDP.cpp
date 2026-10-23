#include<bits/stdc++.h>
using namespace std;
//Iterative DP
int main(){
	int n; 
	cin >> n;
	//state -> dp[i] is the i th fibonacci number
	//Transition -> dp[i] = dp[i - 1] + dp[i - 2]
	//Base case -> dp[1] = 1 & dp[2] = 1
	//Final answer -> dp[n]
	
	int dp[n + 1];
	
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}