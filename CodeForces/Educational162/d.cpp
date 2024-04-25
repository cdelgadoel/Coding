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

ll a[maxN], sum[maxN], sigD[maxN], antD[maxN], resp[maxN];
int n; 

ll sumR(int l, int r){
    if(l == 0)
        return sum[r];
    else
        return sum[r] - sum[l-1];
}
 
void solve(){
    int n; cin>>n;
    loop(i, 0, n){
        cin>>a[i];
        sum[i] = a[i];
    }
    loop(i, 1, n)
        sum[i] += sum[i-1];

    antD[0] = -1;
    loop(i, 1, n){
        if(a[i] != a[i-1])
            antD[i] = i-1;
        else
            antD[i] = antD[i-1];
    }

    sigD[n-1] = -1;
    for(int i = n-2; i >= 0; --i){
        if(a[i] != a[i+1])
            sigD[i] = i+1;
        else
            sigD[i] = sigD[i+1];
    }
    
    bool comen;
    ll ini, fin, m;
    loop(i, 0, n){
        comen = false;
        resp[i] = -1;
        if(i > 0){  
            if(a[i-1] > a[i]){
                comen = true;
                resp[i] = 1; 
            }
            else if(sumR(0, i-1) > a[i] && antD[i-1] > -1){
                comen = true;
                ini = 0; fin = antD[i-1];
                //cout<<i<<" bina "<<ini<<" "<<fin<<endl;
                while(ini != fin){
                    m = (ini + fin + 1)/2; 
                    if(sumR(m, i-1) > a[i]){
                        ini = m;
                    }
                    else {
                        fin = m-1;
                    }
                }
                resp[i] = i - ini;
            }
        }
        if(i < n-1){
            if(a[i+1] > a[i]){
                comen = true;
                resp[i] = 1; 
            }
            else if(sumR(i+1, n-1) > a[i] && sigD[i+1] > -1){
                comen = true;
                ini = sigD[i+1]; fin = n-1;
                //cout<<i<<" bind "<<ini<<" "<<fin<<endl;
                while(ini != fin){
                    m = (ini + fin)/2; 
                    if(sumR(i+1, m) > a[i]){
                        fin = m;
                    }
                    else {
                        ini = m+1;
                    }
                }
                if(resp[i] == -1)
                    resp[i] = ini - i;
                else
                    resp[i] = min(resp[i], ini-i);
            }
        }
        if(comen == false){
            resp[i] = -1;
        }
    }

    loop(i, 0, n)
        cout<<resp[i]<<" \n"[i == n-1];
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