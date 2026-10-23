//not correct and not completed
#include<bits/stdc++.h>
using namespace std;
int helper = 0;
int n;
int *dp;	//O(1) array index
int Fib(int n){
	
	helper++;
	if(dp[n] != -1)	return dp[n];
	
	if(n <= 2)	return 1;
	
	int sub1 = Fib(n - 1);
	int sub2 = Fib(n - 2);
	
	dp[n] = sub1 + sub2;
	return dp[n];
}
int main(){
	cin >> n;
//	dp[n] = {-1};	not corredt 
	cout << Fib(n) << endl;
	cout << helper;
}