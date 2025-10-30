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
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 500005;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    
    int iniClosed = 0, iniOpen = 0;
    for(int i = 1; i < n; i+=2)
        if(s[i] == '(')
            ++iniOpen;
        else    
            ++iniClosed;
    int sum = 0;
    loop(i, 0, n){
        if(sum > 0 && iniOpen > 0){
            s[i] = ')';
            --iniOpen;
            --sum;
        }
        else{
            s[i] = '(';
            --iniClosed;
            ++sum;
        }
        ++i;
        
        if(s[i] == '(')
            ++sum;
        else
            --sum;
    }

    stack<int> activePos;
    ll resp = 0;
    loop(i, 0, n){
        if(s[i] == '('){
            activePos.push(i);
        }
        else{
            int openBracketPos = activePos.top();
            resp += i - openBracketPos;
            activePos.pop();
        }
    }
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