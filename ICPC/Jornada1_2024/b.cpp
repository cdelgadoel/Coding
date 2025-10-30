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


struct matrix{
    vector< vector<ll> > m;
    ll mod, sz;
    ll mod2;
 
    matrix (ll n,ll modc) : sz(n),m(n), mod(modc) {
        for(int i=0;i<n;i++)
            m[i].resize(n, 0);
        mod2=mod*mod;
    }

    void clean(){
        for(int i=0;i<sz;i++)
            fill(m[i].begin(), m[i].end(), 0);
        m[0][0] = 1;
        m[0][1] = 0;
        m[0][2] = 0;
        m[0][3] = 3;
        m[0][4] = 0;
        m[0][5] = 3;
        m[0][6] = 0;
        m[0][7] = 3;
        m[0][8] = 0;
        m[0][9] = 3;
        m[0][10] = -1;

        m[1][0] = 0;
        m[1][1] = 0;
        m[1][2] = 0;
        m[1][3] = 3;
        m[1][4] = 0;
        m[1][5] = 3;
        m[1][6] = 0;
        m[1][7] = 3;
        m[1][8] = 0;
        m[1][9] = 3;
        m[1][10] = 0;

        loop(i, 2, 11)
            m[i][i-1] = 1;
    }
 
    matrix operator*(matrix b)
    {
        matrix ans(sz,mod);
        for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            for(int u=0;u<sz;u++)
            {
                ans.m[i][u]+=m[i][j]*b.m[j][u];
                if(ans.m[i][u]>=mod2)
                    ans.m[i][u]-=mod2;
            }
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ans.m[i][j]%=mod;
        return ans;
    }
 
    matrix pow(ll e)
    {
        if(e==1)
            return *this;
        matrix x =pow(e/2);
        x=(x*x);
        if(e&1)
            x=(x*(*this));
        return x;
    }
};

const int maxN = 500005;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    int inis[11] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    matrix m(11, MOD);
    m.clean();

    int t, n; cin>>t;
    ll resp;
    loop(i, 0, t){
        cin>>n;
        n>>=1;
        if(n == 0)
            cout<<1<<"\n";
        else{
            matrix x = m.pow(n);
            resp = (x.m[0][0] + x.m[0][1])%MOD;
            cout<<resp<<"\n";
        }
    }
    return 0;
}