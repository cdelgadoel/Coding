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
#include <unordered_map>
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

const int maxN = 200005;

unordered_map<string, set<int> >uppers, lowers;
vector<string> types;
string a[maxN];

bool shareColor(string& x, string& y){
    return x[0] == y[0] || x[0] == y[1] || x[1] == y[0] || x[1] == y[1];
}

void solve(){
    for(string s : types)
    {
        uppers.clear();
        lowers.clear();
    }

    int n, q;
    cin>>n>>q;
    loop(i, 0, n){
        cin>>a[i];
        uppers[a[i]].insert(i);
        lowers[a[i]].insert(-i);
    }

    int ini, fin;
    loop(i, 0, q){
        cin>>ini>>fin;
        --ini; --fin;
        if(ini > fin) swap(ini, fin);
        int ans = 1000000000;
        if(shareColor(a[ini], a[fin])){
            ans = fin-ini;
        }
        else{
            int pos;
            for(string s : types){
                if(uppers[s].size() == 0 || !shareColor(s, a[ini]) || !shareColor(s, a[fin])){
                    continue;
                }
                auto it = uppers[s].upper_bound(ini);
                if(it != uppers[s].end()){
                    pos = *it;
                    if(pos < fin)
                        ans = fin - ini;
                    else 
                        ans = min(ans, abs(pos - ini) + abs(pos - fin));
                }
                it = lowers[s].upper_bound(-fin);
                if(it != lowers[s].end()){
                    pos = - (*it);
                    if(pos > ini)
                        ans = fin - ini;
                    else
                        ans = min(ans, abs(ini-pos) + abs(fin - pos));
                }
            }
        }
        if(ans == 1000000000){
            cout<<"-1\n";
        }
        else
            cout<<ans<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    types.push_back("BG");
    types.push_back("BR");
    types.push_back("BY");
    types.push_back("GR");
    types.push_back("GY");
    types.push_back("RY");
    while(t--){
        solve();
    }
    return 0;
}