#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int A[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> A[i][j];
			}
		}
		string str[101];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				str[i+j] = A[i][j];
			}
		}
		map<int, int>num;
		for(int i = 1; i < n; i++){
			num[i] += 1;
		}
		for(auto i : num){
			if(i.second == 0){
				str[0] = i.first;
				break;
			}
		}
		cout << str << "\n";
		
	}
}