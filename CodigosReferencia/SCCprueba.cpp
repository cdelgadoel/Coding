#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define UNVISITED 0
vector<pii> adj[maxV];
int V, E, dfsNumberCounter, numSCC; 
vi dfs_num, dfs_low, S, visited;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	S.push_back(u); 
	visited[u] = 1;
	for (int j = 0; j < (int)adj[u].size(); j++) {
		pii v = adj[u][j];
		if (dfs_num[v.first] == UNVISITED)
			tarjanSCC(v.first);
		if (visited[v.first]) // condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}

	if (dfs_low[u] == dfs_num[u]) { 
		cout<<"SCC "<<(++numSCC)<<":";
		while (1) {
			int v = S.back(); S.pop_back(); visited[v] = 0;
			cout<<" "<<v;
			if (u == v) break; 
		}
		cout<<"\n";
	} 
}

// inside int main()
int main(){
	cin>>V>>E;
	for(int i = 0, a, b; i < E; ++i){
		cin>>a>>b;
		adj[a].push_back(pii(b, 0));
	}

	dfs_num.assign(V, UNVISITED); 
	dfs_low.assign(V, 0); 
	visited.assign(V, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < V; i++)
		if (dfs_num[i] == UNVISITED)
			tarjanSCC(i);
	return 0;
}