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
typedef pair<int,int> pii;
const int maxN = 500005;

int l[maxN], r[maxN], cambia[maxN], indxP[maxN];
int a[maxN], n, k;
string s;
void solve(){
    cin>>n>>k;
    cin>>s;
    loop(i, 0, k) {cin>>l[i]; --l[i];}
    loop(i, 0, k) {cin>>r[i]; --r[i];}

    loop(i, 0, k){
        loop(j, l[i], r[i]+1) 
            indxP[j] = i;
    }

    fill(cambia, cambia+n+1, 0);
    int x, ix, q;
    cin>>q;
    loop(i, 0, q){
        cin>>x; --x;
        ix = indxP[x];
        x = min(x, l[ix] + r[ix] - x);
        //cout<<x<<endl;
        cambia[x] ^= 1;
    }

    int cambioAcum;
    loop(i, 0, k){
        cambioAcum = 0;
        loop(j, 0, (r[i] - l[i] + 1)/2){
            cambioAcum ^= cambia[l[i] + j];
            if(cambioAcum)
                swap(s[l[i] + j], s[r[i] - j]);
        }
    }
    cout<<s<<"\n";

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