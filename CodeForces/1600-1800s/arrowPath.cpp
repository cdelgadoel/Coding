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

const int maxN = 200005;
int n;
bool v[2][maxN];
char m[2][maxN];

void dfs(int i, int j){
    v[i][j] = 1;
    if(i==1 && j == n-1){
        return;
    }
    //abajo
    if(i == 0){
        if(m[1][j] == '>'){
            if(v[1][j+1] == 0)
                dfs(1, j+1);
        }
        else{
            if(v[1][j-1] == 0)
                dfs(1, j-1);
        }
    }
    //arriba
    if(i == 1){
        if(m[0][j] == '>'){
            if(v[0][j+1] == 0)
                dfs(0, j+1);
        }
        else{
            if(v[0][j-1] == 0)
                dfs(0, j-1);
        }
    }
    //der
    if(j < n-1){
        if(m[i][j+1] == '>'){
            if(v[i][j+2] == 0)
                dfs(i, j+2);
        }
    }
    //izq
    if(j > 0){
        if(m[i][j-1] == '<'){
            if(v[i][j-2] == 0)
                dfs(i, j-2);
        }
    }
}

void solve(){
    cin>>n;
    loop(i, 0, 2) fill(v[i], v[i]+n, 0);
    
    loop(i, 0, 2)
    loop(j, 0, n){
        cin>>m[i][j];
    }
    dfs(0, 0);
    cout<<(v[1][n-1]? "YES":"NO")<<"\n";
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