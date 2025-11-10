#include <iostream>
using namespace std;

// Tu estructura original
struct NodoDoble {
    int dato;
    // para recorrer hacia atrás y hacia adelante
    NodoDoble* anterior;
    NodoDoble* siguiente;
};

// Tu función original para insertar al inicio
void insertarDoble(NodoDoble*& cabeza, int valor) {
    NodoDoble* nuevo = new NodoDoble();
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    nuevo->anterior = nullptr;
    
    if (cabeza != nullptr) {
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    } else {
        cabeza = nuevo;
    }
}

// Tu función para mostrar hacia adelante y hacia atrás
void mostrarDoble(NodoDoble* cabeza) { 
    cout << "\nLista doblemente enlazada hacia adelante: ";
    NodoDoble* actual = cabeza;
    NodoDoble* ultimo = nullptr;

    while (actual != nullptr) {
        cout << actual->dato << " <-> ";
        ultimo = actual;
        actual = actual->siguiente;	
    }
    cout << "NULL\n";

    cout << "Lista doblemente enlazada hacia atrás: ";
    while (ultimo != nullptr) {
        cout << ultimo->dato << " <-> ";
        ultimo = ultimo->anterior;	
    }
    cout << "NULL\n";
}

// MAIN para probar todo
int main() {
    NodoDoble* cabeza = nullptr;
    int edad;
    int opcion;

    do {
        cout << "\n--- MENU LISTA DOBLE ENLAZADA (EDADES) ---\n";
        cout << "1) Insertar edad\n";
        cout << "2) Mostrar lista doble\n";
        cout << "3) Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la edad: ";
                cin >> edad;
                insertarDoble(cabeza, edad);
                break;

            case 2:
                mostrarDoble(cabeza);
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción inválida.\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}

