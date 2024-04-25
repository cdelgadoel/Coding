#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
 
#define G(x) ll x; cin>>x;
#define F(i,l,r) for (ll i=l; i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second
typedef __int128 bb;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    ll n, m; cin>>n>>m;
    for (ll q=1; q<6000; ++q) {
        if (logl(q)*n > 30*logl(10)) break;
        if (powl(q, n) > powl(10, 30)) break;
        bb qn = 1; for (int i=0; i<n; ++i) qn*=q;
        for (ll p=q-1; p>0; --p) if (__gcd(p, q)==1) {
            bb pn = 1; for (int i=0; i<n; ++i) pn*=p;
            bb thing = (qn-pn)/(q-p);
            if (m%thing==0) {
                cout<<(q-p)<<' '<<q<<endl;
                return 0;
            }
        }
    }
    cout<<"impossible"<<endl;
}
