//For adj list &
//Matrix convered into list
#include<bits/stdc++.h>
using namespace std;
void ShortestPath(vector<int> List[], vector<int> &vis, vector<int> &dis, int src){
	vis[src] = 1;
	dis[src] = 0;
	queue<int>Q;
	Q.push(src);
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		for(auto nbr: List[node]){
			if(vis[nbr] == 0){
				Q.push(nbr);
				vis[nbr] = 1;
				dis[nbr] = dis[node] + 1;
			}
		}
	}
}
void adjList(){
	int N, E;
	cout << "Enter no.of nodes: ";
	cin >> N;
	cout << "Enter no.of edges: ";
	cin >> E;
	vector<int> List[N+1];
	int u, v;
	cout << "Enter the edges: \n";
	for(int i = 0; i <= N; i++){
		cin >> u >> v;
		List[u].push_back(v);
		List[v].push_back(u);
	}
	vector<int> vis(N + 1, 0);
	vector<int> dis(N + 1, 1e9);
	ShortestPath(List, vis, dis, 1);
	cout << "Shortest paths from single source 1 is: ";
	for(int i = 1; i <= N; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
}
void adjMat(){
	int N, E;
	cout << "Enter no.of nodes: ";
	cin >> N;
	cout << "Enter no.of edges: ";
	cin >> E;
	vector<vector<int>> mat(N + 1, vector<int>(N + 1, 0));
	int u, v;
	cout << "Enter the edges: \n";
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
	vector<int> List[N + 1];
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			if(mat[i][j] == 1){
				List[i].push_back(j);
				List[j].push_back(i);
			}
		}
	}
	vector<int> vis(N + 1, 0);
	vector<int> dis(N + 1, 1e9);
	ShortestPath(List, vis, dis, 1);
	cout << "Shortest paths from single source 1 is: ";
	for(int i = 1; i <= N; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	
}
int main(){
	//adjList();
	adjMat();
}
//1 2
//1 5
//4 2
//4 1
//3 2
//6 3
//5 6