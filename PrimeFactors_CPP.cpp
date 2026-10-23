#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	map<int, int>Pfactors;	//[{2, 2}, {5, 2}]
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){								//Time complexity O(sqrt(n)) * O(log(2*n))
			int c = 0;											// = O(sqrt(n))
			while(n % i == 0){
				n = n / i;
				c++;
			}
			Pfactors[i] += c;
		}
	}
	if(n > 1)	Pfactors[n]++;
	for(auto i: Pfactors){
		cout << i.first << " -> " << i.second << endl;
	}

	//For finding no.of zerors in the giver number at the end
//	int t = 0, f = 0;
//	for(auto i: Pfactors){
//		if(i.first == 2)	r += i.second
//		if(i.first == 5)	f += i.second;
//	}
//	cout << min(r, f);
}
