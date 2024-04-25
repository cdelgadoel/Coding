#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
typedef int64_t ll;

const int maxN = 1e4 + 5;
int n;
ll h, alfa, mi_beta;
ll x[maxN], y[maxN];
ll maxDiametroIzq[maxN], maxDiametroDer[maxN];

ll calculaMaxDiametroIzq(int i){
    ll diametro = 2*(h - y[i]);
    //auxiliares
    ll a, b;
    for(int j = i-1; j>=0; --j){
        a = x[i]-x[j];
        b = h - y[j];
        diametro = min(diametro, 2*(a+b)+ (ll)sqrt(8*a*b));
    }
    return diametro;
}

ll calculaMaxDiametroDer(int i){
    ll diametro = 2*(h - y[i]);
    //auxiliares
    ll a, b;
    for(int j= i+1; j <= n-1; ++j){
        a = x[j] - x[i];
        b = h - y[j];
        diametro = min(diametro, 2*(a+b)+ (ll)sqrt(8*a*b));
    }
    return diametro;
}

bool visited[maxN];
ll dp[maxN];
ll DP(int i){
    if(i == n-1) 
        return alfa*(h-y[i]);
    if(!visited[i]){
        visited[i] = true;
        bool possibleYet = false;
        dp[i] = INT64_MAX;
        for(int j=i+1; j<n;++j){
            if(x[j]-x[i] > maxDiametroDer[i])
                break;
            if(x[j]-x[i] > maxDiametroIzq[j] || DP(j) < 0)
                continue;
            possibleYet = true;
            dp[i] = min(dp[i], DP(j) + mi_beta*(x[j]-x[i])*(x[j]-x[i]));
        }
        if(!possibleYet)
            dp[i] = -1;
        else
            dp[i] += alfa*(h-y[i]);
    }
    return dp[i];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>h>>alfa>>mi_beta;
    for(int i = 0; i < n; ++i)
    {
        cin>>x[i]>>y[i];
    }

    for(int i = 0; i < n; ++i){
        maxDiametroIzq[i] = calculaMaxDiametroIzq(i);
        maxDiametroDer[i] = calculaMaxDiametroDer(i);
    }

    ll resp = DP(0);
    if(resp < 0)
        cout<<"impossible\n";
    else
        cout<<resp<<"\n";
    return 0; 
}