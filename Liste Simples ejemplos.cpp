#include <iostream>
#include <string>
using namespace std;

struct NodoSimple {
    string nombre;
    NodoSimple* siguiente;
};

void insertarSimple(NodoSimple*& cabeza, string valor) {
    NodoSimple* nuevo = new NodoSimple();
    nuevo->nombre = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void mostrarSimple(NodoSimple*& cabeza) {
    cout << "\nLista de nombres: ";
    NodoSimple* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->nombre << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

int main() {
    NodoSimple* lista = nullptr;
    string nombre;
    char opcion;

    do {
        cout << "Ingrese un nombre: ";
        cin >> nombre;
        insertarSimple(lista, nombre);

        cout << "¿Desea ingresar otro nombre? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    mostrarSimple(lista);
}

