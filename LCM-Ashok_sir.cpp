#include<bits/stdc++.h>
using namespace std;

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	int r = 2;
	int res = 1;
	while(true){		//r < n1 and r < n2
		if(n1 % r == 0 and n2 % r == 0){
			n1 = n1 / r;
			n2  = n2 / r;
			res = res * r;
		}
		else{
			r++;
		}
		if(r > n1 or r > n2){
			break;
		}
	}
	//O(log2 (min(n1,n2) )
	
	int LCM = res * n1 * n2;
	cout << LCM << endl;
}