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
#include <unordered_set>
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

const int maxN = 2e5+5, maxM = 1e6+5;

int n, m;
vector< unordered_set<int> > sets;
int leafM[maxM];
int order[maxN];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>m;
    sets.resize(n+1);
    iota(order+1, order+n+1, 1);
    loop(i, 1, n+1){
        int k; cin>>k;
        // sets[i].resize(k);
        int val;
        loop(j, 0, k){
            cin>>val;
            sets[i].insert(val);
        }
    }

    sort(order + 1, order + n+1, [](int a, int b){return sets[a].size() > sets[b].size();});
    
    loop(i, 1, n+1){
        // process sets[order[i]]
        int toCheck = 0;
        for(int v : sets[order[i]]){
            if(leafM[v] != 0){
                if(toCheck == 0)
                    toCheck = leafM[v];
                else if(sets[leafM[v]].size() < sets[toCheck].size())
                    toCheck = leafM[v];
            }
        }

        if(toCheck == 0){
            for(int v : sets[order[i]]){
                leafM[v] = order[i];
            }
        }
        else{
            for(int v : sets[order[i]]){
                if(sets[toCheck].find(v) == sets[toCheck].end()){
                    cout<<"YES\n"<<toCheck<<" "<<order[i]<<"\n";
                    return 0;
                }
                else
                    leafM[v] = order[i];
            }
        }
    }
    cout<<"NO\n";
    return 0;
}