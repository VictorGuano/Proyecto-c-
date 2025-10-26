# include <iostream>
# include <string>
//--------typeDef y Plantillas-----------

using namespace std;
//Alias con typedef

typedef string NombreProducto;
typedef string Categoria;
typedef float Precio;
typedef unsigned int Cantidad;
// case plantilla con miembros publicos (interfaz)

template <typename ID>
class Producto {
	private:
		//Atibutos protegidos (no accesibles desde afuera)
		ID codigo;
		NombreProducto nombre;
		Categoria categoria;
		Precio precio;
		Cantidad  stock;
		
		
	//Clase de tipo Publico
	
	public:
	// Constructor  Publico
	Producto(ID c,NombreProducto n, Categoria cat,Precio p ,Cantidad s):
	codigo(c), nombre(n),categoria(cat),precio(p), stock (s){}
	
	//Metodos publicos (interfaz del TDA)
	void mostrar() const {
		cout<<"Codigo"<<codigo;
		cout<<"Nombre"<<nombre;
		cout<<"Precio $"<<precio;
		cout<<"Stock"<<stock;
	}	
	//metodo vender
	void vender(Cantidad cantidad){
		if(cantidad <=stock)
		// stock = stock -cantidad;
		stock -= cantidad;
		else
			cout<<"Erros: stock insuficiente .\n";
	
	}
	//metodo reponer
	void reponer(Cantidad cantidad){
		//stock = stock+cantidad;
		stock += cantidad;
	}
	
	bool sinStock() const{
		return stock==0;
	}	
};
// metodo Principal
int main(){
	Producto<int> p1(1002,"teclado Mecanico","Periferico",79.99f,30);
	
	//uso de metodos Publicos
	p1.mostrar();
	p1.vender(5);
	p1.mostrar();
	if(p1.sinStock())
	cout<<"El producto esta agotado. \n";
	else 
	cout<<"Aun hay unidades disponibles. \n";
	return 0;
}

