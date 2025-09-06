#include<bits/stdc++.h>
using namespace std;
void DFS(int src, vector<int> adj[], vector<int>&vis){
	vis[src] = 1;
	cout << src << " ";
	//Bring all adj nodes to the src
	for(auto nbr: adj[src]){		//gives the nodes that are connected to the source
		if(vis[nbr] == 0){
			DFS(nbr, adj, vis);
		}
	}
}
int main(){
	int N, E;
	cin >> N >> E;
	//Adjacency list - array of vectors
	vector<int> adj[N+1];	//Graph
	int u, v;
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		adj[u].push_back(v);	//Pushing the adjacent node to each node into the adjacency list
		adj[v].push_back(u);
	}
	vector<int>vis(N+1, 0);	//vector
	DFS(1, adj, vis);
	//for unconnected components in graph
	int c = 0;
	for(int i = 1; i <= N; i++){
		if(vis[i] == 0){
			DFS(i, adj, vis);
			c++;
		}
	}
	cout << "\nNo. of componets in graph: " << c + 1 << endl;
}
