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
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 200005;

string s; 
void solve(){
    cin>>s;
    int f = 0, u = 0, minC = -1;
    int it = 0;
    for(char c : s){
        if(c == '+'){
            ++u;
        }
        else if(c=='-'){
            if(u == 0){
                --f;
            }
            else{
                --u;
                if(f + u < minC)
                    minC = -1;
            }
        }
        else if(c == '1'){
            if(minC != -1){
                cout<<"NO\n";
                return;
            }
            f += u;
            u = 0;
        }
        else if(c=='0'){
            if(u == 0 || f+u < 2){
                cout<<"NO\n";
                return;
            }
            minC = minC == -1? f+u : min(minC, f+u); 
            ++it;
        }
    }
    cout<<"YES\n";
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