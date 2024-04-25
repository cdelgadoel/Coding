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

#define V vector
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    ll x, k; cin>>x>>k;
    queue<pl> lists[k];
    loop(i, 0, k){
        int n; cin>>n;
        ll sum = 0, num, cost = 0;
        loop(j, 0, n){
            cin>>num;
            sum += num;
            cost = max(cost, -sum);
            if(sum > 0){
                lists[i].push(pl(cost, sum));
                sum = cost = 0;
            }
        }
    }

    priority_queue<pl, vector<pl>, greater<pl> > minHeap;
    loop(i, 0, k){
        if(!lists[i].empty())
            minHeap.push(pl(lists[i].front().first, i));
    }

    int listIndx;
    while(!minHeap.empty() && x >= minHeap.top().first){
        listIndx = minHeap.top().second;
        x += lists[listIndx].front().second;
        minHeap.pop();
        lists[listIndx].pop();

        if(!lists[listIndx].empty())
            minHeap.push(pl(lists[listIndx].front().first, listIndx));
    }
    cout<<x<<"\n";
    return 0;
}