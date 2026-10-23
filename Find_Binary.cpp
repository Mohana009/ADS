#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n;
	cin >> n;
	string binary;
	llmask = 1;
	while(mask <= n){
		if((n & mask) > 0){
			binary += '1';
		}
		else{
			binary += 0;
		}
		mask = mask << 1;
	}
	reverse(binary.begin(), binary.end());
	cout << binary << endl;
	
}