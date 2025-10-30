#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> pl;

const ll maxN = 1e5+1;
ll n, m;
ll inicio, destino, presupuesto;

void dijkstra(ll nodo, vector<ll> &vec, vector<pl>adj_ [maxN]){
    priority_queue<pl, vector<pl>, greater<pl> > minHeap;
    bool visited[maxN];
    fill(visited, visited + n + 1, 0);
    fill(vec.begin(), vec.end(), presupuesto + 1);
    minHeap.push(pl(0, nodo));

    ll u, cost;
    while(!minHeap.empty()){
        cost = minHeap.top().first;
        u = minHeap.top().second;
        minHeap.pop();

        if(visited[u]) continue;
        visited[u] = true;
        vec[u] = cost;

        ll v, costEdge;
        for(pl neighbor_pair : adj_[u]){
            v = neighbor_pair.first;
            costEdge = neighbor_pair.second;         
            if(!visited[v])
                minHeap.push(pl(cost + costEdge, v));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<pl> adj[maxN], invAdj[maxN];
    for(ll i = 0, a, b, c; i < m; ++i){
        cin>>a>>b>>c;
        adj[a].push_back(pl(b, c));
        invAdj[b].push_back(pl(a, c));
    } 
    cin>>inicio>>destino>>presupuesto;
    
    vector<ll> costoDesdeInicio, costoADestino;
    costoDesdeInicio.resize(n+1);
    costoADestino.resize(n+1);
    // con dijkstra se puede precalcular la distancia minima de un nodo 
    // a todos los demas
    dijkstra(inicio, costoDesdeInicio, adj);
    dijkstra(destino, costoADestino, invAdj);
    
    // itero sobre las aristas
    ll resp = -1;
    for(ll u = 1, v, costEdge; u <= n; ++u){
        for(pair v_pair : adj[u]){
            v = v_pair.first;
            costEdge = v_pair.second;
            // ruta inicio -> u -> v -> final
            if(costoDesdeInicio[u] + costEdge + costoADestino[v] <= presupuesto)
                resp = max(resp, costEdge);
        }
    }
    cout<<resp<<"\n";
    return 0;
}