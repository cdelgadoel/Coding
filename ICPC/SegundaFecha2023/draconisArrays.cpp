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

vector<int> build_PI(vector<int> &P) { ///Visualizando indexado en 1
    ///PI[i] guarda el tamanio del prefijo mas grande de P que es sufijo de P[0...i]
    vector<int> PI(P.size());
    PI[0]=0;
    int k=0;
    int i;
    for(i=1;i<P.size();i++) {
        while(k>0 && P[k]!=P[i]) k=PI[k-1];
        if(P[k]==P[i]) k++;
        PI[i]=k;
    }
    return PI;
}

int KMP_Match(vector<int> &T , vector<int> &P) {
    int numberOfMatches = 0;
    vector<int> PI=build_PI(P);
    int q=0;
    for(int i=0;i<T.size();i++) {
        while(q>0 && P[q]!=T[i]) q=PI[q-1];
        if(P[q]==T[i]) q++;
        if(q==P.size()) {
            ++numberOfMatches;
            q=PI[q-1];
        }
    }
    return numberOfMatches;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n, m; cin>>m>>n;
    if(m == 1){
        cout<<n<<"\n";
        return 0;
    }
    
    vector<int> M(m), N(n);
    loop(i, 0, m) cin>>M[i];
    loop(i, 0, n) cin>>N[i];
    vector<int> dM(m-1), dN(n-1);
    loop(i, 0, m-1)
        dM[i] = M[i+1] - M[i];
    loop(i, 0, n-1)
        dN[i] = N[i+1] - N[i];
    cout<<KMP_Match(dN, dM)<<"\n";
    return 0;
}