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
typedef pair<ll,ll> pii;
const int maxN = 500005;

int n; 
pii resp = pii(0, 1);

ll gcd(ll a, ll b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

void update(pii o){
    ll g = gcd(o.first, o.second);
    o.first/=g;
    o.second/=g;
    if(resp.second * o.first > resp.first*o.second){
        resp = o;
    }
}

void solve(vector<int>& h){
    stack<int> s; 
    ll nu, d;
    for(int i = n-1; i>=0; --i){
        if( !s.empty() && h[s.top()] < h[i]){
            while(!s.empty() && h[s.top()] < h[i])
                s.pop();
            if(!s.empty()){
                nu = h[i] - h[s.top()-1];
                d = h[s.top()] - h[s.top()-1];
                update( pii( nu + d*(s.top()-1-i), d));
            }
        }
        s.push(i);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    vector<int> h(n);
    loop(i, 0, n) cin>>h[i];
    solve(h);
    reverse(h.begin(), h.end());
    solve(h);
    if(resp.second == 1){
        cout<<resp.first<<"\n";
    }
    else{
        cout<<resp.first<<"/"<<resp.second<<"\n";
    }
    return 0;
}