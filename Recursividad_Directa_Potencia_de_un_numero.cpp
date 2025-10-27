# include <iostream>
//Ejemplo de Recursividad Directa
//Recursividad
//Este ejemplo muestra cómo calcular la potencia de un número usando
//recursividad directa.
using namespace std;
class Potencia {
	public:
	int calcularPotencia(int base, int exponente){
		if(exponente == 0){//caso base
		return 1;	
		
		}else{
		//aqui es donde va la operacion : return.........
		return base*calcularPotencia(base, exponente-1);//caso recursividad	
		}
	}
};
int main(){
	Potencia potencia;
	int base, exponente;
	cout<<"Ingrese la base; ";
	cin>> base;
	cout<<"Ingrese el exponente: ";
	cin>> exponente;
	cout<<"Potencia"<<potencia.calcularPotencia(base,exponente)<<endl;
	
}
