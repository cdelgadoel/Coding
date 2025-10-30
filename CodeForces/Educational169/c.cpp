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
#include <cstdint>
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

ll a[maxN];
void solve(){
    ll n, k; cin>>n>>k;
    loop(i, 0, n)
        cin>>a[i];
    sort(a, a+n);
    reverse(a, a+n);

    ll A = 0, B = 0;
    for(int i = 1; i < n; i += 2){
        if(a[i-1] - a[i] <= k){
            k -= a[i-1] - a[i];
            a[i] = a[i-1];
        }
        else{
            a[i] += k;
            k = 0;
        }
    }
    loop(i, 0, n){
        if(i&1)
            B += a[i];
        else
            A += a[i];
    }
    cout<<(A-B)<<"\n";
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