#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, arre[maxN];
ll s[maxN],d[maxN], tTot;
vector< multiset<pii> >atras, enfrente;
vector<int> respE, respA;

void leeLinea(vector< multiset<pii> > &linea){
    vector<pair<int, pii> > a;
    vector<int> x(n), y(n);

    loop(i, 0, n){
        cin>>x[i];
    }
    loop(i, 0, n){
        cin>>y[i];
    }
    loop(i, 0, n){
        a.push_back(make_pair(x[i], pii(y[i],i)));
    }
    sort(a.begin(), a.end());
    int i = 0;
    while(i != a.size()){
        int repre = a[i].first;
        multiset<pii> sig; 
        while(i != a.size() && a[i].first == repre){
            sig.insert(a[i].second);
            ++i;
        }
        linea.push_back(sig);
    }
}

void solve(){
    cin>>n;

    leeLinea(atras);
    leeLinea(enfrente);
    
    
    int indxA = 0, indxE = 0;
    while(indxA < atras.size() && indxE < enfrente.size()){
        int sizeA = atras[indxA].size();
        int sizeE = enfrente[indxE].size();

        multiset<pii> ::iterator it;
        if(sizeA < sizeE){
            //por cada uno en A borro al mayor que le gano en E
            for(pii v : atras[indxA]){
                it = enfrente[indxE].lower_bound(pii(v.first, -1));
                if(it == enfrente[indxE].begin()){
                    cout<<"impossible\n";
                    return;
                }
                --it;
                respE.push_back(it->second);
                respA.push_back(v.second);

                enfrente[indxE].erase(it);
            }
            ++indxA;
        }
        else{
            //por cada uno en E borro el primero mas grande en A
            for(pii v : enfrente[indxE]){
                it = atras[indxA].upper_bound(pii(v.first,1e6));
                if(it == atras[indxA].end()){
                    cout<<"impossible\n";
                    return;
                }
                respE.push_back(v.second);
                respA.push_back(it->second);
                atras[indxA].erase(it);
            }
            ++indxE;
        }
    }

    loop(i, 0, n){
        if(i > 0) cout<<" ";
        cout<<1+respA[i];
    }
    cout<<"\n";
    loop(i, 0, n){
        if(i > 0) cout<<" ";
        cout<<1+respE[i];
    }
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}