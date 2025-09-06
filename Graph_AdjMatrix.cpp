#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, E;
	cin >> N >> E;
//	int Graph[N + 1][N + 1];
//	for(int i = 0; i <= N; i++){
//		for(int j= 0; j <= N; j++){
//			Graph[i][j] = 0;
//		}
//	}
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
	for(int i = 0; i < N+1; i++){
		for(int j = 0; j < N+1; j++){
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
}
