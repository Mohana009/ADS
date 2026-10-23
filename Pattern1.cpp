#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 9;
	int s = 1;
	for(int i = 1; i <= n; i++){
		//for spaces
		for(int j = 1; j <= n-1; j++){
			cout << " ";
		}
		//for *
		for(int k = 1; k <= s; k++){
			cout << "*";
			s += 2;
		}
		//same loop for last spaces
		cout << endl;
	}
}