/*
    idea central
        Como todos los numeros son diferentes, la secuencia completa 
        esta ordenada si al final están los numeros 
            1, 2, 3, ..., n

    entonces solo tengo que ver si el color que estaba inicialmente en una casilla
    es el mismo que el del numero que deberia ir ahi

    Por ejemplo, el color que tenia la casilla cero debera ser el mismo que el del 1

    Para implementar tengo un conjunto para cada color, y voy checando si el conjunto tiene al
    numero que va en ese lugar

    Complejidad de tiempo O(n)
        leer + insertar los numeros al conjunto + recorrer el arreglo
        O(n) + n*O(1) + O(n)
        Complejidad total: O(3*n) = O(n)
    
    Complejidad de memoria  O(n)
        arreglo de colores, arreglo de conjuntos
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
    
	int colores[n];
	unordered_set<int> setColor[k+1];
    int num, color;
    for(int i = 0; i < n; ++i){
        cin>>num>>color;
        colores[i] = color;
        setColor[color].insert(num);
    }

    bool sePuede = true;
    for(int i = 0; i < n; ++i){
        //cuando un elemento no está en un conjunto, 
        // la funcion find regresa un apuntador a .end()
        // Si si estuviera, te regresa un apuntador a un elemento que 
        //      tiene este valor buscado
        if(setColor[colores[i]].find(i+1) == setColor[colores[i]].end())
            sePuede = false;
    }

    if(sePuede)
        cout<<"Y\n";
    else
        cout<<"N\n";
    return 0;
}