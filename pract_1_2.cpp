#include <iostream>
#include <cmath> 
using namespace std;

struct Punto {
    double x, y;
};

// Función para calcular el producto punto
double productoPunto(Punto A, Punto B) {
    return (A.x * B.x + A.y * B.y);
}

//Función para calcular el ángulo entre dos vectores
double calcularAngulo(Punto A, Punto B) {
    //Calcular los vectores
    Punto vecA = {A.x, A.y};
    Punto vecB = {B.x, B.y};
    
    double prodPunto = productoPunto(vecA, vecB);
    
    //Calcular los módulos de los vectores
    double magA = sqrt(vecA.x * vecA.x + vecA.y * vecA.y);
    double magB = sqrt(vecB.x * vecB.x + vecB.y * vecB.y);
    
    //Calcular el ángulo
    double cosTheta = prodPunto / (magA * magB);
    double angulo = acos(cosTheta);
    
    return angulo;
}

//Función para verificar si dos líneas son paralelas, perpendiculares o se cruzan
int verificarRelacion(Punto A, Punto B, Punto C, Punto D, bool verificarPerpendicular = false) {
    double det = (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x);
    if (det == 0) {
        return 0;  //Las líneas son paralelas
    } else if (verificarPerpendicular) {
        Punto vecA = {B.x - A.x, B.y - A.y};
        Punto vecB = {D.x - C.x, D.y - C.y};
        //Si el producto punto es cero, las líneas son perpendiculares
        if (productoPunto(vecA, vecB) == 0) {
            return 1;  //Las líneas son perpendiculares
        }
    }
    return -1;  // Las líneas se cruzan
}

int main() {
  Punto A, B, C, D;
    //Solicitar las coordenadas de las líneas al usuario
    cout << "Ingrese las coordenadas del primer punto de la primera linea: "<<endl;
    cout<<"X: ";
    cin >> A.x; 
    cout<<"Y: ";
    cin>> A.y;
    cout << "Ingrese las coordenadas del segundo punto de la primera linea: "<<endl;
    cout<<"X: ";
    cin >> B.x; 
    cout<<"Y: ";
    cin>> B.y;
    cout << "Ingrese las coordenadas del primer punto de la segunda linea: "<<endl;
    cout<<"X: ";
    cin >> C.x; 
    cout<<"Y: ";
    cin>> C.y;
    cout << "Ingrese las coordenadas del segundo punto de la segunda linea: "<<endl;
    cout<<"X: ";
    cin >> D.x; 
    cout<<"Y: ";
    cin>> D.y;

    // Verificar si las líneas son paralelas, perpendiculares o se cruzan
    int resultado = verificarRelacion(A, B, C, D, true);
    
    if (resultado == 1) {
        cout << "Las lineas son perpendiculares." << endl;
    } else if (resultado == 0) {
        cout << "Las lineas son paralelas." << endl;
    } else {
        cout << "Las lineas se cruzan." << endl;
    }
    return 0;
}
