//COLA CIRCULAR
// Varainte de la cola estatica que se reutiliza el espacio del arreglo
//cuando el final llega al final del arreglo . se "regresal a l incio
//utilizando la operacion del modulo(%)
# include <iostream>
using namespace std;
const int MAXQ =5; //CAPACIDAD DE LA COLA
//ESTRUCTURA DE LA COLA CCIRCULAR

struct ColaCircular{
	int data[MAXQ];//ARREGLO QUE ALMACENA LOS ELEMENTOS
	int front;//indice del incio
	int rear;//indice del final
	int count;// cantidad de elementos de cola
};

//inicializar la cola circular vacia
 void incializar(ColaCircular& c){
 	c.front=0 ;
 	c.count=-1;
 	c.count=0;
 }
 //verifica si esta cavia o llena
 bool vacia( const ColaCircular& c){return c.count==0;}
 bool llena( const ColaCircular& c){return c.count==MAXQ;}
 
 //INSERTAR UN ELEMENTO AL FINAL DE LA COLA
 bool encolar(ColaCircular& c,int v){
 	if(llena(c))return false;
 	c.rear = (c.rear+1)% MAXQ; // avanza el limite circularmente
 	c.data[c.rear]=v;
 	c.count++;
 	return true;
 }
 
 // funcion eliminar un elemento del frente
 bool desencolar(ColaCircular& c, int& out){
 	if(vacia(c)) return false;
 	out =c.data[c.front];
 	c.front=(c.front+1) %MAXQ;//AVANZA CIRCULAR
 	c.count--;
 	return true;
 }
 //pRINCIPAL
 int main(){
 	ColaCircular c; incializar(c);
 	//Insertar cinco Elementos
 	for(int i=1;i<=5;i++)
 	    cout<<(encolar(c,i*10) ? "Encolado. \n":"Cola llena.?n");
 	    
 	    int x;
 	    //quitamos uno y volvemos a insertar
 	    desencolar(c,x); cout<<"Desencolado: "<<x<<"\n";
 	    encolar(c,60);
 	    //mostramos el contenido restante
 	    while(desencolar(c,x))
 	    cout <<"Desencolado"<<x<<"\n";
 	    return 0;
 	    
 	    
 	
 }

