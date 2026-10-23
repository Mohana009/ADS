#include<bits/stdc++.h>
using namespace std;
int minSumPath(vector<vector<int>>&grid, int i, int j, int n){
	//base case
	if(i >= n && j >= n) return INT_MAX ;
	if(i == n - 1 || j == n - 1) return grid[i][j];
	
	int sub1 = minSumPath(grid, i + 1, j, n);
	int sub2 = minSumPath(grid, i, j + 1, n);
	
	return grid[i][j] + min(sub1, sub2);
}
int main(){
	int n;
	cin >> n;
	vector<vector<int>>grid(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}
	cout << minSumPath(grid, 0, 0, n) << endl;
}
