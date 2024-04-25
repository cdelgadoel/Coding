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

const int maxN = 500005;

ll n, m;
void solve(){
    cin>>n>>m;
    cout<<"? 1 1"<<endl;
    ll d; cin>>d;
    pl c1 = d > n-1? pl(n, 1 + d-(n-1)) : pl(1+d, 1);
    pl c2 = d > m-1? pl(1 + d-(m-1), m) : pl(1, d+1);
    
    cout<<"? "<<c1.first<<" "<<c1.second<<endl;
    ll dc1; cin>>dc1;
    cout<<"? "<<c2.first<<" "<<c2.second<<endl;
    ll dc2; cin>>dc2;

    pl qc1 = pl(c1.first - dc1/2, c1.second + dc1/2);
    pl qc2 = pl(c2.first + dc2/2, c2.second - dc2/2);

    if(dc1 & 1){
        cout<<"! "<<qc2.first<<" "<<qc2.second<<endl;
        return;
    }

    cout<<"? "<<qc1.first<<" "<<qc1.second<<endl;
    ll dqc1; cin>>dqc1;
    if(dqc1 != 0){
        cout<<"! "<<qc2.first<<" "<<qc2.second<<endl;
    }
    else{
        cout<<"! "<<qc1.first<<" "<<qc1.second<<endl;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}