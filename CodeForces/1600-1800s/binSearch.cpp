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

const int maxN = 2e5+5;

int n, x;
int p[maxN];

int getLeaf(int l, int r){
    if(r-l == 1)
        return l;
    if( p[(l+r)/2] == 0)
        return getLeaf((l+r)/2, r);
    else
        return getLeaf(l, (l+r)/2);
}

void solve(){
    cin>>n>>x;
    int id_x;
    loop(i, 0, n){
        int u; cin>>u;
        if(u == x){
            id_x = i;
            p[i] = x;
        }
        else
            p[i] = u <= x? 0 : 1;
    }

    if(x == 1){
        if(id_x == 0){
            cout<<0<<"\n";
        }
        else{
            cout<<"1\n";
            cout<<1<<" "<<(1+id_x)<<"\n";
        }
        return;
    }
    if(x == n){
        if(id_x == n){
            cout<<0<<"\n";
        }
        else{
            cout<<"1\n";
            cout<<n<<" "<<(1+id_x)<<"\n";
        }
        return;
    }

    // then at least one zero and one one
    int firstZero = n+1, lastOne = -1; 
    loop(i, 0, n){
        if(p[i] == 0) firstZero = min(firstZero, i);
        if(p[i] == 1) lastOne = max(lastOne, i);
    }

    vector<pi> swaps;
    int m = n/2;
    if(p[m] == x){
        if(firstZero < x){
            swaps.push_back(pi(firstZero, id_x));
            swap(p[firstZero], p[id_x]);
            id_x = firstZero;

            int leaf = getLeaf(0, n);
            swaps.pb(pi(leaf, id_x));
        }
        else if(lastOne > x){
            swaps.push_back(pi(lastOne, id_x));
            swap(p[lastOne], p[id_x]);
            id_x = lastOne;

            int leaf = getLeaf(0, n);
            swaps.pb(pi(leaf, id_x));
        }
        else{
            swaps.push_back(pi(m, n-1));
        }
    }
    else{
        if(m < id_x){
            if(p[m] == 0){
                swaps.pb(pi(m, lastOne));
                swap(p[lastOne], p[m]);
            }
            int leaf = getLeaf(0, n);
            swaps.pb(pi(leaf, id_x));
        }
        // x < m
        else{
            if(p[m] == 1){
                swaps.pb(pi(m, firstZero));
                swap(p[firstZero], p[m]);
            }
            int leaf = getLeaf(0, n);
            swaps.pb(pi(leaf, id_x));
        }
    }

    cout<<swaps.size()<<"\n";
    for(pi p_ : swaps){
        cout<<1+p_.first<<" "<<1+p_.second<<"\n";
    }

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