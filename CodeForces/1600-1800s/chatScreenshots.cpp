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

const int maxN = 200005;


int n, k;
map<int, int> nums[maxN];
string solve(){
    cin>>n>>k;
    loop(i, 0, n+1)
        nums[i].clear();
    loop(i, 0, k){
        int last = 0;
        int u; cin>>u;
        loop(j, 0, n-1){
            cin>>u;
            nums[u][last]++;
            last = u;
        }
    }

    if(k == 1)
        return "YES";
    loop(i, 1, n+1){
        if(nums[i].size() > 1){
            if(nums[i].size() > 2)
                return "NO";
            int fi, se;
            fi = nums[i].begin()->second;
            se = (++(nums[i].begin()))->second;
            if(fi > 1 && se > 1)
                return "NO";
        }
    }
    return "YES";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}