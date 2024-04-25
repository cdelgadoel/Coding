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
int n, a[maxN];

int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int earnsWith(int d){
    int g = 0;
    loop(i, d, n){
        g = gcd(g, abs(a[i]-a[i-d]));
        if(g == 1)
            return 0;
    }
    return 1;
}

void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i];
    }

    int resp = 0;
    for(int i = 1; i * i <= n; ++i){
        if(n%i != 0 ) continue;
        int e = earnsWith(i);
        resp += e;
        if(n/i != i){
            e = earnsWith(n/i);
            resp += e;
        }
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