#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdint>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;


const int maxN = 200005, maxE = 300005;
int n; 
pi edges[maxE];
vector<pi> adj[maxN];
pi ancestor[maxN];
int distRoot[maxN], isBackEdge[maxE];
bool visited[maxN];

int costBackEdge(int i){
    return min(distRoot[edges[i].first], distRoot[edges[i].second]);
}

void dfs(int u, int fa){
    visited[u] = true;
    for(pi edge : adj[u]){
        if(edge.first == fa) continue;
        if(visited[edge.first]){
            isBackEdge[edge.second] = true;
        }
        else{
            ancestor[edge.first] = pi(u, edge.second);
            distRoot[edge.first] = distRoot[u] + 1;
            dfs(edge.first, u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n; 
    int e; cin>>e;

    loop(i, 0, e){
        int a, b; cin>>a>>b;
        --a; --b;
        edges[i] = pi(a, b);
        adj[a].push_back(pi(b, i));
        adj[b].push_back(pi(a, i));
    }

    dfs(0, -1);
    int idMaxCostEdge = -1;
    loop(i, 0, e){
        if(isBackEdge[i]){
            if(idMaxCostEdge == -1 || costBackEdge(idMaxCostEdge) < costBackEdge(i)){
                idMaxCostEdge = i;
            }
        }
    }

    vector<int> resp;
    resp.push_back(idMaxCostEdge);
    if(distRoot[edges[idMaxCostEdge].first] > distRoot[edges[idMaxCostEdge].second])
        swap(edges[idMaxCostEdge].first, edges[idMaxCostEdge].second);
    
    int it = edges[idMaxCostEdge].second;
    while(it != edges[idMaxCostEdge].first){
        resp.push_back(ancestor[it].second);
        it = ancestor[it].first;
    }

    cout<<resp.size()<<"\n";
    loop(i, 0, resp.size()){
        cout<<resp[i]+1<<" \n"[i==resp.size()-1];
    }
    return 0;
}