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

const int maxN = 500005;

ll pots2[64];
ll query(ll x){
    vector<int> bits;
    ll x_ = x;;
    while (x_ > 0){
        bits.push_back(x_&1);
        x_ >>=1;
    }

    ll f[64];
    f[0] = bits[0];
    ll num = bits[0];
    loop(i, 1, bits.size()){
        if(bits[i] == 0){
            f[i] = f[i-1];
        }
        else{
            // cout<<pots2[i-1]<<" "<<num<<" "<<f[i-1];
            f[i] = i*pots2[i-1] + (num+1) + f[i-1];
            num =  pots2[i] + num;
        }
    }
    return f[bits.size()-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    pots2[0] = 1;
    loop(i, 1, 64)
        pots2[i] = pots2[i-1]*2;

    ll a, b;
    cin>>a>>b;
    if(a <= 1)
        cout<<query(b)<<"\n";
    else{
        cout<<query(b) - query(a-1)<<"\n";
    }
    return 0;
}