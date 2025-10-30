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
#include <cmath>
using namespace std;
const int maxN = 1e4+5, maxM = 1e5+5;
int Q, n, resp[maxM], a[maxN];

struct query{
	int L, R, indx;
}q[maxM];

int block;
bool compara(const query &x, const query &y){
	if (x.L/block != y.L/block) 
	        return x.L/block < y.L/block;
    else
	    return x.R < y.R; 
}

void quita(int indx, multiset<int>& active,  multiset<int>& differences){
    multiset<int>::iterator it = active.find(a[indx]);
    if(it == active.begin()){
        ++it;
        if(it != active.end()){
            differences.erase(differences.find(*it - a[indx]));
        }
    }
    else{
        --it; 
        int atras = *it;
        ++it;

        ++it;
        if(it == active.end()){
            differences.erase(differences.find(a[indx] - atras));
        }
        else{
            int adelante = *it;
            differences.erase(differences.find(adelante - a[indx]));
            differences.erase(differences.find(a[indx] - atras));
            differences.insert(adelante - atras);
        }
    }

    // quita elemento
    active.erase(active.find(a[indx]));
}

void agrega(int indx, multiset<int>& active,  multiset<int>& differences){
    // agrega elemento
    active.insert(a[indx]);
    // quita diferencias
        // hacia adelante
        multiset<int>::iterator it = active.find(a[indx]);
        if(it == active.begin()){
            ++it;
            if(it != active.end()){
                differences.insert(*it - a[indx]);
            }
        }
        else{
            --it; 
            int atras = *it;
            ++it;

            ++it;
            if(it == active.end()){
                differences.insert(a[indx] - atras);
            }
            else{
                int adelante = *it;
                differences.erase(differences.find(adelante - atras));
                differences.insert(adelante - a[indx]);
                differences.insert(a[indx] - atras);
            }
        }
}
 
 
void MOs(){
    block = max((int)sqrt(n), 1);
    sort(q, q + Q, compara); 
    
	int L,R;
    multiset<int> active, differences;
    int currL = 0, currR = 0;
    active.insert(a[0]);

    // Traverse through all queries 
    for (int i=0; i<Q; ++i){ 
        // L and R values of current range 
        L = q[i].L;
        R = q[i].R;
        
        while (currR < R){
            //agrega hacia la derecha
            ++currR;
            agrega(currR, active, differences);
        }
        while (L < currL){
        	//agrega hacia la izq
            --currL;
            agrega(currL, active, differences);
        }
        while (R < currR){
        	//quita de la derecha
            quita(currR, active, differences);
            --currR;
        }
        while (currL < L){
        	//quita de la izq
            quita(currL, active, differences);
            ++currL;
        }
        resp[q[i].indx] = *differences.begin();
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
	cin>>n;
    for(int i = 0; i<n; ++i)
        cin>>a[i];

    cin>>Q;
	for(int i = 0; i < Q; ++i){
		cin>>q[i].L>>q[i].R;
        --q[i].L; --q[i].R;
		q[i].indx = i;
	}
	MOs();
	for(int i = 0; i < Q; ++i)
		cout<<resp[i]<<'\n';
	return 0;
}