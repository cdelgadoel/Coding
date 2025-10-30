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

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(a) a.size()

#define V vector
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 2e5+5;

int val[maxN];
vector<int> adj[maxN];

bool canPrepare(int v, ll value){ 
    if(value > 1000000000)
        return false;
    
    if(adj[v].size() == 0)
        return val[v] >= value;
    else{
        for(int son : adj[v]){
            if(!canPrepare(son, value + max(0LL, value - val[v])))
                return false;
        }
        return true;
    }
}

bool rootCanAchieve(ll value){
    if(value <= val[0])
        return true;

    for(int son : adj[0]){
        if(!canPrepare(son, value - val[0]))
            return false;
    }
    return true;
}

void solve(){
    int n; cin>>n;
    loop(i, 0, n)
        adj[i].clear();
    loop(i, 0, n)
        cin>>val[i];
    loop(i, 1, n){
        int fa;
        cin>>fa;
        adj[--fa].push_back(i);
    }
    ll ini = val[0], fin = 2000000000LL, mitad;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(rootCanAchieve(mitad))
            ini = mitad;
        else
            fin = mitad-1;
    }
    cout<<ini<<"\n";
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