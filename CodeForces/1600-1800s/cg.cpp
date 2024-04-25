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
const int maxN = 20;

int n, m, k; 
char h[maxN][maxN];
char v[maxN][maxN];
void solve(){
    cin>>n>>m>>k;
    if(k < n-1 + m-1){
        cout<<"NO\n";
        return;
    }
    if( abs(k - (n-1) - (m-1))&1){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    loop(i, 0, n)
        fill(h[i], h[i]+m-1, 'B');
    loop(i, 0, n-1)
        fill(v[i], v[i]+m, 'B');
        
    h[0][0] = h[1][0] = 'B';
    v[0][1] = 'R';
    char c = 'B';
    loop(i, 0, n-1){
        v[i][0] = c;
        c ^= 'B' ^ 'R';
    }
    loop(j, 0, m-1){
        h[n-1][j] = c;
        c ^= 'B' ^ 'R';
    }

    h[n-2][m-2] = c^'B'^'R';
    v[n-2][m-2] = v[n-2][m-1] = c;

    loop(i, 0, n)
    loop(j, 0, m-1){
        cout<<h[i][j]<<" \n"[j==m-2];
    }

    loop(i, 0, n-1)
    loop(j, 0, m){
        cout<<v[i][j]<<" \n"[j==m-1];
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