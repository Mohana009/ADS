#include<bits/stdc++.h>
using namespace std;
void BFS(int src, vector<int> Graph[], vector<int>&vis){
	queue<int>Q;
	vis[src] = 1;
	Q.push(src);
	while(!Q.empty()){
		int node = Q.front();
		cout << node << " ";
		Q.pop();
		for(auto nbr: Graph[node]){
			if(vis[nbr] == 0){
				Q.push(nbr);
				vis[nbr] = 1;
			}
		}
	}
}
void DFS(int src, vector<int> Graph[], vector<int> &vis){
	vis[src] = 1;
	cout << src << " ";
	for(auto nbr: Graph[src]){
		if(vis[nbr] == 0){
			DFS(nbr, Graph, vis);
		}
	}
}
int main(){
	int N, E;
	cin >> N >> E;
	vector<int> Graph[N + 1];
	int u, v;
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
	vector<int> vis(N + 1, 0);
	//BFS(1, Graph, vis);
	DFS(1, Graph, vis);
}