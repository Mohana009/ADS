// https://cses.fi/problemset/task/1635
//*Distinct ways*

#include<bits/stdc++.h>
using namespace std;
int Coin_combinations(int x, int n, vector<int>&coins){
	if(x == 0)	return 1;
	if(x < 0)	return 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += Coin_combinations(x - coins[i], n, coins); 
	}
	return ans;
}
int main(){
	int n, x;
	cin >> n >> x;
	vector<int>coins(n);
	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}
	cout << Coin_combinations(x, n, coins);
}