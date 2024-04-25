#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define loop(i, a, b) for(int i = a; i < b; ++i)

const int maxE = 2e5 + 5;
int n, e, q;
int a[maxE];

int l[4*maxE], r[4*maxE], f[4*maxE], level[4*maxE];
void init(int id, int le, int ri, int level_){ 
    l[id] = le;
    r[id] = ri;
    level[id] = level_;
    if(le != ri){
        int m = (le + ri)/2;
        init(2*id, le, m, level_+1);
        init(2*id+1, m+1, ri, level_+1);

        if(n&1){
            f[id] = level_&1? f[2*id] | f[2*id+1] : f[2*id] ^ f[2*id+1];
        }
        else{
            f[id] = level_&1? f[2*id] ^ f[2*id+1] : f[2*id] | f[2*id+1];
        }
    }
    else{
        f[id] = a[le];
    }
}

void update(int p, int b){
    int id = 1, m;
    while(l[id] != r[id]){
        m = (l[id] + r[id])/2;
        id = p<=m?  2*id : 2*id + 1;
    }

    f[id] = b;
    while(id != 0){
        id /= 2;
        if(n&1){
            f[id] = level[id]&1? f[2*id] | f[2*id+1] : f[2*id] ^ f[2*id+1];
        }
        else{
            f[id] = level[id]&1? f[2*id] ^ f[2*id+1] : f[2*id] | f[2*id+1];
        }
    }
}

// int query(int id, int q_l, int q_r){
//     if( q_r < l[id] ||  r[id] < q_l){
//         return 0;
//     }
//     else if(q_l <= l[id] && r[id] <= q_r){
//         return f[id];
//     }
//     else{
//         int lr = query(2*id, q_l, q_r);
//         int rr = query(2*id+1, q_l, q_r);
//         if(n&1){
//             return level[id]&1? lr | rr : lr ^ rr;
//         }
//         else{
//             return level[id]&1? lr ^ rr : lr | rr;
//         }
//     }
// }


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;

    e = 1;
    loop(i, 0, n)
        e *= 2;
    
    loop(i, 1, e+1){
        cin>>a[i];
    }
    
    // construir el ST
    init(1, 1, e, 1);
    loop(i, 0, q){
        int p, b; cin>>p>>b;
        update(p, b);
        cout<<f[1]<<"\n";
    }
}