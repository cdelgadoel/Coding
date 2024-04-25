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
#include <cstdint>
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

vector<int> build_PI(string &P) { ///Visualizando indexado en 1
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

int KMP_Match(string &T , string &P) {
    vector<int> PI=build_PI(P);
    int q=0;
    for(int i=0;i<T.size();i++) {
        while(q>0 && P[q]!=T[i]) q=PI[q-1];
        if(P[q]==T[i]) q++;
        if(q==P.size()) {
            return i - P.size() + 1;
            q=PI[q-1];
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    string ss; cin>>ss;
    string s2 = ss.substr(1, ss.size()-1);
    s2 += ss;

    int p = (KMP_Match(s2, ss)+1)%ss.size();
    if(p > 0)
        ss = ss.substr(0, p);
    
    string sinv = ss;
    reverse(sinv.begin(), sinv.end());
    sinv += sinv.substr(0, ss.size()-1);
    int pinv = KMP_Match(sinv, ss);
    //pinv = pinv == -1? pinv : ss.size() - pinv;

    ll bucket[ss.size()], bucketi[ss.size()];
    fill(bucket, bucket + ss.size(), 0);
    fill(bucketi, bucketi + ss.size(), 0);
    bucket[0] = 1;
    
    int k; cin>>k;
    int accum = 0, inv = 0, nex;
    char t;
    ll resp = 0;
    loop(i, 0, k){
        cin>>t;
        if(t == 'R' || t == 'L'){
            cin>>nex;
            nex %= ss.size();
            if( (t == 'R' && inv == 0) || (t == 'L' && inv == 1)){
                accum = (accum + nex)%ss.size();
            }
            else{
                accum = (accum + ss.size() - nex)%ss.size();
            }
        }
        // I 
        else{
            inv ^= 1;

        }

        if(inv == 0){
            resp += bucket[accum];
            if(pinv >= 0)
                resp += bucketi[(accum + pinv)%ss.size()];
            ++bucket[accum];
        }
        else{
            resp += bucketi[accum];
            if(pinv >= 0)
                resp += bucket[(accum - pinv + ss.size())%ss.size()];
            ++bucketi[accum];
        }
    }

    cout<<resp<<"\n";
    return 0;
}