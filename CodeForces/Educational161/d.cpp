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

ll a[maxN], d[maxN], cl[maxN], cr[maxN], l[maxN];
bool v[maxN];
int n;
void solve(){
    cin>>n;
    loop(i, 1, n+1)
        cin>>a[i];
    loop(i, 1, n+1)
        cin>>d[i];
    a[0] = a[n+1] = 0;
    iota(cl+1, cl+n+1, 0);
    iota(cr+1, cr+n+1, 2);
    fill(v+1, v+n+1, 0);
    // loop(i, 1, n+1)
    //     cout<<cr[i]<<" ";
    // cout<<endl;
    stack<int> s1, s2;
    stack<int> *dies, *ndies;
    dies = &s1; ndies = &s2;

    loop(i, 1, n+1){
        l[i] = d[i] - (a[cl[i]] + a[cr[i]]);
        if(l[i] < 0){
            dies->push(i);
            v[i] = true;
        }
    }

    int diedRound, id;
    int tmpcl, tmpcr;
    
    loop(times, 0, n){
        diedRound = 0;
        while(!(dies->empty())){
            id = dies->top(); dies->pop();
            ++diedRound;
            //cout<<times<<" "<<id<<endl;
            tmpcl = cl[id];
            tmpcr = cr[id];
            //cout<<tmpcl<<" "<<tmpcr<<endl;
            cl[tmpcr] = tmpcl;
            cr[tmpcl] = tmpcr;
            
            int i = tmpcl;
            if( i > 0 && i < n+1){
                ndies->push(i);
            } 
            i = tmpcr;
            if(i > 0 && i < n+1){
                ndies->push(i);
            } 
        }
        cout<<diedRound<<" \n"[times == n-1];
        while(!(ndies->empty())){
            int i = ndies ->top();
            ndies -> pop();
            if(v[i]) continue;
            l[i] = d[i] - (a[cl[i]] + a[cr[i]]);
            if(l[i] < 0){
                //cout<<"entro "<<i<<" "<<cl[i]<<" "<<cr[i]<<endl;
                dies->push(i);
                v[i] = true;
            }
        }
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