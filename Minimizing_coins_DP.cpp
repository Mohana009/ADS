// https://cses.fi/problemset/task/1634
#include<bits/stdc++.h>
using namespace std;

int dp[1000];
int FindMinCoins(int x, int n, vector<int>&coins){
	if(x < 0)	return INT_MAX;
	if(x == 0)	return 0;
	if(dp[x] != -1)	return dp[x];
	int ans = INT_MAX;
	for(int i = 0; i < n; i++){
		ans = min(ans, FindMinCoins(x - coins[i], n, coins));
	}
	return dp[x] = ans + 1;
}
int main(){
	int n, x;
	cin >> n >> x;
	vector<int>coins;
	for(int i = 0; i < n; i++)	cin >> coins[i];
	memset(dp, -1, sizeof(dp));
	cout << FindMinCoins(x, n, coins);
}