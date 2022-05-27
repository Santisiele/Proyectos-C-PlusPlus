#include <iostream>
using namespace std;

void main() {
	//declaración constantes
	const float DESCUENTO_5_POR_CIENTO = 0.95;
	const float DESCUENTO_10_POR_CIENTO = 0.90;
	const float DESCUENTO_15_POR_CIENTO = 0.85;

	//declaración variables (datos de entrada)
	string nombre;
	float precioUni;
	int cantidad;
	char formaDePago;
	float precioTotal;
	float pago;
	float vuelto;



	//Interaccion con el usuario
	cout << "Ingrese su nombre" << endl;
	cin >> nombre;
	cout << "Bienvenido a StanK Company " << nombre << endl;


	cout << "Recuerde que puede abonar con tarjeta o con efectivo." << endl;
	cout << "Le recordamos que en caso de pagar con efectivo,si compra 5 o menos unidades se le descontara un 5% del total. " << endl;
	cout << "Si compra mas de 5 unidades, se le hara un descuento del 10%" << endl;
	cout << "Si paga con tarjeta, se le descontara en 15% del total en caso de que el pedido supere los $1000" << endl;
	cout << "Por favor, ingrese el precio de lo que va a llevar: $";
	cin >> precioUni;
	cout << "Seleccione la cantidad: ";
	cin >> cantidad;
	cout << "¿Pagara con efectivo o con tarjeta? (seleccionar E para efectivo o T para tarjeta): ";
	cin >> formaDePago;

	//Calculo de precio (if)
	if (formaDePago == 'T' || formaDePago == 't') {
		if (precioUni >= 1000) {

			precioTotal = precioUni * cantidad * DESCUENTO_15_POR_CIENTO;

		}
		else {

			precioTotal = precioUni * cantidad;

		}
	}
	else if (formaDePago == 'E' || formaDePago == 'e') {
		if (cantidad >= 5) {

			precioTotal = precioUni * cantidad * DESCUENTO_10_POR_CIENTO;

		}
		else {

			precioTotal = precioUni * cantidad * DESCUENTO_5_POR_CIENTO;

		}
	}



	cout << "El precio total de su pedido es: $" << precioTotal << endl;

	cout << "Con cuanto abonara la compra? $";
	cin >> pago;

	vuelto = pago - precioTotal;

	cout << "Resumen de la compra" << endl;
	cout << "Precio de la unidad $" << precioUni << endl;
	cout << "Cantidad de unidades: " << cantidad << endl;
	cout << "Forma de pago: " << formaDePago << endl;
	cout << "Precio total: $" << precioTotal << endl;
	cout << "Abona con: $" << pago << endl;
	cout << "Vuelto: $" << vuelto << endl;




	cout << "Muchas gracias, hasta luego" << endl;








	system("pause");
}