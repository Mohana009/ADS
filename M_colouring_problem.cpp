#include<bits/stdc++.h>
using namespace std;
bool isSafe(int node, int c, vector<vector<int>>&Graph, vector<int>&colours, int n){
	for(int u = 0; u < n; u++){
		if(Graph[node][u] == 1 && colours[u] == c)	return false;
	}
	return true;
}
bool canColour(int node, vector<int>&colours, vector<vector<int>>&Graph, int totalnodes, int m){
	//base case
	if(node == totalnodes){
		return true;
	}
	//try all possibilities
	for(int c = 1; c <= m; c++){
		if(isSafe(node, c, Graph, colours, m)){
			colours[node] = c;
			if(canColour(node + 1, colours, Graph, totalnodes, m))	return true;
			colours[node] = 0;
		}
	}
	return false;
}
int main(){
	int V, E;
	cin >> V >> E;
	vector<vector<int>>Graph(V, vector<int>(V, 0));
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		Graph[u][v] = 1;
		Graph[v][u] = 1;
	}
	int m;
	cin >> m;
	vector<int>colours(V, 0); 
	bool possible = canColour(0, colours, Graph, V, m);
	cout << possible;
}