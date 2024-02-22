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
int n; pii p[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n)
        cin>>p[i].first;
    loop(i, 0,n)
        cin>>p[i].second;
    sort(p, p+n);
    loop(i, 0, n)
        cout<<p[i].first<<" \n"[i == n-1];
    loop(i, 0,n)
        cout<<p[i].second<<" \n"[i == n-1];
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