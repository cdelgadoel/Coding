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

#define sz(a) a.size()

#define V vector
#define pb push_back
#define f first
#define s second

const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n, q; cin>>n>>q;
    vector<int> original(n);
    multiset<pi> collection;

    loop(i, 0, n)
        cin>>original[i];
    sort(original.begin(), original.end());

    loop(i, 0, n)
        collection.insert(pi(original[i], i));

    loop(i, 0, q){
        int type;
        cin>>type;
        if(type == 1){
            int k; cin>>k;
            auto nextGreater = collection.lower_bound(pi(k, 0));
            if(nextGreater == collection.end()){
                collection.insert(pi(k, n));
                ++n;
            }
            else if(nextGreater->first != k){
                int indxK = nextGreater -> second;
                collection.erase(nextGreater);
                collection.insert(pi(k, indxK));
            }
        }else{
            int a,b; cin>>a>>b;
            auto firstElement = collection.lower_bound(pi(a, 0));
            auto end = collection.lower_bound(pi(b+1, 0));

            if(firstElement == collection.end())
                cout<<0<<"\n";
            else if(end == collection.end()){
                cout<< n - (firstElement->second) <<"\n";
            }
            else{
                cout<< (end->second) - (firstElement->second)<<"\n";
            }
        }
    }
    
    return 0;
}