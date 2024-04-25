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

const int maxN = 5005;

int n;
int a[maxN], dp[maxN];
void solve(){
    cin>>n;
    fill(a, a + 5001, 0);
    loop(i, 0, n) {
        int u; cin>>u;
        if(u <= 5000)
            ++a[u];
    }

    int it = 0;
    while(a[it] > 0) ++it;
    int mex = it;

    //dp[i] has the minimum m if i is the mex of the array
    dp[0] = 0;
    loop(i, 1, mex+1){
        // I choose the next mex
        dp[i] = 1e9;
        loop(j, 0, i){
            dp[i] = min(dp[i], i*(a[j]-1) + j + dp[j]);
        }
    }
    cout<<dp[mex]<<"\n";
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