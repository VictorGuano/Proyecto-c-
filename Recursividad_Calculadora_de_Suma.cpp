#include <iostream>
using namespace std;
//clase 
class CalculadoraSuma{
	public:
		int sumaRecursiva(int n){
			if(n==1){//caso base
			return 1;	
			}else {
				return n+ sumaRecursiva(n-1);
			}
		}
};
//metodo principal
int main(){
	CalculadoraSuma objetoSuma;
	int n=5;
	int resultado =objetoSuma.sumaRecursiva(n);
	cout<<"La suma de los primeros"<< n <<"numeros naturales es"<<resultado<<endl;
	return 0;

}
