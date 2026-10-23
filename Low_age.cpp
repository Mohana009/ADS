//To find the lowest age 
#include<iostream>
using namespace std;
int main(){
	int ages[] = {24, 43, 8, 90};
	int lowage = ages[0];
	//For-each loop
	for(int age : ages){		
		if(lowage > age)	lowage = age;
	}
	cout << lowage;
}