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

stack<int> bits;
vector<int> arre;
void solve(){
    ll n; cin>>n;
    while(n > 0){
        bits.push(n&1);
        n>>=1;
    }
    ll resp = 1, min = 0, max = 0;

    bits.pop();
    while(!bits.empty()){
        int nex = bits.top(); 
        bits.pop();
        arre.push_back(++max);
        if(nex == 1){
            arre.push_back(min);
        }
    }
    cout<<arre.size()<<"\n";
    loop(i, 0, arre.size())
        cout<<arre[i]<<" \n"[i == arre.size()-1];
    arre.clear();
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