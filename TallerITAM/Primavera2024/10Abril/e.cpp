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

const int maxN = 1005;
int n; 
int entry[maxN], out[maxN], f[2*maxN];

int find(int a){return f[a] == a? a : f[a] = find(f[a]);}
void unite(int a, int b){
    int fa = find(a), fb = find(b);
    if(fa != fb) f[fb] = fa;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    loop(i, 0, 2*n){
        int a; cin>>a;
        if(a > 0)
            entry[a] = i;
        else
            out[-a] = i;
    }

    iota(f, f+2*n+5, 0);
    loop(i, 1, n+1)
    loop(j, i+1, n+1){
        if( (entry[i] < entry[j] && entry[j] < out[i] && out[i] < out[j])
            || (entry[j] < entry[i] && entry[i] < out[j] && out[j] < out[i]))
        {
            // no pueden pertencer al mismo cluster
            unite(i, j+n);
            unite(j, i+n);
        }
    }

    loop(i, 1, n+1){
        if(find(i) != find(2*n+1) && find(i) != find(2*n+2)){
            unite(i, 2*n+1);
            unite(i+n, 2*n+2);
        }
    }

    loop(i, 1, n+1){
        if(find(i) == find(i+n)){
            cout<<"*\n";
            return 0;
        }
    }

    loop(i, 1, n+1){
        if(find(i) == find(2*n+1)){
            cout<<"G";
        }
        else if(find(i) == find(2*n+2))
            cout<<"S";
    }
    cout<<"\n";
    return 0;
}