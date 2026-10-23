#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    int f = 0;
	    int p;
	    for(int i = n; i >= 0; i++){
	
	        int m = max(i, i - 1, i - 2);
	        p = i + (i - 1) + (i - 2);
	        if(2 * m < p){
	            f = 1;
	        }
	    }
	    if(f == 1){
	        cout << p << "\n";
	    }
	    else{
	        cout << "-1\n";
	    }
	    
	}

}
