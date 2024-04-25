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

void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i];
    }
    int l = 0, r = n-1;
    while(l < n-1 && a[l] == 0)
        ++l;
    while(r >= 0 && a[r] == 0)
        --r;
    if(l >= r){
        cout<<0<<"\n";
        return;
    }
    
    int resp = 0; 
    loop(i, l, r)
        resp += a[i] == 0;
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