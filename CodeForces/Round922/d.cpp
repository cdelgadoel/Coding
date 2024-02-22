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

ll a[maxN], sum[maxN], dp[maxN], f[4*maxN], l[4*maxN], r[4*maxN];
int n; 

void init(int it, int le, int ri){
    l[it] = le; 
    r[it] = ri;
    f[it] = 0;
    if(le != ri){
        int m = (le+ri)/2;
        init(it<<1, le, m);
        init((it<<1)+1, m+1, ri);
    }
}

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

void update(int indx, ll value){
    int it = 1; 
    while(l[it] != r[it]){
        if(indx <= r[it<<1])
            it <<= 1;
        else
            it = (it<<=1) + 1;
    }
    f[it] = value;
    it >>= 1;
    while(it != 0){
        f[it] = min(f[it<<1], f[(it<<1) + 1]);
        it >>= 1;
    }   
}

ll query(int it, int le, int ri){
    if( r[it] < le || ri < l[it])
        return 1e14;
    if( le <= l[it] && r[it] <= ri)
        return f[it];
    return min(query(it<<1, le, ri), query( (it<<1) + 1, le, ri));
}

bool possible(ll target){
    loop(i, 1, n+1){
        if(i == 1 || sum[i-1] <= target){
            
            dp[i] = a[i];
            //cout<<"fi "<<sum[i-1]<<" "<<dp[i]<<endl;;
        }
        else{
            int indx = searchFurthestValid(i-1, target);
            dp[i] = a[i] + query(1, indx-1, i-1);
            //cout<<"ss "<<indx<<" "<<dp[i]<<endl;;
        }
        //cout<<dp[i]<<" \n";
        update(i, dp[i]);
    }
    int furthestEnd = searchFurthestValid(n, target);
    return query(1, furthestEnd-1, n) <= target;
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
    init(1, 1, n);
    sum[0] = 0;
    loop(i, 1, n+1){
        sum[i] = a[i];
        sum[i] += sum[i-1];
    }

    ll ini = maxi, fin = 1e14, mid;
    while(ini != fin){ 
        
        mid = (ini+fin)/2;
        //cout<<"neewwww "<<mid<<endl;
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