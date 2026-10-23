#include<bits/stdc++.h>
using namespace std;
int DivAndConq(vector<int>&A, int low, int high){
	//Base case(Trivial case)
	if(low == high)	return A[low];
	//Divide
	int mid = (low + high) / 2;
	int s1 = DivAndConq(A, low, mid);
	int s2 = DivAndConq(A, mid + 1, high);
	//Conquer
	int curr_sum = s1 + s2;
	return curr_sum;
}
int main(){
	int n;
	cin >> n;
	vector<int>A(n);
	for(int i = 0; i < n; i++)	cin >> A[i];
	int Sum_of_A = DivAndConq(A, 0, n - 1);
	cout << Sum_of_A << endl;
}