#include <iostream>
#include <algorithm>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
const int maxN = 500005;

void imprimeCualesBitsPrimeros15(int a){
    int bits[15];
    for(int i = 0; i < 15; ++i){
        bits[i] = a&1;
        a = a>>1;
    }
    
    for(int i = 15; i >= 0; --i){
        cout<<bits[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int a; 
    cin>>a;
    imprimeCualesBitsPrimeros15(a);

    return 0;
}