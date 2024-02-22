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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll a, b;
    char c;
    cin>>a>>c>>b;
    ll s, n = b;
    bool exists = false;
    while(!exists && n <= 1000000){
        s = n/b*a;
        if( n-1 <= s && s <= n*(n-1)/2){
            exists = true;
        }
        else
            n += b;
    }

    if(exists){
        int connect[n+1];
        iota(connect+2, connect + n + 1, 1);
        ll d = n*(n-1)/2 - s; 
        int it = n;
        while(d > 0){
            int maxResto = it-2;
            if( d >= maxResto){
                connect[it] = 1;
                d -= it-2;
            }
            else{
                connect[it] = it-1-d;
                d = 0;
            }
            --it;
        }
        cout<<n<<" "<<n-1<<"\n";
        loop(i, 2, n+1){
            cout<<connect[i]<<" "<<i<<"\n";
        }
    }   
    else{
        cout<<"impossible\n";
    }
    return 0;
}