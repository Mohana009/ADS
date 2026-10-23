#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1 = "Hello";
	cout << s1[0] << endl;
	cout << s1[s1.length() - 1] << endl;
	cout << s1.at(1) << endl;
	cout << s1.at(s1.length() - 1) << endl;
	cout << s1 <<"\n";
	s1[0] = 'J';
	cout << s1 << "\n";
	s1.at(0) = 'h';
	cout << s1 << "\n";
}