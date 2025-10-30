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

const int maxN = 1e6+5;
int n; 
ll nodosSubarbol[maxN];
vector<int> adj[maxN];

void dfs(int v, int fa){
    nodosSubarbol[v] = 1;
    for(int u : adj[v]){
        if(u != fa){
            dfs(u, v);
            nodosSubarbol[v] += nodosSubarbol[u];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    loop(i, 0, n-1){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    ll maxVisitas = -1;
    for(int i = 2; i <= n; ++i){
        maxVisitas = max(maxVisitas, nodosSubarbol[i]*(n - nodosSubarbol[i]));
    }

    int countMax = 0;
    for(int i = 2; i <= n; ++i){
        if( nodosSubarbol[i]*(n - nodosSubarbol[i]) == maxVisitas)
            ++countMax;
    }
    cout<<maxVisitas<<" "<<countMax<<"\n";

    return 0;
}