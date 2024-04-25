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

const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    ll n; cin>>n;
    vector<ll> primes;
    vector<ll> pots;
    for(ll i = 2; i*i <=n ; ++i){
        if(n%i == 0){
          primes.push_back(i);
          ll p = 0;
          while(n%i == 0){
            n/=i;  
            ++p;
          }
          pots.push_back(p);
        }
    }
    if(n != 1){
        primes.push_back(n);
        pots.push_back(1);
    }

    if( (primes.size() == 1 && pots[0]&1) || 
        (primes.size() == 2 && pots[0] == 1 && pots[1] == 1))
        cout<<"Y\n";
    else 
        cout<<"N\n";

    return 0;
}