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
int n; int a[maxN];
bool solve(){
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    bool dropped = false;
    loop(i, 0, n-1){
        if(a[i] > a[i+1]){
            if(dropped)
                return false;
            dropped = true;
            if(i != 0){
                if(a[i-1] > a[i+1])
                    a[i+1] = a[i];
                else if(a[i-1] == a[i+1])
                    ++a[i+1];
            }
        }
        else if(a[i] == a[i+1]){
            ++a[i+1];
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<(solve()? "YES\n" : "NO\n");
    }
    return 0;
}