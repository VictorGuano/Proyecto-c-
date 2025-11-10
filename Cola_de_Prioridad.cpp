// COLA DE PRIORIDAD
// Cada elemento tiene una prioridad asociada.
// Los elementos se insertan ordenados por prioridad (mayor a menor)
// y siempre se extrae primero el de mayor prioridad.

#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Estructura del nodo que contendrá el valor y la prioridad
//-----------------------------------------------------------
struct Node {
    int val;        // Valor del elemento almacenado
    int priority;   // Prioridad asociada (mayor número = más prioridad)
    Node* next;     // Puntero al siguiente nodo de la lista
};

//-----------------------------------------------------------
// Estructura de la cola de prioridad
//-----------------------------------------------------------
struct PQueue {
    Node* head;     // Puntero al primer nodo de la cola (mayor prioridad)
};

//-----------------------------------------------------------
// Inicializa la cola vacía (head apunta a nullptr)
//-----------------------------------------------------------
void init(PQueue& q) {
    q.head = nullptr;
}

//-----------------------------------------------------------
// Verifica si la cola está vacía
//-----------------------------------------------------------
bool empty(const PQueue& q) {
    return q.head == nullptr; // Devuelve true si no hay elementos
}

//-----------------------------------------------------------
// Inserta un nuevo elemento ordenado por prioridad descendente
//-----------------------------------------------------------
void push(PQueue& q, int v, int p) {
    // Crear nuevo nodo con valor y prioridad
    Node* n = new Node{v, p, nullptr};

    // Caso 1: la cola está vacía o la prioridad del nuevo elemento
    // es mayor que la del primer nodo (debe ir al inicio)
    if (empty(q) || p > q.head->priority) {
        n->next = q.head; // Nuevo nodo apunta al anterior primero
        q.head = n;       // Ahora el nuevo nodo es el primero
        return;
    }

    // Caso 2: buscar la posición correcta según prioridad
    Node* cur = q.head;
    while (cur->next && cur->next->priority >= p)
        cur = cur->next; // Avanza mientras la siguiente prioridad sea mayor o igual

    // Insertar el nuevo nodo en su posición
    n->next = cur->next;
    cur->next = n;
}

//-----------------------------------------------------------
// Elimina el elemento de mayor prioridad (el primero)
//-----------------------------------------------------------
bool pop(PQueue& q, int& outVal, int& outPri) {
    // Si la cola está vacía, no hay nada que eliminar
    if (empty(q)) return false;

    // Guardar referencia temporal al primer nodo
    Node* t = q.head;

    // Extraer los valores de salida
    outVal = t->val;
    outPri = t->priority;

    // Mover la cabeza al siguiente nodo
    q.head = t->next;

    // Liberar memoria del nodo eliminado
    delete t;

    // Indicar que se extrajo correctamente
    return true;
}

//-----------------------------------------------------------
// Función principal
//-----------------------------------------------------------
int main() {
    PQueue q;       // Crear una cola de prioridad
    init(q);     // Inicializarla vacía
	int n=0,n2=0,n3=0;       
    // Insertar elementos con su valor y prioridad
    cout<<"Ingrese el valor y la prioridad"<< endl;
    cin>>n;                                                                      ;
    push(q, n, rand());
    cout<<"Ingrese el valor y la prioridad"<< endl;
    cin>>n2;
    push(q, n2, rand());
    cout<<"Ingrese el valor y la prioridad"<< endl;
    cin>>n3;
    push(q, n3, rand());

    int v, p;
    // Extraer elementos según su prioridad
    while (pop(q, v, p))
        cout << "Elemento " << v << " con prioridad " << p << " eliminado.\n";

    return 0;
}

