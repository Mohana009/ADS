#include<bits/stdc++.h>
using namespace std;
//comparison function for sorting
bool comp(const pair<int, int>&a, const pair<int, int>&b){
//	if(a.second == b.second)	return a.first > b.first; -> no need this condition
	return a.second < b.second; 
}

int main(){
	int n;
	cin >> n;
//	vector<vector<int>>Movies;	-> vector of vectors
	vector<pair<int, int>>Movies;	//vector pair
	for(int i = 0; i < n; i++){
		int startTime, endTime;
		cin >> startTime >> endTime;
		Movies.push_back({startTime, endTime});
		
		//Movies.push_back(make_pair(startTime, endTime))
	}
//	for(int i = 0; i < n; i++){
//		cout << Movies[i].startTime << " " << Movies[i].endTime;
//	}
	
	//Sort based on end time
	//sort(Movies.begin(), Movies.end())	-> by default sorts based on startTime
	
	sort(Movies.begin(), Movies.end(), comp);
	int c = 1;
	int end = Movies[0].second;
	for(int i = 1; i < n; i++){
		if(Movies[i].first >= end){
			c++;
			end = Movies[i].second;
		}
	}
	cout << c << endl;
	
	
}