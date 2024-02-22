/*
    idea central
        Como todos los numeros son diferentes, la secuencia completa 
        esta ordenada si al final están los numeros 
            1, 2, 3, ..., n

    entonces solo tengo que ver si el color que estaba inicialmente en una casilla
    es el mismo que el del numero que deberia ir ahi

    Por ejemplo, el color que tenia la casilla cero debera ser el mismo que el del 1

    Para implementar guardo el color de cada numero y el color de cada casilla
    si el color del numero 1 no corresponde con el de la casilla cero, no se puede
    y esto lo checo para cada casilla, comparando con el numero correspondiente. 

    Complejidad de tiempo O(n)
        leer + recorrer el arreglo
        O(n) + O(n)
        Complejidad total: = O(n)
    
    Complejidad de memoria  O(n)
        arreglo de colores, arreglo de colores de numeros
        O(n)          O(n)
        Complejidad total O(n)
*/  

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef pair<int, int> pii;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
    
	int colorCasilla[n], colorNumero[n+1];
    int num, color;
    for(int i = 0; i < n; ++i){
        cin>>num>>color;
        colorCasilla[i] = color;
        colorNumero[num] = color;
    }

    bool sePuede = true;
    for(int i = 0; i < n; ++i){
        if(colorCasilla[i] != colorNumero[i+1])
            sePuede = false;
    }

    if(sePuede)
        cout<<"Y\n";
    else
        cout<<"N\n";
    return 0;
}