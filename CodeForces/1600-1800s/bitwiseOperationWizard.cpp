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
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 500005;

int n; vi c;
void solve(){
    cin>>n;
    int m = 0;
    string s;
    loop(i, 1, n){
        cout<<"? "<<m<<" "<<m<<" "<<i<<" "<<i<<endl;
        cin>>s;
        if(s[0] == '<')
            m = i;
    }

    c.clear();
    c.push_back(0);
    loop(i, 1, n){
        cout<<"? "<<m<<" "<<c[0]<<" "<<m<<" "<<i<<endl;
        cin>>s;
        if(s[0] == '=')
            c.push_back(i);
        else if(s[0] == '<'){
            c.clear();
            c.push_back(i);
        }
    }

    int minc = c[0];
    loop(i, 1, sz(c)){
        cout<<"? "<<minc<<" "<<minc<<" "<<c[i]<<" "<<c[i]<<endl;
        cin>>s;
        if(s[0] == '>')
            minc = c[i];
    }
    cout<<"! "<<m<<" "<<minc<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}