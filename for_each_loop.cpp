//for each loop or range-based for loop
//Used for arrays
#include<iostream>
using namespace std;
int main(){
	int A[5] = {10, 20, 30, 40, 50};
	for(int i: A){
		cout << i << " ";
	}
}