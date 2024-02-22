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

void solve(){
    int n; cin>>n;
    int sign = 1;
    bool zero = false;
    loop(i, 0,  n){
        int x; cin>>x;
        if(x == 0)
            zero = true;
        else if(x < 0){
            sign *= -1;
        }
    }

    if(zero || sign == -1)
        cout<<0<<"\n";
    else{
        cout<<1<<"\n";
        cout<<"1 0\n";
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