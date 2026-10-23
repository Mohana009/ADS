//Given an integer array of size n find the sum of all the sub arrays 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n; 
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int totalSu m = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int sum = 0;
			for(int k = i; k <= j; k++){
				cout << arr[k] << " ";
				sum += arr[k];
			}
			totalSum += sum;
			cout << "-> " << sum << endl;
		}
	}
	cout <<"Total sub array sum: "<< totalSum;
	
}