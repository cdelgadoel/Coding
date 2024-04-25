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
const int maxN = 200005;
int n, a[maxN];
string solve(){
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    
    sort(a, a+n);
    if(a[0] != a[1])
        return "YES";
    else{
        loop(i, 1, n){
            if(a[i]%a[0] != 0)
                return "YES";
        }
        return "NO";
    }
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