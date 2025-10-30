#include <iostream>
#include <algorithm>
#include <vector>
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;


const int maxN = 11;
bool inDanceFloor[maxN];
int n; ll resp = 0;
vector<int> adj[maxN];
void backTrack(int indxNext){
    inDanceFloor[indxNext] = true;
    for(int v : adj[indxNext]){
        if(!inDanceFloor[v]){
            inDanceFloor[v] = true;
            ++resp;
            loop(nextIndx, indxNext + 1, n-1)
                if(!inDanceFloor[nextIndx])
                    backTrack(nextIndx);
            inDanceFloor[v] = false;
        }
    }
    inDanceFloor[indxNext] = false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    for(int i = 0, t, u; i < n; ++i){
        cin>>t;
        while(t--){
            cin>>u; --u;
            if(i < u){
                adj[i].push_back(u);
            }
        }
    }
    loop(i, 0, n-1)
        backTrack(i);
    cout<<1+resp<<"\n";
    return 0;
}