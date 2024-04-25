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
typedef pair<int,int> pii;
const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; int Q;
    cin>>n>>Q;
    ll a[n];
    ll ac[n];
    loop(i, 0, n){
        cin>>a[i];
    }

    loop(q, 0, Q){
        ll k; cin>>k;
        ll resp = 0;
        loop(i, 0, n) ac[i] = a[i];
        for(int i = 59; i >= 0; i--){
            //needed
            int it = 0; 
            ll needed = 0;
            while(it < n && needed <= k){
                if( (ac[it]&(1LL<<i)) == 0){
                    needed +=  (1LL<<i) - (((1LL<<i) - 1) & ac[it]);
                }
                ++it;
            }
            if(needed <= k){
                resp |= (1LL<<i);
                k -= needed;
                loop(it, 0, n)
                    if( (a[it]&(1LL<<i)) == 0)
                        ac[it] +=  (1LL<<i) - (((1LL<<i) - 1) & ac[it]);
            }
        }
        cout<<resp<<"\n";
    }
    
    return 0;
}