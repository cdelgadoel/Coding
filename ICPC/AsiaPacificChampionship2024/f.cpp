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

const int maxN = 1e6 + 5;

pl resp;
int n;
vector<int> skills(maxN), sums(maxN);
multiset<int> ordered_sums;

vector<int> get_prime_factors(int x){
    vector<int> primes;
    for(int p = 2; p*p <= x; ++p){
        if(x%p == 0){
            primes.push_back(p);
            while(x%p == 0)
                x/=p;
        }
    }
    if( x > 1)
        primes.push_back(x);
    return primes;
}

void update_resp(pl other){
    resp = min(resp, other);
}

pl min(pl a, pl b){ return a.first * b.second < a.second * b.first? a : b;}

pl get_min_ratio(){
    return pl(*(--ordered_sums.end()), *ordered_sums.begin());
}

pi get_min_k_groups(int k){
    fill(sums.begin(), sums.begin() + k, 0);
    ordered_sums.clear();

    // initialize group sums
    loop(i, 0, n)
        sums[i%k] += skills[i];
    loop(i, 0, k)
        ordered_sums.insert(sums[i]);
    pi resp_case = get_min_ratio();

    loop(i, 1, n){
        ordered_sums.erase(ordered_sums.find(sums[(i-1)%k]));
        ordered_sums.erase(ordered_sums.find(sums[(i)%k]));

        sums[i%k] = sums[i%k] - skills[i] + skills[0];
        sums[(i-1)%k] = sums[(i-1)%k] - skills[0] + skills[i];

        ordered_sums.insert(sums[(i-1)%k]);
        ordered_sums.insert(sums[i%k]);

        resp_case = min(resp_case, get_min_ratio());
    }
    return resp_case;
}

void solve(){
    cin>>n;
    loop(i, 0, n) 
        cin>>skills[i];
    vector<int> primes = get_prime_factors(n);
    resp = pl(1000, 1);
    for(int p : primes){
        resp = min(resp, get_min_k_groups(p));
    }
    int g = __gcd(resp.first, resp.second);
    resp.first /= g; resp.second /= g;
    cout<<resp.first<<" "<<resp.second<<"\n";
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