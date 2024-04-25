#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
const int maxN = 1005;
bool visitado[maxN];
int color[maxN];
vector<int> adj[maxN];
bool sePuede = true;

void dfs(int u, int ancestro, int colorActual){
    visitado[u] = true;
    color[u] = colorActual;

    // propagar a mis hijos
    for(int v : adj[u]){
        if(v != ancestro){
            // span edge
            if(!visitado[v]){
                dfs(v, u, -colorActual);
            }
            // back edge
            if(colorActual == color[v]){
                sePuede = false;
                return;
            }
        }
    }
}

int main(){
    cin>>n;
    int entry[n+1], out[n+1];
    for(int i = 0, num; i < 2*n; ++i){
        cin>>num;
        if(num > 0){
            entry[num] = i;
        }
        else{
            out[-num] = i;
        }
    }

    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
        // si tienen una relacion indeseada, los uno
        if( i != j && entry[i] < entry[j] && entry[j] < out[i] && out[i] < out[j]){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    
    for(int i = 1; i <= n; ++i){
        if(!visitado[i])
            dfs(i, 0, 1);
    }

    if(!sePuede){
        cout<<"*\n";
    }
    else{
        for(int i = 1; i <= n; ++i){
            if(color[i] == 1)
                cout<<"G";
            else
                cout<<"S";
        }
        cout<<"\n";
    }
    return 0;
}