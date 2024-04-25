#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

int n, k;
const int maxN = 5e5+5;
int incoming[maxN];
int nextNode[maxN];

bool visited[maxN];
multiset<int> foo[maxN];
multiset<int>* ms[maxN];
int offset[maxN];
int resp[maxN];

void merge(int a, int b){
    while( *(ms[a]->begin()) + offset[a] <= 0){
        //cout<<"ea "<<*(ms[a]->begin())<<endl;
        ms[a]->erase(ms[a]->begin());
    }
    
    while( *(ms[b]->begin()) + offset[b] <= 0){
        //cout<<"eb "<<*(ms[b]->begin())<<endl;
        ms[b]->erase(ms[b]->begin());
    }

    if(ms[a]->size() > ms[b]->size()){
        for(int v: *ms[b]){
            //cout<<"a "<<v<<endl;
            ms[a]->insert(v+offset[b]-offset[a]);
        }
        ms[b] = ms[a];
        offset[b] = offset[a];
    }
    else{
        for(int v: *ms[a]){
            //cout<<"b "<<v<<endl;
            ms[b]->insert(v+offset[a]-offset[b]);
        }
    }
}

int findsizeCiclo(int a){
    int resp = 1;
    int v = nextNode[a];
    while(v != a){
        ++resp;
        v = nextNode[v];
    }
    return resp;
}

int acum[maxN];
int sizeCiclo;
void processMs(int a, int indx){
    for(int x : *ms[a]){
        x+=offset[a];
        if(x <= 0) continue;
        if(x >= sizeCiclo){
            acum[0] += 1;
        }
        else if(x + indx >= sizeCiclo){
            acum[indx] += 1;
            
            acum[0] += 1;
            acum[x+indx - sizeCiclo] -= 1;
        }
        else{
            acum[indx] += 1;
            acum[indx+x] -= 1; 
        }
    } 
}

void solveCycle(int a){
    sizeCiclo = findsizeCiclo(a);
    //cout<<"sizeCiclo "<<sizeCiclo<<endl;
    fill(acum, acum+sizeCiclo, 0);
    processMs(a, 0);
    int v = nextNode[a], indx = 1;
    while(v != a){
        processMs(v, indx);
        v = nextNode[v];
        ++indx;
    }

    v = a;
    loop(i, 0, sizeCiclo){
        if(i > 0) acum[i] += acum[i-1];
        visited[v] = true;
        resp[v] = acum[i];
        v = nextNode[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>k;
    ++k;
    loop(i, 0, n){
        int sig;
        cin>>sig;
        --sig;
        nextNode[i] = sig;
        incoming[sig]++;
    }

    loop(i, 0, n){
        offset[i] = 0;
        ms[i] = &foo[i];
        ms[i]->insert(k);
    }

    stack<int> hojas;
    loop(i, 0, n)
        if(incoming[i]==0)
            hojas.push(i);
        
    while(!hojas.empty()){
        int tope = hojas.top();
        visited[tope] = true;
        hojas.pop();
        resp[tope] = ms[tope]->size();
       
        //merge
        offset[tope] -= 1;
        int sigTope = nextNode[tope];
        merge(tope, sigTope);
        --incoming[sigTope];
        if(incoming[sigTope]==0)
            hojas.push(sigTope);
    }
    //simple cycles
    loop(i, 0, n){
        if(!visited[i]){
            solveCycle(i);
        }
    }

    loop(i, 0, n)
        cout<<resp[i]<<"\n";
    return 0; 
}