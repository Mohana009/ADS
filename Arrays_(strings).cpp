//String arrays
#include<iostream>
#include<string>
using namespace std;
int main(){
	string students[4] = {"Ram", "John", "Sofia", "Jack"};
	for(string i: students){
		cout << i << " ";
	}
}