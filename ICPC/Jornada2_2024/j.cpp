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

const int maxN = 1e3+1;
bool adj[maxN][maxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n, m; cin>>n>>m;
    if(n == 1){
        cout<<"NO\n";
        return 0;
    }

    int a, b;
    loop(i, 0, m){
        cin>>a>>b;
        adj[a][b] = adj[b][a] = 1;
    }

    int k = 0;
    cout<<"YES\n";
    loop(i, 1, n/2 + 1){
    loop(j, i+1, n/2 + 1){
        if(!adj[i][j])
            ++k;
    }
    }

    loop(i, n/2 + 1, n+1)
    loop(j, i+1, n+1){
        if(!adj[i][j])
            ++k;
    }
    cout<<k<<"\n";

    loop(i, 1, n/2 + 1){
    loop(j, i+1, n/2 + 1){
        if(!adj[i][j])
            cout<<i<<" "<<j<<"\n";
    }
    }

    loop(i, n/2 + 1, n+1)
    loop(j, i+1, n+1){
        if(!adj[i][j])
            cout<<i<<" "<<j<<"\n";
    }
    
    return 0;
}