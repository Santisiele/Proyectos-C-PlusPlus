#include <iostream>
using namespace std;


//Definición del programa principal
void main() {
	//declaración de variables
	float numero1;
	float numero2;
	float extraccion;
	float suma;
	float multiplicacion;

	cout << "Bienvenido" << endl;
	//ingreso numeros
	cout << "Asignale un valor al primer numero" << endl;
	cin >> numero1;
	cout << "Numero 1= " << numero1<< endl;


	cout << "Asignale un valor al segundo numero" << endl;
	cin >> numero2;
	cout << "numero2= " << numero2 << endl;


	suma = numero1 + numero2;
	extraccion = numero1 - numero2; //puse extracccion porque con resta me tiraba error
	multiplicacion = numero1 * numero2;

	//resolucion
	cout << "Los resultados son:" << endl;
	cout << "Suma: " <<numero1 <<" + "<<numero2<<" = "<< suma << endl;
	cout << "Resta:  " << numero1 << " - " << numero2 << " = "<<extraccion << endl;
	cout << "Multiplicacion:  " << numero1 << " X " << numero2<<" = " <<multiplicacion << endl;



	if (numero2 != 0) {
		float division;
		division = numero1 / numero2;
		cout << "division: " << numero1 << "/" << numero2<<" = " << division << endl;

	}else{


		cout << "Division: " << numero1 << "/" << numero2 << "=" << "NO SE PUEDE DIVIDIR POR 0" << endl;

	}


	system("pause");
}