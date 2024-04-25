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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    int costo[50];
    costo[0] = 0;
    int coins[5] = {1, 3, 6, 10, 15};
    for(int i = 1; i < 50; ++i){
        costo[i] = i;
        for(int coin : coins ){
            if(i >= coin)
                costo[i] = min(costo[i], 1 + costo[i-coin]);
        }
    }

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int resp = n;
        if(resp < 50)
            resp = costo[resp];
        else{
            loop(i, 0, 50){
                if( (n - i)%15 == 0){
                    resp = min(resp, (n - i)/15 + costo[i]);
                }
            }
        }
        cout<<resp<<"\n";
    }
    return 0;
}