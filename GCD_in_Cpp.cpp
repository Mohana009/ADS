#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int GCD = __gcd(a, b);
	cout << "GCD is: " << GCD << endl;
	int LCM = (a * b)/GCD;
	cout << "LCM is: " << LCM << endl;

}