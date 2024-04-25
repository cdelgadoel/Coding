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
typedef pair<pii, int> pi;
const int maxN = 1002;
int n, m, a[maxN][maxN], v[maxN][maxN];
queue<pair<pii, int> >q;
void solve(){
    cin>>n>>m;
    loop(i, 0, n)
    loop(j, 0, m)
    {
        cin>>a[i][j];
        v[i][j] = 0;
    }
    while(!q.empty())
        q.pop();

    q.push(pi(pii(0, 0), 0));
    v[0][0] =1;
    
    int f, s, d, df, nf, ns;
    int resp = 10000000;
    while(!q.empty()){
        f = q.front().first.first;
        s = q.front().first.second;
        d = q.front().second;
        //cout<<f<<" "<<s<<" "<<d<<endl;
        q.pop();

        if(s == m-1){
            df = abs((f%n) - ((n-1+d)%n));
            //cout<<"llego "<<df <<" "<<n - df<<endl;
            resp = min(resp, d +  min(df, n - df));
        }

        nf = (f+1) % n; ns = (s+1)%m;
        if( v[nf][ns] != 1 && a[nf][ns] != 1){
            v[nf][ns] = 1;
            q.push(pi(pii(nf, ns), d+1));
        }

        nf = (f+2) % n; ns = s;
        if( v[nf][ns] != 1 && a[(f+1)%n][s] != 1 && a[nf][ns] != 1){
            v[nf][ns] = 1;
            q.push(pi(pii(nf, ns), d+1));
        }
    }
    if(resp == 10000000)
        resp = -1;
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