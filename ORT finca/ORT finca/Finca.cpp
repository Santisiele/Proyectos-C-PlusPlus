#include <iostream>
using namespace std;

void main() {


	int seleccionUva;
	const float PRECIOUVAGENERAL = 100;
	const float PRECIOUVA1A = 0.20;
	const float PRECIOUVA1B = 0.30;
	const float PRECIOUVA2A = 0.30;
	const float PRECIOUVA2B = 0.50;



	cout << "Bienvenido a ORT Finca, por favor, seleccione el tipo y tamanio de uva (Tamanio 1 y 2 y tipo A y B). " << endl;
	cout << "El precio por el kilo de uva es de $" << PRECIOUVAGENERAL << endl;
	cout << "En el caso de pedir el tipo A tamanio 1, se le suman $" << PRECIOUVA1A << " y en caso de ser del tipo A tamanio 2 se le suman $" << PRECIOUVA2A << endl;
	cout << "En el caso de pedir el tipo B tamanio 1 se le descuentan $" << PRECIOUVA1B << " y en el caso de ser tipo B tamanio 2 se le descuentan $" << PRECIOUVA2B << endl;

	cout << "Por favor, seleccione el tipo y tamanio de uva (recuerde que solo se puede de un tipo y tamanio)" << endl;
	cout << "Le solicitamos elegir entre 1A, 2A, 1B y 2B siguiendo la siguiente tabla:" << endl;
	cout << "1A = 1" << endl;
	cout << "2A = 2" << endl;
	cout << "1B = 3" << endl;
	cout << "2B = 4" << endl;




	cin >> seleccionUva;

	if (seleccionUva == 1) {


		cout << "El precio de su pedido es: $" << PRECIOUVAGENERAL + PRECIOUVA1A << endl;


	} else if(seleccionUva == 2) {
	

		cout << "El precio de su pedido es: $" << PRECIOUVAGENERAL + PRECIOUVA2A << endl;
	
	}
	else if(seleccionUva==3) {


		cout << "El precio de su pedido es: $" << PRECIOUVAGENERAL - PRECIOUVA1B << endl;


	}
	else if (seleccionUva == 4) {



		cout << "El precio de su pedido es: $" << PRECIOUVAGENERAL - PRECIOUVA2B << endl;

	}
	else {


		cout << "ERROR, ESA UVA NO EXISTE" << endl;


	}

	cout << "Muchas gracias por realizar su pedido" << endl;


		system("pause");
}