//Multi-Dimensional arrays
#include<iostream>
using namespace std;
int main(){
	int A[2][4] = {
		{78, 90, 12, 75},
		{89, 79, 45, 23}
	};
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
		
	
	
}