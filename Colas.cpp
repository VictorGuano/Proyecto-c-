// COLAS CON MEMORIA  ESTATICA
# include <iostream>
using namespace std;
#define MAX 5 //tamaño maximo de Cola
//aqui se define la  estructura y define una cola estatica
struct Cola {
	int datos[MAX];
	int front;
	int rear;
};
//Inicializa la cola vacia
void inicializar(Cola &c){
	c.front=0;
	c.rear=-1;
}
//verifica si la cola esta vacia
bool estaVacia(Cola c){
	return c.front > c.rear ;
}

//Verifica si la cola esta llena
bool estaLlena(Cola c){
	return c.rear==MAX-1;
}
//Insertar un nuevo elemento al final de la cola
void encolar(Cola &c, int valor){
	if(!estaLlena(c)){
		c.datos[++c.rear]=valor;
		cout<< "Elemento"<< valor <<"encolado. \n";
	}else{
		cout<<"Cola llena.\n" ;
	}
}
//eliminar elemento frente
int desencolar(Cola &c){
	if(!estaVacia(c)){
		return c.datos[c.front++];
		
	}else{
		cout<<"Cola vacia\n";
		return -1;
	}
}
int main(){
	Cola c;
	inicializar(c);
	
	encolar(c,10);
	encolar(c,20);
	encolar(c,30);
	
	cout<<"Desconlado"<< desencolar(c)<< endl;
	cout<<"Desconlado"<< desencolar(c)<< endl;
	
	encolar(c, 40);
	encolar(c, 50);
	encolar(c, 60);
	cout<<"desencolado"<<desencolar(c)<< endl;
	//direcciones
	
	cout << "Direccion de la cola: " << &c << endl;
	cout << "Direccion del arreglo datos: " << &c.datos << endl;
	cout << "Direccion del primer elemento: " << &c.datos[0] << endl;
	return 0;
}
