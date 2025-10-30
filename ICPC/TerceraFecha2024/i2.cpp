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

const int maxN = 1000001;
int n;

vector<ll> prime;
// tiene 0 en los primos y un primo del numero en los no primos
int criba[maxN];
void sieve () {
    for(int i = 4; i < maxN; i +=2){
        criba[i] = 2;
    }

    for(int i = 3; i*i < maxN; i += 2){
        if(criba[i] == 0){
            for(int j = i*i; j < maxN; j += i)
                criba[j] = i;
        }
    }
}

// para uno regresa un vector vacio
void obtenPrimosDividen(int num, vector<int> & primosNum){
    primosNum.clear();
    int primoActual;
    while(criba[num]){
        primoActual = criba[num];
        primosNum.push_back(primoActual);
        while(num % primoActual == 0)
            num /= primoActual;
    }
    if(criba[num] == 0)
        primosNum.push_back(num);

}

// solo llenamos para i square free
// countDividen[i] := cantidad de numeros a los que divide el numero i entre los numeros del 
//                      restaurante
int countDividen[maxN];
vector<int> primesFood;
void actualizaCountDividen(int food){
    obtenPrimosDividen(food, primesFood);
    // consideramos todos los divisores sf
    for(int i = 1, divisor; i < (1<<primesFood.size()); ++i){
        // genera el numero sf
        divisor = 1;
        for(int indx = 0; indx < primesFood.size(); ++indx){
            if(i & (1<<indx))
                divisor *= primesFood[indx];
        }
        // lo uso para lo que quiera
        ++countDividen[divisor];
    }
}

int cantidadFoodsAlergicas(int food){
    obtenPrimosDividen(food, primesFood);
    int cantAlergicos = 0;
    // consideramos todos los divisores sf
    // usamos inclusion exclusion
    for(int i = 1, divisor, cantBits; i < (1<<primesFood.size()); ++i){
        // genera el numero sf
        divisor = 1; cantBits = 0;
        for(int indx = 0; indx < primesFood.size(); ++indx){
            if(i & (1<<indx)){
                divisor *= primesFood[indx];
                ++cantBits;
            }
        }
        
        // lo uso para lo que quiera
        cantAlergicos += cantBits & 1? countDividen[divisor] : -countDividen[divisor];
    }
    return cantAlergicos;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    sieve();
    
    cin>>n;
    for(int i = 0, food; i < n; ++i){
        cin>>food;
        actualizaCountDividen(food);
    }
    
    ll pow[n+1];
    pow[0] = 1;
    loop(i, 1, n+1) 
        pow[i] = (pow[i-1]<<1)%MOD;

    int q, num; 
    cin>>q;
    loop(i, 0, q){
        cin>>num;
        cout<<pow[n-cantidadFoodsAlergicas(num)]<<"\n";
    }
    return 0;
}