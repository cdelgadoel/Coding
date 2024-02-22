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
const int maxN = 2005, maxK = 500005;

int n, k, d;
int a[maxN], v[maxK];

int currentScore(){
    int score = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i] == i)
            ++score;
    return score;
}
void solve(){
    cin>>n>>k>>d;
    loop(i, 1, n+1) cin>>a[i];
    loop(i, 1, k+1) cin>>v[i];

    // applying operation 2 in the first day
    int resp = currentScore() + (d-1)/2;

    int itV = 1;
    for(int i = 1; i <= min(2*n, d-1); ++i){
        for(int j = 1; j <= v[itV]; ++j)
            ++a[j];
        ++itV;
        if(itV == k+1)
            itV = 1;
        resp = max(resp, currentScore() + (d - i - 1)/2);
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