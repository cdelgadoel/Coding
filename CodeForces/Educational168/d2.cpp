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

const int maxN = 500005;

int f[maxN];
vector<int> adj[maxN];

int getMinBalanceSons(int v);

int balance(int v){
    if(adj[v].size() == 0)
        return f[v];

    int m = getMinBalanceSons(v);
    return f[v] >= m? m : f[v] + (m - f[v])/2;
}

int getMinBalanceSons(int v){
    int m = 2e9;
    for(int h : adj[v])
        m = min(m, balance(h));
    return m;
}

void solve(){
    int n; cin>>n;
    loop(i, 0, n) {cin>>f[i]; adj[i].clear();}
    for(int i = 1, a; i < n; ++i){
        cin>>a; --a;
        adj[a].push_back(i);
    }
    cout<<f[0] + getMinBalanceSons(0)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}