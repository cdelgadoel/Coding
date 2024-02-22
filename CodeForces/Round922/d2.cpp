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
const int maxN = 100005;

ll a[maxN], sum[maxN], dp[maxN];
int n; 

int searchFurthestValid(int indx, ll limit){
    int ini = 1, fin = indx, mid;
    while(ini != fin){
        mid =(ini+fin)/2;
        if(sum[indx] - sum[mid-1] <= limit)
            fin = mid;
        else
            ini = mid+1;
    } 
    return ini;
}

multiset<ll> dps;
int lastIncluded;
bool possible(ll target){
    dps.clear();
    lastIncluded = 1;
    loop(i, 1, n+1){
        if(i == 1 || sum[i-1] <= target){
            dp[i] = a[i];
        }
        else{
            int indx = searchFurthestValid(i-1, target);
            while(lastIncluded < indx-1){
                dps.erase(dps.find(dp[lastIncluded]));
                lastIncluded++;
            }
            dp[i] = a[i] + (*dps.begin());
        }
        dps.insert(dp[i]);
    }
    int furthestEnd = searchFurthestValid(n, target);
    while(lastIncluded < furthestEnd-1){
        dps.erase(dps.find(dp[lastIncluded]));
        ++lastIncluded;
    }
    return  *dps.begin()<= target;
}

void solve(){
    cin>>n;
    ll maxi;
    loop(i, 1, n+1){
        cin>>a[i];
        if(i == 1)
            maxi = a[i];
        else{
            maxi = max(a[i], maxi);
        }
    }
    sum[0] = 0;
    loop(i, 1, n+1){
        sum[i] = a[i];
        sum[i] += sum[i-1];
    }

    ll ini = maxi, fin = 1e14, mid;
    while(ini != fin){ 
        mid = (ini+fin)/2;
        if(possible(mid)){
            fin = mid;
        }
        else
            ini = mid+1;
    }
    cout<<ini<<"\n";
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