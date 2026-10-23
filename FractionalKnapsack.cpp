// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		static bool comp(pair<int, int>&a, pair<int, int>&b){
			double r1 = a.first / (a.second * 1.0);
			double r2 = b.first / (b.second * 1.0);
			return r1 > r2;
		}
		double fractionalKnapsack(vector<int>&val, vector<int>&wt, int cap){
			vector<pair<int, int>>Item;
			int n = val.size();
			for(int i = 0; i < n; i++){
				Item.push_back({val[i], wt[i]});
			}
			sort(Item.begin(), Item.end(), comp);
			double pick = 0.0;
			for(int i = 0; i < n; i++){
				if(Item[i].second < cap){
					pick += Item[i].first;
					cap -= Item[i].second;
				}
				else{
					pick += (Item[i].first / (Item[i].second * 1.0)) * cap;
					cap = 0;
					break;
				}
			}
			return pick;
		}
};
int main(){
	int n;
	cin >> n;
	vector<int>val(n);
	vector<int>wt(n);
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	for(int i = 0; i < n; i++){
		cin >> wt[i];
	}
	int cap;
	cin >> cap;
	
	Solution s1;
	cout << s1.fractionalKnapsack(val, wt, cap);
	
}