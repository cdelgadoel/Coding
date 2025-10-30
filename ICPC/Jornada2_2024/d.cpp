#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
vector<int> firstDigit(19);
vector<int> zeroDigit(19);
ll resp[801];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //fill first digit 
    for(int i = 1; i <= 9; ++i)
    for(int j = 1; j <= 9; ++j){
        if(i != j){
            ++firstDigit[i-j + 9];
        }
    }
    
    // este es para el caso en que no eres digito inicial
    // y uno puede ser cero
    loop(i, 1, 10) ++zeroDigit[i + 9];
    loop(j, 1, 10) ++zeroDigit[-j + 9];

    resp[1] = 0;
    const int maxN = 800;
    ll m1[2*9*maxN+1], m2[2*9*maxN+1];
    fill(m1, m1 + 2*9*maxN+1, 0);
    fill(m2, m2 + 2*9*maxN+1, 0);
    auto dpn = &m1, dpo = &m2;
    
    // lleno dp(1)
    for(int i = -9; i <= 9; ++i)
        (*dpo)[i + 9*maxN] = firstDigit[i+9] + zeroDigit[i+9];

    for(int d = 2; d <= 800; ++d){
        // calcula dpn para cada suma posible
        for(int s = -9*d; s <= 9*d; ++s){
            (*dpn)[s + 9*maxN] = 0;
            for(int i = -8; i <= 8; ++i){
                if( -9*maxN <= s-i && s-i <= 9*maxN )
                    (*dpn)[s + 9*maxN] = ((*dpn)[s + 9*maxN] + (firstDigit[i+9] * ((*dpo)[ s - i + 9*maxN]))%MOD )%MOD;
            }
            if(s == 0)
                resp[d] = ((*dpn)[s + 9*maxN])%MOD;
            for(int i = -9; i <= 9; ++i){
                if( -9*maxN <= s-i && s-i <= 9*maxN )
                    (*dpn)[s + 9*maxN] = ((*dpn)[s + 9*maxN] + (zeroDigit[i+9] * (*dpo)[ s - i + 9*maxN])%MOD )%MOD;
            }
        }
        swap(dpn, dpo);
    }
    int q; cin>>q;
    loop(i, 0, q){
        int x; cin>>x; cout<<resp[x]<<"\n";
    }
    return 0;
}