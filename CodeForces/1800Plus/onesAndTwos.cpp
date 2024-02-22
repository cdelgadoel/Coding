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
const int maxN = 100005;
int n, q;

int sum[maxN], arre[maxN], ones[maxN];
void update(int *bit, int pos, ll x){
    while(pos <= n){
        bit[pos] = bit[pos] + x;
        pos += pos&(-pos);
    }
}

int query(int*bit, int pos){
    int suma = 0;
    while(pos > 0){
        suma = suma + bit[pos];
        pos -= pos&(-pos);
    }
    return suma;
}

int query(int* bit, int pos1, int pos2){
	return query(bit, pos2) - query(bit, pos1-1);
}

int indxLessOrEqual(int num){
    ll ini = 1, fin = n, mitad;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(query(sum, mitad) <= num)
            ini = mitad;
        else
            fin = mitad - 1;
    }
    return ini;
}

int nextOne(int indx){
    ll ini = indx+1, fin = n, mitad;
    ll onesIndx = query(ones, indx);
    if(query(ones, ini) - onesIndx == 1)
        return ini;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(query(ones, mitad) - onesIndx == 0)
            ini = mitad;
        else
            fin = mitad - 1;
    }
    
    return ini==n? -1 : ini+1;
}

void solve(){
    cin>>n>>q;
    ll sumTot = 0;
    fill(ones, ones+n+1, 0);
    fill(sum, sum+n+1, 0);
    loop(i, 1, n+1)
    {
        cin>>arre[i];
        sumTot += arre[i];
        update(sum, i, arre[i]);
        if(arre[i] == 1){
            update(ones, i, 1);
        }
    }

    int op, s, indx, v;
    loop(i, 0, q){
        cin>>op;
        if(op == 1){
            cin>>s;
            if(sumTot < s){
                cout<<"NO\n";
                continue;
            }
            int indxL = indxLessOrEqual(s);
            if(query(sum, indxL) == s){
                cout<<"YES\n";
                continue;
            }
            
            int indx1 = nextOne(0);
            int indx2 = nextOne(indxL);
            bool resp;
            if(indx1 != -1 && indx2 != -1)
                resp = true;
            //this implies both are -1
            // cannot have only indx1 -1 and not indx2
            else if(indx1 == -1)
                resp = false;
            else if(indx2 == -1){
                resp = n-indxL >= indx1;
            }
            cout<<(resp? "YES\n":"NO\n");    
        }
        else{
            cin>>indx>>v;
            if(v == arre[indx]) continue;
            sumTot += v - arre[indx];
            update(sum, indx, v - arre[indx]);
            update(ones, indx, v==1? 1 : -1);
            arre[indx] = v;
        }
    }
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