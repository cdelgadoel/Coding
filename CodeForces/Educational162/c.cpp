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
ll n, q, a[maxN];
ll ones[maxN];
ll sum[maxN];

ll onesR(int l, int r){
    if(l == 0)
        return ones[r];
    else
        return ones[r] - ones[l-1];
}

ll sumR(int l, int r){
    if(l == 0)
        return sum[r];
    else
        return sum[r] - sum[l-1];
}

void solve(){
    cin>>n>>q; loop(i, 0, n) cin>>a[i];
    fill(ones, ones+n+1, 0);
    fill(sum, sum + n+1, 0);
    loop(i, 0, n){
        if(a[i] == 1)
            ones[i] = 1;
        sum[i] = a[i];    }
    loop(i, 1, n){
        ones[i] += ones[i-1];
        sum[i] += sum[i-1];
    }

    int l, r;
    loop(i, 0, q){
        cin>>l>>r;
        --l; --r;
        //cout<<"l r"<<endl;
        if(l == r)
            cout<<"NO\n";
        else if( r - l + 1 - onesR(l, r) >= onesR(l, r)){
            //cout<<l<<" "<<r<<" "<<onesR(l, r)<<endl;
            //cout<<"ak"<<endl;
            cout<<"YES\n";
        }
        else if(sumR(l, r) -  onesR(l, r) + onesR(l, r) >=  2*onesR(l, r) + (r - l + 1 - onesR(l, r))){
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
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