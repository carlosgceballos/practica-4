#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x, y;
};


double productoPunto(Punto A, Punto B) {
    return (A.x * B.x + A.y * B.y);
}


double magnitud(Punto A) {
    return sqrt(A.x * A.x + A.y * A.y);
}

//Función para calcular el ángulo en radianes entre dos líneas
double calcularAngulo(Punto A, Punto B, Punto C, Punto D, bool enGrados = false) {
    // Vectores A-B y C-D
    Punto vectorAB = {B.x - A.x, B.y - A.y};
    Punto vectorCD = {D.x - C.x, D.y - C.y};

    //Producto punto entre los dos vectores
    double producto = productoPunto(vectorAB, vectorCD);

    //Magnitudes de los vectores
    double magnAB = magnitud(vectorAB);
    double magnCD = magnitud(vectorCD);

    double cosAngulo = producto / (magnAB * magnCD);

    if (cosAngulo > 1) cosAngulo = 1;
    if (cosAngulo < -1) cosAngulo = -1;

    //Calcular el ángulo en radianes
    double anguloRadianes = acos(cosAngulo);

    //Si se desea el ángulo en grados, convertirlo
    if (enGrados) {
        return anguloRadianes * 180.0 / M_PI;
    }

    return anguloRadianes; 
}

int main() {
    Punto A, B, C, D;

    // Solicitar las coordenadas de los puntos al usuario
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
    cin>> D.y;;

    // Llamar a la función para calcular el ángulo en radianes
    double anguloRadianes = calcularAngulo(A, B, C, D);

    // Llamar a la función para calcular el ángulo en grados
    double anguloGrados = calcularAngulo(A, B, C, D, true);

    // Mostrar los resultados
    cout << "Angulo en radianes: " << anguloRadianes << endl;
    cout << "Angulo en grados: " << anguloGrados << endl;

    return 0;
}
