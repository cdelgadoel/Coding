#include <iostream>
#include <algorithm>
#include <cstdint>
#define MOD 1000000007
#define loop(i,a,b) for(ll i = a; i < b; ++i)
#define sum(a, b) (((a)+(b))%MOD)
#define mul(a, b) (((a)*(b))%MOD)
using namespace std;
typedef int64_t ll;
const int maxK = 1e6+5;

ll binPow(ll base, ll exp){
    ll r = 1;
    while (exp > 0){
        if( exp & 1)
            r = (r*base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return r;
} 

ll k, n;
ll prods[maxK], pots[maxK], invPots[maxK];
void init(int limit){
    prods[0] = 1;
    loop(i, 1, limit+1){
        prods[i] = mul(prods[i-1], (n-i)%MOD);
    }
    pots[0] = 1;
    invPots[0] = 1;
    loop(i, 1, limit+1){
        pots[i] = mul(pots[i-1], n%MOD);
        invPots[i] = binPow(pots[i], MOD-2);
    }
}

ll solve1(){
    ll resp = 0;
    init(n);
    ll term;    
    loop(i, 2, n+2){
        term = mul(i, i-1);
        term = mul(term, invPots[i-1]);
        term = mul(term, prods[i-2]);
        resp = sum(resp, term);
    }
    return resp;
}

ll solve2(){
    init(k);
    ll resp = 0, term;
    loop(i, 2, k+1){
        term = mul(i, i-1);
        term = mul(term, invPots[i-1]);
        term = mul(term, prods[i-2]);
        resp = sum(resp, term);
    }
    term = sum(mul(k,k-1), n);
    term = mul(mul(mul(term, prods[k-1]), invPots[k-1]), binPow(k-1, MOD-2));
    resp = sum(resp, term);
    return resp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>k;
    cout<<(k > n? solve1() : solve2())<<"\n";
    return 0;

}