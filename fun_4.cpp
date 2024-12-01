#include <iostream>
using namespace std;

int contadorLlamadas = 0;

//Función que realiza un proceso cualquiera
void proceso(int n) {
  for(int i=0; i<n; i++){
    contadorLlamadas++;
  }
  cout << "Procesos ejecutados." << endl;
}

// Función que devuelve cuántas veces se ha llamado a la función proceso
int contarLlamadas() {
    return contadorLlamadas;
}

int main() {
  int n;
  cout<<"Cuantas veces desea realizar el proceso?"<<endl;
  cin>>n;
  proceso(n);
    
    // Mostrar cuántas veces se ha llamado
    cout << "La funcion proceso se llamo " << contarLlamadas() << " veces." << endl;

    return 0;
}
