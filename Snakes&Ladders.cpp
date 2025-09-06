#include<bits/stdc++.h>
using namespace std;
//Finding the shortes path to reach lastnode in the snakes and ladders
//Dice is in our control
//We may not choose snakes path
//We just consider the ladders to reach 30 in minimum steps
void BFS(int src, vector<int> Graph[], vector<int>&vis, vector<int>&Dis){
	queue<int>Q;
	Q.push(src);
	vis[src] = 1;
	Dis[src] = 0;
	while(!Q.empty() and vis[30] != 1){	//If 30 is visisted, we'll break the loop
										//because we don't need other node's short distance, only 30's
		int node = Q.front();
		cout << node << " ";
		Q.pop();
		for(auto nbr: Graph[node]){
			if(vis[nbr] == 0){
				Q.push(nbr);
				vis[nbr] = 1;
				Dis[nbr] = Dis[node] + 1;
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<int>arr(2 * n);
	for(int i = 0; i < 2 * n; i++){		//Storing the given input in an array - ladders and snakes
		cin >> arr[i];
	}
	map<int, int>Ladder;
	for(int i = 0; i < 2 * n; i += 2){	//Storing the ladders
		Ladder[arr[i]] = arr[i+1]; 
	}
	vector<int> Graph[31];	//Graph with 31 nodes including 0
	
	for(int i = 1; i < 31; i++){		//Outer loop for 31 nodes
		for(int j = 1; j <= 6; j++){	//Inner loop for chances of jump from i
			int jump = i + j;			
			
			if(jump <= 30){
				
				if(Ladder.find(jump) != Ladder.end()){	//Checking if ladder exists at the jump
					
					Graph[i].push_back(Ladder[jump]);	//If yes, climbing the ladder after jump
					
				}
				else{
					Graph[i].push_back(jump);	//If not, staying at the node after jump
				}
			}
		}
	}
	vector<int>vis(31, 0);
	vector<int>Dis(31, 1e9);
	BFS(1, Graph, vis, Dis);
	cout << "\nMinimum Distances: ";
	for(auto i: Dis){
		cout << i << " ";
	}
	cout << endl << Dis[30];
	
}
