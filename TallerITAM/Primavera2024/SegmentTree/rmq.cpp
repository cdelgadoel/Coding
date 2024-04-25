#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
#define loop(i, a, b) for(int i = a; i < b; ++i)

const int maxE = 2e5 + 5;
int n, e, q;
int a[maxE];

int l[4*maxE], r[4*maxE], f[4*maxE];
void init(int id, int le, int ri){ 
    l[id] = le;
    r[id] = ri;
    if(le != ri){
        int m = (le + ri)/2;
        init(2*id, le, m);
        init(2*id+1, m+1, ri);
        f[id] = min(f[2*id], f[2*id+1]);
    }
    else{
        f[id] = a[le];
    }
}

void update(int indx, int newValue){
    int id = 1, m;
    while(l[id] != r[id]){
        m = (l[id] + r[id])/2;
        id = indx<=m?  2*id : 2*id + 1;
    }

    f[id] = newValue;
    while(id != 0){
        id /= 2;
        f[id] = min(f[2*id], f[2*id+1]);
    }
}

int query(int id, int q_l, int q_r){
    if( q_r < l[id] ||  r[id] < q_l){
        return INT_MAX;
    }
    else if(q_l <= l[id] && r[id] <= q_r){
        return f[id];
    }
    else{
        return min(query(2*id, q_l, q_r), query(2*id+1, q_l, q_r));
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    loop(i, 1, n+1){
        cin>>a[i];
    }
    
    // construir el ST
    init(1, 1, n);

    loop(i, 0, q){
        int tipoQuery; cin>>tipoQuery;
        // update
        if(tipoQuery == 1){
            int indx, newValue;
            cin>>indx>>newValue;
            update(indx, newValue);
        }
        // query
        else{
            int q_l, q_r; cin>>q_l>>q_r;
            cout<<query(1, q_l, q_r)<<"\n";
        }
        
    }
}