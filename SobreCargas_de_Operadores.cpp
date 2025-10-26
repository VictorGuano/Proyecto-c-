// CLASE Sobrecarga_de_Operadores
#include <iostream>
#include <string>
# include<stdexcept>
using namespace std;

//1) Uso de de alias de tipos
typedef unsigned int Entero;
typedef string texto;
typedef string Categoria;
typedef float flotante;
typedef unsigned  int Cantidad;

//2)creciion de la case con sus acceso privado y publico
class Producto{
	//privado
	private:
	    Entero codigo;
		texto nombre;
		Categoria categoria;
		flotante precio;
		Cantidad stock;
	//publico
    public:
    //creacion del constructor
    Producto(Entero c, texto n , Categoria cat, flotante p,Cantidad s)
    : codigo(c),nombre(n),categoria (cat), precio (p),stock(s){}
    
    //{--Operadores Miembros--
    
    Producto& operator+=(Cantidad cantidad){
    	stock += cantidad;
    	return *this;
	}
    Producto& operator-=(Cantidad cantidad){
    	if(cantidad> stock)
    	throw  runtime_error("Erro : no hay suficiete stock.");
    	stock-= cantidad;
    	return *this;
	}
    Producto& operator++(){
     ++stock;
	 return *this;	
	}
	
	Producto operator++(int){
		Producto temp =*this;
		++stock;
		return temp;
	}
	
    //--Operadores no miembros (amigos)--
    friend bool operator == (const Producto& a,Producto& b){
    	return a.codigo == a.codigo;
	}
	friend bool operator<(const Producto& a, const Producto& b){
		return a.codigo < b.codigo;
	}
	friend ostream& operator <<(ostream& os , const Producto& p){
		os<<"#"<<p.codigo<<"]"<<p.nombre<<"|Categoria:"<<p.nombre
		<<"|Precio : $"<<p.precio
		<<"|Stock:$"<<p.stock;
		return os;
		
	}
    	
};

int main() {
    Producto p1(101, "Laptop Lenovo", "Computadoras", 799.99f, 15);
    Producto p2(102, "Mouse Logitech", "Perifericos", 25.50f, 50);

    cout << "Producto 1: " << p1 << endl;
    cout << "Producto 2: " << p2 << endl;

    p1 += 5;  // reponer stock
    p2 -= 2;  // vender unidades
    ++p1;     // incremento unitario

    cout << "\nLuego de actualizar:\n";
    cout << p1 << endl;
    cout << p2 << endl;

    if (p1 < p2)
        cout << "El producto 1 tiene un codigo menor.\n";

    return 0;
}
 
