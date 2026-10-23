#include<bits/stdc++.h>
using namespace std;
void DFS(int src, vector<int> Graph[], vector<int> &vis){
	vis[src] = 1;
	cout << src << " ";
	for(auto nbr: Graph[src]){
		if(vis[nbr] == 0){
			DFS(nbr, Graph, vis);
		}
	}
}
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
int main(){
	int N, E;
	cin >> N >> E;
	int u, v;
	vector<vector<int>> mat(N + 1, vector<int>(N + 1, 0));
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
	//Taking array of vectors
	//Converting adj matrix to adj list
	vector<int> list[N + 1];
	for(int i = 0; i < N + 1; i++){
		for(int j = 0; j < N + 1; j++){
			if(mat[i][j] == 1){
				list[i].push_back(j);
				list[j].push_back(i);
			}
		}
	}
	vector<int> vis(N + 1, 0);
	BFS(1, list, vis);
}