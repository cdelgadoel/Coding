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

const int maxN = 4000005;
int n;
int a[maxN/2], b[maxN/2], ra[maxN/2], rb[maxN/2], bit[maxN];

void update(int pos, int x){
    while(pos <= n){
        bit[pos] = bit[pos] + x;
        pos += pos&(-pos);
    }
}

ll query(int pos){
    ll suma = 0;
    while(pos > 0){
        suma = suma + bit[pos];
        pos -= pos&(-pos);
    }
    return suma;
}

int findK(int k){
    int ini = 1, fin = n, m;
    while(ini != fin){
        m = (ini + fin)/2;
        if(query(m) >= k)
            fin = m;
        else
            ini = m+1;
    }
    return ini;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    FOR(i, 1, n+1){update(i, 1);}

    int newn = n>>1;
    F0R(i, newn) cin>>a[i];
    F0R(i, newn) cin>>b[i];

    int resp;
    F0R(i, newn){
        ra[i] = findK(a[i]); update(ra[i], -1);
        rb[i] = findK(b[i]); update(rb[i], -1);
    }

    F0R(i, newn) cout<<ra[i]<<" \n"[i==newn-1];
    F0R(i, newn) cout<<rb[i]<<" \n"[i==newn-1];

    return 0;
}