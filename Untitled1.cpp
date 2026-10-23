#include<iostream>
int main(){
	int ages[] = {24, 43, 89, 90};
	int lowage = age[0];
	for(int age : ages){
		if(lowage > age)	lowage = age;
	}
	cout << lowage;
}