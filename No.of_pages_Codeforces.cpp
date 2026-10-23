#include<bits/stdc++.h>
using namespace std;
int Pages(int i, int n, vector<int>&c, vector<int>&p, int x){
	//basse case
	if(i == n){
		return 0;
	}
	int left = 0;
	int right = 0;
	//pick
	if(c[i] <= x){
		left = p[i] + Pages(i + 1, n, c, p, x - c[i]);
	}
	//dont pick
	right - 0 + Pages(i + 1, n, c, p, x);
	
	return max(left, right);
}
int main(){
	int n;
	cin >> n;
	vector<int>c(n);
	for(int i = 0; i < n; i++)	cin >> c[i];
	vector<int>p(n);
	int x;
	cin >> x;
	int res = Pages(0, n, c, p, x);
	cout << res << endl;
}