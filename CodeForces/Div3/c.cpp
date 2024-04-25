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

ll ap[33], bp[33], a, b, l;
set<int> ks;
void solve(){
    cin>>a>>b>>l;
    ap[0] = 1; bp[0] = 1;
    int ita = 0; 
    while(ap[ita] <= l){
        ++ita;
        ap[ita] = ap[ita-1]*a;
    }
    int itb = 0; 
    while(bp[itb] <= l){
        ++itb;
        bp[itb] = bp[itb-1]*b;
    }
    ks.clear();
    loop(i, 0, ita)
    loop(j, 0, itb){
        ll d = ap[i]*bp[j];
        if(d <= l && l%d == 0){
            ks.insert(l/d);
        }
    }
    cout<<ks.size()<<"\n";
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