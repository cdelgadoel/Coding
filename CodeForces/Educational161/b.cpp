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

int n; 
int bucket[maxN];
void solve(){
    cin>>n;
    fill(bucket, bucket+n+1, 0);
    loop(i, 0, n){
        int k; cin>>k;
        ++bucket[k];
    }
    ll sumPast = 0, resp = 0, b;
    loop(i, 0, n+1){
        b = bucket[i];
        resp += b*(b-1)*(b-2)/6; 
        if( i > 0){
            resp += b*(b-1)/2 * sumPast;
        }
        sumPast += b;
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