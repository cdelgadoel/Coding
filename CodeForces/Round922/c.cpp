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

ll a, b, r;
int aa[64], ab[64], ar[64];

void creaA(ll x, int ax[64]){
    for(int i = 0; i < 63; ++i){
        if( (x&(1LL<<i)))
        {
            ax[i]=1;
        }
    }   
}

void solve(){
    cin>>a>>b>>r;
    fill(aa, aa+64, 0);
    fill(ab, ab+64, 0);
    fill(ar, ar+64, 0);

    for(ll i = 0; i < 63; ++i){
        if( (a&(1LL<<i)) && (b&(1LL<<i)))
        {
            a^=(1LL<<i);
            b^=(1LL<<i);
        }
    }
    if(a < b)
        swap(a, b);
    creaA(a, aa);
    creaA(b, ab);
    creaA(r, ar);

    loop(i, 0, 63){
        if(ab[i] == 1)
            ab[i] = -1;
    }

    int i1 = 62;
    while(i1 > -1 && aa[i1] == 0)
        --i1;
    int i2 = 62;
    while(i2 > -1 && !(ar[i2] == 1 && aa[i2] == 0)){
        if(ar[i2] == 1 && aa[i2] == 1){
            if(i2 == i1) 
                break;
            aa[i2] = -1;
        }
        --i2;
    }

    int i = min(i1-1, i2);
    while(i > -1){
        if(aa[i] == 1)
            aa[i] = -1;
        --i;
    }

    ll resp = 0;
    for(int i = 0; i < 63; ++i){
        resp += aa[i]*(1LL<<i) + ab[i]*(1LL<<i);
    }
    cout<<resp<<"\n";
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