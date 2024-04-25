# include <iostream>
using namespace std;

int main() {
  int n;
  int numeroMaximo = -100000;
  cout << "ingresa una cantidad de numeros: ";
  cin >> n;

  for(int i = 0; i < n ; i++) {
    int numero;
    cout << "\ningresa un numero";
    cin >> numero;
    if(numero > numeroMaximo){
      numeroMaximo = numero;
    }
      
  }
  cout << "\nel numero maximo es: " << numeroMaximo;
}