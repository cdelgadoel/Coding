#include <iostream>
using namespace std;

int n;
int vertical[200005], horizontal[200005];

int tamanioNivelHorizontal(int i){
    int ini = 1, mitad, fin = n;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(vertical[mitad] >= i)
            ini = mitad;
        else
            fin = mitad-1;
    }
    return ini;
}

void resuelveCaso(){
    cin>>n;
    for(int i =1; i <= n; ++i)
        cin>>vertical[i];
    
    if(vertical[1] != n){
        cout<<"NO\n";
        return;
    }

    for(int i =1; i <= n; ++i){
        horizontal[i] = tamanioNivelHorizontal(i);
    }

    bool iguales = true;
    for(int i = 1; i <=n ; ++i)
        if(horizontal[i] != vertical[i])
            iguales = false;
    
    if(iguales)
        cout<<"YES\n";
    else{
        cout<<"NO\n";
    }
}


int main(){
    int cantCasos; 
    cin>>cantCasos;
    for(int i =0 ; i < cantCasos; ++i){
        resuelveCaso();
    }
    return 0;

}