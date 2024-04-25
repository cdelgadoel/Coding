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
const int maxN = 300005;

ll a[maxN], sum[maxN], sigD[maxN], antd[maxN], resp[maxN];
int n; 

ll sumr(int l, int r){return l == 0? sum[r]:sum[r] - sum[l-1];}
 
void solve(){
    int n; cin>>n;
    loop(i, 0, n){
        cin>>a[i];
        resp[i] = maxN;
    }

    loop(side, 0, 2){
        sum[0] = a[0];
        loop(i, 1, n) sum[i] = sum[i-1] + a[i];
        
        antd[0] = -1;
        loop(i, 1, n)
            antd[i] = a[i] != a[i-1]? i-1 : antd[i-1];
    
        ll ini, fin, m;
        loop(i, 1, n){  
            int ir = side==0? i : n-1-i;
            if(sumr(0, i-1) <= a[i] || (a[i-1] <= a[i] && antd[i-1] == -1) ) continue;
            if(a[i-1] > a[i])
                resp[ ir ] = 1; 
            else{
                ini = 0; fin = antd[i-1];
                while(ini != fin){
                    m = (ini + fin + 1)/2; 
                    if(sumr(m, i-1) > a[i])
                        ini = m;
                    else
                        fin = m-1;
                }
                resp[ ir ] = min(resp[ir], i - ini);
            }
        }
        reverse(a, a+n);
    }

    loop(i, 0, n)
        cout<<(resp[i]<maxN? resp[i] : -1)<<" \n"[i == n-1];
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