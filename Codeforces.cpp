#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int c  = 0;
	    if(n >= 4){
	        c += n / 4;
	        n = n % 4;
	    }
	    if(n >= 2){
	        c += n / 2;
	        n = n / 2;
	    }
	    cout << c << endl;
	}

}
