#include<bits/stdc++.h>
using namespace std;
int dp[1000000];
int mod = 10000000 + 7;
int Coin_combinations(vector<int> &coins, int n, int x){
	if(x == 0)	return 1;	//Found one valid way to make sum x
	if(x == -1)	return 0;	//Not a valid way
	if(dp[x] != -1)	return dp[n];
	int ans;
	for(int i = 0; i < n; i++){
		ans += Coin_combinations(coins, n, x - coins[i]) % mod;
	}
	dp[x] = ans;
	return ans; 
}
int main(){
	int n, x;
	cin >> n >> x;
	vector<int>coins(n);
	for(int i = 0; i < n; i++)	cin >> coins[i];
	memset(dp, -1, sizeof(dp));
	cout << Coin_combinations(coins, n, x);
}