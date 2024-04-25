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

const int maxN = 1e6+5;
int n; 
char let[maxN];
int sig[maxN];

int order[maxN];

struct parPrefijo{int ord[2], p;};
bool comp(const parPrefijo &a, const parPrefijo &b){
    if(a.ord[0] == b.ord[0])
        return a.ord[1] < b.ord[1];
    return a.ord[0] < b.ord[0];
}

void sortNames(){
    if(n == 1){
        order[0] = 0;
        return;
    }
    int logN = 0, foo=n;
    while(foo > 0){
        logN += 1;
        foo>>=1;
    }
    int binaryLifting[logN+1][n];
    loop(i, 0, n){
        binaryLifting[0][i] = sig[i];
    }
    int inter;
    loop(level, 1, logN+1){
        loop(i, 0, n){
            inter = binaryLifting[level-1][i];
            //cout<<inter<<endl;
            binaryLifting[level][i] = inter == -1? -1 : binaryLifting[level-1][inter]; 
        }
    }

    int ordenPrefijo[logN+1][n];
    loop(i, 0, n){
        ordenPrefijo[0][i] = let[i]-'A';
    }
    parPrefijo pares[n];
    loop(level, 1, logN+1){
        loop(i, 0, n){
            pares[i].ord[0] = ordenPrefijo[level-1][i];
            pares[i].ord[1] = binaryLifting[level-1][i] == -1? -1 : ordenPrefijo[level-1][binaryLifting[level-1][i]];
            pares[i].p = i;
        }
        sort(pares, pares+n, comp);
        loop(i, 0, n){
            ordenPrefijo[level][pares[i].p] = i>0 && pares[i].ord[0]==pares[i-1].ord[0] && pares[i].ord[1]==pares[i-1].ord[1]? 
                ordenPrefijo[level][pares[i-1].p] : i; 
        }
    }
    loop(i, 0, n){
        order[i] = pares[i].p;
    }
}

bool mayorIgual(int i, const string& s){
    int indxS = 0, v = i;
    for(int indxS = 0; indxS < s.size(); ++indxS, v=sig[v]){
        if(v == -1) return false;
        if(let[v]!=s[indxS])
            return let[v]>s[indxS];
    }
    return true;
}

int lowerBound(const string &s){
    int ini = 0, fin = n, mitad;
    while(ini != fin){
        mitad = (ini + fin)/2;
        if(mayorIgual(order[mitad], s))
            fin = mitad;
        else
            ini = mitad+1;
    }
    return ini;
}

bool sigString(string &s){
    int size = s.size();
    for(int i = size-1; i>=0; --i){
        if(s[i] < 'Z'){
            ++s[i];
            s = s.substr(0, i+1);
            return true;
        }
    }
    return false;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int q;
    cin>>n>>q;
    loop(i, 0, n){
        cin>>let[i]>>sig[i];
        --sig[i];
    }

    sortNames();
    string query;
    int indxm, indxM;
    bool hay;
    loop(i, 0, q){
        cin>>query;
        indxm = lowerBound(query);
        hay = sigString(query);
        indxM = hay? lowerBound(query) : n;
        cout<<indxM-indxm<<"\n";
    }
    return 0; 
}