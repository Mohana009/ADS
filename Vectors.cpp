#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(40);
	arr.push_back(60);
	arr.push_back(50);
	arr.push_back(1000);
	
	//After pushing

	cout << "After pushing: ";
	//for-each loop
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	
	//Popping 
	arr.pop_back();
	cout << "After popping: ";
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	
	
	cout << "First element: ";
	cout << *(arr.begin());
	cout << endl;
	
	cout << "Last element: ";
	cout << *(arr.end() - 1);
	cout << endl;
	
	cout << "Second element: ";
	cout << *(arr.begin() + 1);
	cout << endl;
	
	//Insert at position
	arr.insert(arr.begin() + 2, 0);
	cout << "Inserting at position: ";
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	
	//Erase at position
	arr.erase(arr.begin() + 2);
	cout << "Erasing at position: ";
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	
	
	
	
	cout << "Before sorting: ";
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	//sorting ascending order
	sort(arr.begin(), arr.end());
	cout << "Ascending order: ";
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	//sorting descending order
	sort(arr.rbegin(), arr.rend());
	cout << "Descending order: ";
	for(auto i: arr)	cout << i << " ";
	cout << endl;
	
}