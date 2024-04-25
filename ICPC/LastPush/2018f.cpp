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

vector<pair<int, pi> > d1, d2;
vector<pair<int, pi> > *dp, *dpLast;
int getMaxRiver(const vector<int> &ws, int w){
    dp = &d1;
    dpLast = &d2;
    int fila = 0, col = 0;
    int anterior, misma, desp, riv, resp = 0;
    for(int i = 0; i < sz(ws)-1; ++i){
        col += ws[i];
        if(col + ws[i+1] >= w){
            ++fila;
            col = 0;
            swap(dp, dpLast);
        }
        else{
            if (fila == 0){
                (*dp)[col] = pair(1, pi(fila, w));
            }
            else{
                anterior = (*dpLast)[col-1].second == pi(fila-1, w)? 1+(*dpLast)[col-1].first : -2500;
                misma = (*dpLast)[col].second == pi(fila-1, w)? 1+(*dpLast)[col].first : -2500;
                desp = (*dpLast)[col+1].second == pi(fila-1, w)? 1+(*dpLast)[col+1].first : -2500;
                riv = max(1, max(anterior, max(misma, desp)));
                (*dp)[col] = pair(riv, pi(fila, w));
            }
            resp = max(resp, (*dp)[col].first);
            col += 1;
        }
    }
    return resp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n; cin>>n;
    vector<int> ws;
    int maxWordSize = 0, totalSize = 0;
    loop(i, 0, n){
        string ss; cin>>ss;
        ws.push_back(ss.size());
        totalSize += ss.size();
        if(i < n-1) totalSize += 1;
        maxWordSize = max(maxWordSize, (int)ss.size());
    }

    d1.resize(n*(maxWordSize+1) + 5, pair(0, pi(-1, -1)));
    d2.resize(n*(maxWordSize+1) + 5, pair(0, pi(-1, -1)));
    int maxRiver = 0, widthResp, currRiver;
    for(int i = maxWordSize; i <= totalSize; ++i){
        currRiver = getMaxRiver(ws, i);
        if(currRiver > maxRiver){
            widthResp = i;
            maxRiver = currRiver;
        }
    }
    cout<<widthResp<<" "<<maxRiver<<"\n";
    return 0;
}