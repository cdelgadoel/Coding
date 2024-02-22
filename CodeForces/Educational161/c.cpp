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
ll a[maxN], s[maxN], f[maxN], b[maxN];
int n; 

int sigEsElCercano(int x){
    if(x == 0)
        return 1;
    else if(x == n-1)
        return 0;    
    else
        return a[x+1] < a[x]? 1 : 0;

}

void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i];
    }
    for(int i = n-1; i >= 1; --i)
        a[i] -= a[i-1];
    a[0] = 0; 

    s[0] = 0;
    loop(i, 1, n){
        s[i] = a[i];
        s[i] += s[i-1];
    }

    //fw
    loop(i, 0, n-1){
        f[i] = (-a[i+1]+1)*sigEsElCercano(i);
    }
    f[n-1] = 0;
    loop(i, 1, n)
        f[i] += f[i-1];

    b[0] = 0;
    loop(i, 1, n){
        b[i] = (-a[i]+1)*(1-sigEsElCercano(i));
    }
    loop(i, 1, n)
        b[i] += b[i-1];

    int m; cin>>m;
    int x, y; ll resp;
    loop(i, 0, m){
        cin>>x>>y;
        --x; --y;
        resp = abs(s[y] - s[x]);
        if(x > y){
            resp += b[x] - b[y];
        }
        else{
            if(x == 0)
                resp += f[y-1];
            else
                resp += f[y-1] - f[x-1];
        }
        cout<<resp<<'\n';
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