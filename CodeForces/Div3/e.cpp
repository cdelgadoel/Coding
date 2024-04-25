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
int n, a[maxN], s[maxN];

int sumr(int l, int r){
    return l == 0? s[r] :s[r] - s[l-1];
}

void solve(){
    cin>>n;
    loop(i, 0, n) {cin>>a[i]; s[i] = a[i];}
    loop(i, 1, n) s[i] += s[i-1];

    ll q, l, u, r, resp;
    ll ini, fin, mid;
    cin>>q;
    loop(Q, 0, q){
        cin>>l>>u;
        --l;
        
        if(sumr(l, l) >= u+1)
            resp = l;
        else if(sumr(l, n-1) <= u)
            resp = n-1;
        else{
            ini = l;
            fin = n-1;
            while(ini != fin){
                mid = (ini + fin)/2;
                if(sumr(l, mid) >= u+1){
                    fin = mid;
                }
                else{
                    ini = mid+1;
                }
                //cout<<ini<<" "<<fin<<endl;
            }
            if(ini != l){
                ll b = sumr(l, ini-1), bi = sumr(l, ini);
                ll extra = bi - (u+1);
                if( u*b - (b*(b-1)/2) >= u*(u+1)/2 - extra*(extra+1)/2) 
                    resp = ini-1;
                else
                    resp = ini;
            }
            else   
                resp = ini;
        }
        cout<<1+resp<<" \n"[Q == q-1];
        
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