#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1 = "Hello \"World\" from Me.\n";
	cout << s1;
	string s2 = "It\'s a win.\n";
	cout << s2;
	string s3 = "\\ is backslash.\n";
	cout << s3;
	string s4 = "The character \'\\' is called backslash.\n";
	cout << s4;
	cout << "They are in \'America\' since 2006.\n";
	string s5 = "\\n";
	cout << s5;
}