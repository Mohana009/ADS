#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float a;
	int b;
	cin >> a >> b;
	cout << "sqrt(" << b << ") : " << sqrt(b) << endl;
	cout << "Round of(" << a << ") : " << round(sqrt(a)) << endl;
	cout << "log(" << a << ") : " << log(a) << endl;
	cout << "Round of " << a << " : " << round(a) << endl;
}