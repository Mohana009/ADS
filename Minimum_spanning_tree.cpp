#include <bits/stdc++.h>

using namespace std;
int MinimumSpanningTree(vector<pair<int , int>>adj , int start , vector<int>&vis)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
    PQ.push({start , 0});
    int cost = 0;
    while(!PQ.empty())
    {
        auto node = PQ.top();
        PQ.pop();
        int u = node.first;
        int wt = node.second;
        if(vis[u] == 1) continue;
        vis[u] = 1;
        cost += wt;
        for(auto it : adj[u])
        {
            int v = it.first;
            wt = it.second;
            PQ.push({v , wt});
        }
    }
    return cost;
    
    
}
int main()
{
    int n , e ; 
    cin >> n >> e;
    vector<vector<int>>graph(e , vector<int>(3));
    vector<vector<pair<int , int>>>adj;
    for(int i = 0 ; i < e ; i++)
    {
            int u , v , wt;
            cin >> u >> v >> wt;
            graph[i][0] = u;
            graph[i][1] = v;
            graph[i][2] = wt;
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
    }
    int start ;
    cin >> start;
    vector<int>vis(n+1 , 0);
    int cst = MinimumSpanningTree(adj , start , vis);
    cout << cst;    
}
