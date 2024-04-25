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
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(a) a.size()

#define V vector
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 2e5 + 5, maxPot = 20;
int n, a[maxN], b[maxN];

int sparse[maxN][maxPot], logg[maxN];
void oneTimeInit(){
    logg[1] = 0;
    for(int i = 2; i < maxN; ++i)
        logg[i] = logg[i/2]+1;
}
void fillSparse(){
    int mid;
    for(int indx = 0; indx < n; ++indx)
        sparse[indx][0] = a[indx];

    for(int i = 1; i < maxPot; ++i){
        for(int indx = 0; indx < n; ++indx){
            mid = min( (ll)(n-1), indx+(1LL<<(i-1)));
            sparse[indx][i] = max(sparse[mid][i-1], sparse[indx][i-1]);
        }
    }
}

//regresa el indice del maximo en el rango
//si hay varios, regresa el indice del primero
int maxQuery(int l, int r){
    int size = logg[r-l+1];
    //cout<<"query "<<l<<" "<<r<<" "<<size<<" "<<r-(1LL<<size)+1<<endl;
    int maxiL = sparse[l][size], maxiR = sparse[r-(1LL<<size)+1][size];
    return max(maxiR, maxiL);
}

int valid[maxN];
void solve(){
    fill(valid, valid + n, 0);
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    loop(i, 0, n) cin>>b[i];


    for(int z = 0; z < 2; ++z){
        fillSparse();
        stack<int> p;
        int ini, fin, m;
        
        b[n] = -1;
        p.push(n);
        
        for(int i = n-1; i >= 0; --i){
            while(b[p.top()] >= b[i]){
                p.pop();   
            }

            if(a[i] == b[i]){
                valid[z == 0? i : (n-1-i)] = 1;
            }
            else if(a[i] < b[i] && maxQuery(i, p.top()-1) >= b[i]){
                ini = i; fin = p.top()-1;
                while(ini != fin){
                    m = (ini + fin)/2;
                    if(maxQuery(i, m) >= b[i])
                        fin = m;
                    else
                        ini = m+1;
                }
                if(maxQuery(i, ini) == b[i])
                    valid[z == 0? i : (n-1-i)] = 1;
            } 
            p.push(i);  
        }
        reverse(a, a+n);
        reverse(b, b+n);
    }
    
    int it = 0; 
    while(it < n && valid[it] == 1)
        ++it;
    cout<<(it == n? "YES":"NO")<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    oneTimeInit();
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}