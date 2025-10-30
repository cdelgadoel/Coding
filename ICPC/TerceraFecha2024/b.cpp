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
#include <unordered_set>
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

const int maxM = 1e6+1, maxN = 100+1;
int n, m;
unordered_set<int> moviesForPerson[maxM];
// save movies and the actor that ensures that connection
unordered_set<int> adjMovies[maxN];
int personBetweenMovies[maxN+1][maxN+1];


bool visited[maxN];
stack<int> moviesBetweenActors;
int target;
bool dfs(int v){
    visited[v] = true;
    if(moviesForPerson[target].find(v) != moviesForPerson[target].end()){
        moviesBetweenActors.push(v);
        return true;
    }

    for(int movie : adjMovies[v]){
        if(visited[movie]) continue;
        if(dfs(movie)){
            moviesBetweenActors.push(v);
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>n>>m;
    loop(i, 1, n+1){
        int numPeople, person; 
        cin>>numPeople;
        while(numPeople--){
            cin>>person;
            moviesForPerson[person].insert(i);
        }
    }

    for(int p = 1; p <= m; ++p){
        if(moviesForPerson[p].empty()) continue;
        int pivotMovie = *moviesForPerson[p].begin();
        for(int movie : moviesForPerson[p]){
            personBetweenMovies[movie][pivotMovie] = personBetweenMovies[pivotMovie][movie] = p;
            adjMovies[pivotMovie].insert(movie);
            adjMovies[movie].insert(pivotMovie);
        }
    }

    int q; cin>>q;
    vector<int> moviesPath;
    while(q--){
        int a, b; cin>>a>>b;
        fill(visited, visited + n + 1, 0);
        bool foundPath = false;
        target = b;
        for(int movie : moviesForPerson[a]){
            if(!visited[movie])
                foundPath = dfs(movie);
            if(foundPath) break;
        }

        // result
        if(!foundPath){
            cout<<"-1\n";
        }
        else{
            while(!moviesBetweenActors.empty()){
                moviesPath.push_back(moviesBetweenActors.top());
                moviesBetweenActors.pop();
            }
            cout<<moviesPath.size()+1<<"\n";
            cout<<a<<" "<<moviesPath[0];
            for(int i = 1; i < moviesPath.size(); ++i){
                cout<<" "<<personBetweenMovies[moviesPath[i-1]][moviesPath[i]]<<" "<<moviesPath[i];
            }
            cout<<" "<<b<<"\n";
            moviesPath.clear();
        }
    }
    return 0;
}