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

int solve(){
    int l, r, L, R;
    cin>>l>>r>>L>>R;
    if(l > L){
        swap(l , L);
        swap(r, R);
    }

    if(r < L)
        return 1;

    int interl = L, interr = min(r, R);    
    int ans = interr - (interl-1) + 1;
    if(r == R) 
        ans--;
    if(l == L) 
        ans--;
    
    return ans;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}