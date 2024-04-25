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
int n, m;
set<int> alive;

bool complie(int x, int y, int z, int p){
    if(p < 4){
        if(x&1) 
            z = z ^ 1;
        // ymod4
        y%=4;
        if(p<2){
            if(y > 1)
                z = z^1;
        }
        else{
            if(y == 1 || y == 2)
                z = z^1;
        }
        if(p == 0 || p == 2) return z == 1;
        else return z==0;
    }
    else{
        return complie(y, n - 1 - x, z, p-4);
    }
    // if(p>3){
    //     return complie(y, n-1-x, z, p-4);
    // }
    // if(p > 1){
    //     --y;
    //     p-=2;
    // }
    // if(p==1)
    //     z^=1;
    // x%=2; y%=4;
    // if(y > 1)  
    //     z^=1;
    // return x==0? z==1 : z==0;
}

void solve(){
    int q; cin>>n>>m>>q;
    
    loop(i, 0, 8) alive.insert(i);
    cout<<alive.size()<<"\n";
    
    int x, y, z; string f;
    loop(i, 0, q){
        cin>>x>>y>>f;
        --x; --y;
        z = f == "circle";
        loop(i, 0, 8){
            if(!complie(x, y, z, i))
                alive.erase(i);
        }
        cout<<alive.size()<<"\n";
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