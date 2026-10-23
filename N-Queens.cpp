#include<bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, vector<string> &valid, int n){
	int i = row, j = col;
	//top
	while(i >= 0){
		if(valid[i][j] == 'Q')	return false;
		i--;
	}
	
	//top left diagonal
	i = row, j = col;
	while(i >= 0 && j >= 0){
		if(valid[i][j] == 'Q')	return false;
		i--;
		j--;
	}
	//top right diagonal
	i = row, j = col;
	while(i >= 0 && j < n){
		if(valid[i][j] == 'Q')	return false;
		i--;
		j++;
	}
	return true;
}
void NQueens(int row, int n, vector<string> &valid, vector<vector<string>> &out){
	if(row == n){	//All above are already checked -> it is valid
		out.push_back(valid);
		return;
	}
	for(int col = 0; col < n; col++){
		if(isValid(row, col, valid, n)){
			valid[row][col] = 'Q';
			NQueens(row + 1, n, valid, out);
			valid[row][col] = '.';
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<string> valid;
	for(int i = 0; i < n; i++){
		string s;
		for(int j = 0; j < n; j++){
			s += '.';
		}
		valid.push_back(s);
	}
	vector<vector<string>> out;
	NQueens(0, n, valid, out);
	for(auto board: out){
		for(auto row : board){
			cout << row << endl;
		}
		cout << endl;
	}
}