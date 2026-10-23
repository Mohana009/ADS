//Lalitha
#include<bits/stdc++.h>
using namespace std;
void BFS(int src , vector<int>Graph[] , vector<int>&vis , vector<int>&D)
{
	queue<int>Q;
	Q.push(src);
	vis[src] = 1;
	D[src] = 0;
	while(!Q.empty())
	{
		int node = Q.front();
		cout<<node<<" ";
		Q.pop();
		for(auto nbr : Graph[node])
		{
			if(vis[nbr] == 0)
			{
				Q.push(nbr);
				vis[nbr] = 1;
				D[nbr] = D[node]+1;
			}
		}
	}
	cout<<"\n";
	for(auto i : D){
		cout << i << " ";
	}
}
int main()
{
	int n, e;
	cin >> n >> e;
	vector<int>Graph[n+1];
	int u , v;
	for(int i = 0 ; i < e ; i++){
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
	vector<int>vis(n+1 , 0);
	vector<int>D(n+1 , 1e9);
	BFS(1, Graph, vis, D);
}
