#include<bits/stdc++.h>
using namespace std;

void DFS(int src, vector<int> List[], vector<int>&vis){
	vis[src] = 1;
	cout << src << " ";
	for(auto nbr: List[src]){
		if(vis[nbr] == 0){
			DFS(nbr, List, vis);
		}
	}
}

int main(){
	int N, E;
	cin >> N >> E;
	vector<vector<int>>Graph(N+1, vector<int>(N+1, 0));	//vector of vectors
//	vector<int>Graph(n, 0)
	int U, V;
	for(int i = 0; i < E; i++){
		cin >> U >> V;
		Graph[U][V] = 1;
		Graph[V][U] = 1;	//undirected graph
	}
	//Space is more 
	//Time: 
	
	
	//For printing matrix
	for(int i = 0; i < N+1; i++){
		for(int j = 0; j < N+1; j++){
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	
	//Storing adj matrix into adj list
	vector<int> List[N+1];
	for(int i = 0; i < N+1; i++){
		for(int j = 0; j < N+1; j++){
			if(Graph[i][j] == 1){
				List[i].push_back(j);
			}
		}
	}
	vector<int>vis(N+1, 0);
	DFS(1, List, vis);
	int c = 1;
	for(int i = 1; i < N+1; i++){
		if(vis[i] == 0){
			DFS(i, List, vis);
			c++;
		}
	}
	cout << endl << c << endl;
}