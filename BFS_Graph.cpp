//BFS
#include<bits/stdc++.h>
using namespace std;
void BFS(int src, vector<int>Graph[], vector<int>&vis){
	queue<int>Q;
	Q.push(src);
	vis[src] = 1;
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
	vector<int>Graph[N+1];	//array of vectors
  int u, v;
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
	vector<int>vis(N+1, 0);
	BFS(1, Graph, vis);
}
//6
//8
//1 5
//1 4
//5 0
//5 4
//4 0
//0 2
//4 2
//2 3
