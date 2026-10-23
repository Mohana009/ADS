#include<bits/stdc++.h>
using namespace std;
int helper = 0;
map<int, int>mpp;	//With map Time complexity O(logn) & operations minimum
int Fib(int n){
	helper++;
	
	if(mpp.find(n) != mpp.end())	return mpp[n];
	if(n <= 2)	return 1;
	
	int sub1 = Fib(n - 1);
	int sub2 = Fib(n - 2);
	
	mpp[n] = sub1 + sub2;
	return mpp[n];
}
int main(){
	int n;
	cin >> n;
	cout << Fib(n) << endl;
	cout << helper;
}