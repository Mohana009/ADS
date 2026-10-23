#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	vector<int>coins(n);
	for(int i = 0; i < n; i++)	cin >> coins[i];
	vector<int>dp(x + 1, 0);
	int mod = 1000000000 + 7;
	//state -> dp[n] is no.of ways to make sum n by using the given elements
	//transition -> dp[n] = dp[n] + dp[n - x]
	//Basecase -> dp[0] = 1 -> we can make sum 0 by not choosing any of the coins in 1 way
	//final answer -> dp[n]
	dp[0] = 1;	//we can make sum 0 by picking 0 coins in 1 way
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(i - coins[j] >= 0)	dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
		}
	}
	cout << dp[x];
}