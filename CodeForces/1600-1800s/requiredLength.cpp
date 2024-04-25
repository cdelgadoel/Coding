#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
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
typedef pair<ll,ll> pll;
const int maxN = 500005;

bool onlyOnesOrZeros(ll x){
    while(x > 0){
        if(x % 10 > 1)
            return false;
        x /= 10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll n, x;
    cin>>n>>x;

    if(onlyOnesOrZeros(x)){
        cout<<-1<<"\n";
        return 0;
    }

    ll power10 = 1;
    loop(i, 0, n-1)
        power10 *= 10;

    queue<pll> bfs;
    unordered_map<ll, bool> v;
    ll resp, d, u, itu, next;
    bool found = false;
    
    bfs.push(pll(x, 0));
    while(!found){
        u = bfs.front().first;
        d = bfs.front().second;
        bfs.pop();
        if(u >= power10){
            found = true;
            cout<<d<<"\n";
        }
        else{
            itu = u;
            while(itu > 0){
                next = u*(itu%10);
                if( next > u && !v[next]){
                    v[next] = true;
                    bfs.push(pll(next, d+1));
                }
                itu /= 10;
            }
        }
    }

    return 0;
}