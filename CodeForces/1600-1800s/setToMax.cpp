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

const int maxN = 1005;
int n; int a[maxN], b[maxN];
set<int> valid;
void solve(){  
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    loop(i, 0, n) cin>>b[i];
    int it; 
    valid.clear();
    loop(i, 0, n){
        //expandL
        if(a[i] == b[i])
            valid.insert(i);
        it = i;
        while(it-1>=0 && a[it-1] < a[i] && b[it-1] >= a[i]){
            --it;
            if(a[i] == b[it]){
                valid.insert(it);
                //cout<<i<<" v "<<it<<endl;
            }
        }

        it = i;
        while(it+1<=n-1 && a[it+1] < a[i] && b[it+1] >= a[i]){
            ++it;
            if(a[i] == b[it]){
                valid.insert(it);
                //cout<<i<<" v "<<it<<endl;
            }
        }
    }
    cout<<(valid.size() == n? "YES" : "NO")<<"\n";
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