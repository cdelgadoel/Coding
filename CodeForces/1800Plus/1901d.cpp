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
const int maxN = 300005;
ll n, a[maxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    loop(i, 0, n) cin>>a[i];
    
    ll izq[maxN], der[maxN];
    loop(i, 0, n){
        izq[i] = a[i] + n - i - 1;
        der[i] = a[i] + i;
    }

    loop(i, 1, n)
        izq[i] = max(izq[i], izq[i-1]);
    for(int i = n-2; i >= 0; --i)
        der[i] = max(der[i], der[i+1]);
    
    ll resp = 2e9, respCase;
    loop(i, 0, n){
        respCase = a[i];
        if(i > 0)
            respCase = max(respCase, izq[i-1]);
        if(i < n-1)
            respCase = max(respCase, der[i+1]);
        resp = min(resp, respCase);
    }
    cout<<resp<<"\n";
    
    return 0;
}