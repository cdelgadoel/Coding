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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n, k; cin>>k>>n;
    int in[2][k], resp[3][n];
    F0R(i, 3) F0R(j, n) fill(resp[i], resp[i] + n, -1);
    vector<int> p[4][4];
    F0R(i, k) cin>>in[0][i];
    F0R(i, k) cin>>in[1][i];
    F0R(i, k) {
        int a = in[0][i], b = in[1][i];
        p[b][a].push_back(i+1);
    }
    
    int it = 0;
    for(int ancho = 2; ancho <= 3; ++ancho){
        for(int ik : p[3][ancho]){
            F0R(i, 3) F0R(j, ancho) resp[i][it+j] = ik;
            it += ancho;
        }
    }

    for(int ik: p[2][2]){
        F0R(i, 2) F0R(j, 2) resp[i][it+j] = ik;
        it += 2;
    }

    int it2s = 0;
    while(it2s < sz(p[2][1]) && it < n){
        int ik = p[2][1][it2s];
        F0R(i, 2) resp[i][it] = ik;
        ++it; ++it2s;
    }

    if(it < n){
        //rellenar de unos todo lo que queda con unos
        int it1s = 0;
        // cout<<"indexes 1s"<<endl;
        // loop(i, 0, p[1][1].size())
        //     cout<<p[1][1][i]<<" ";
        // cout<<endl;
        while(startTwos < it){
            int ik = p[1][1][it1s];
            resp[2][startTwos] = ik;
            ++it1s; ++startTwos;
        }
        while(it < n){
            resp[0][it] = p[1][1][it1s++];
            resp[1][it] = p[1][1][it1s++];  
            resp[2][it] = p[1][1][it1s++]; 
            ++it;
        }
    }else{
        //usar los de 2x1 horizontales en la tercera fila
        while(it2s < sz(p[2][1])){
            int ik = p[2][1][it2s];
            F0R(j, 2) resp[2][startTwos+j] = ik;
            startTwos += 2;
            ++it2s;
        }
        // rellenar lo que queda con unos
        for(int ik: p[1][1]){
            cout<<ik<<endl;
            resp[2][startTwos] = ik;
            ++startTwos;
        }
    }

    F0R(i, 3) F0R(j, n){
        cout<<resp[i][j]<<" \n"[j==n-1];
    }

    return 0;
}