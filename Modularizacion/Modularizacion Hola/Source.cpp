#include <iostream>
using namespace std;

string pedirNombre(string mensajeNombre) {
	string cadena;
	cout << mensajeNombre << endl;
	cin >> cadena;
	return cadena;
}

 void saludar(string nombre) {
	cout << "Bienvenido " << nombre << endl;
}

 float pedirPrecioUni(string mensaje) {
	 float numeroComa;
	 cout << "Recuerde que puede abonar con tarjeta o con efectivo." << endl;
	 cout << "Le recordamos que en caso de pagar con efectivo,si compra 5 o menos unidades se le descontara un 5% del total. " << endl;
	 cout << "Si compra mas de 5 unidades, se le hara un descuento del 10%" << endl;
	 cout << "Si paga con tarjeta, se le descontara en 15% del total en caso de que el pedido supere los $1000" << endl;
	 cout << "Por favor, ingrese el precio de lo que va a llevar: $";
	 cin >> numeroComa;
	 return numeroComa;
 }

 int pedirCantidad(string mensaje) {
	int entero;
	cout << "Seleccione la cantidad : ";
	cin >> entero;
	return entero;
 }

 char pedirPago(string mensaje) {
	char caracter;
	cout << "¿Pagara con efectivo o con tarjeta? (seleccionar E para efectivo o T para tarjeta): ";
	cin >> caracter;
	return caracter;
 }

 float condicionales(float precioPorUni, int cantidad, char formaDePago) {
	 float precioTotal;
	 const float DESCUENTO_15_POR_CIENTO = 0.85;
	 const float DESCUENTO_10_POR_CIENTO = 0.90;
	 const float DESCUENTO_5_POR_CIENTO = 0.95;
	 if (formaDePago == 'T' || formaDePago == 't') {
		 if (precioPorUni >= 1000) {

			 precioTotal = precioPorUni * cantidad * DESCUENTO_15_POR_CIENTO;

		 }
		 else {

			 precioTotal = precioPorUni * cantidad;

		 }
	 }
	 else if (formaDePago == 'E' || formaDePago == 'e') {
		 if (cantidad >= 5) {

			 precioTotal = precioPorUni * cantidad * DESCUENTO_10_POR_CIENTO;

		 }
		 else {

			 precioTotal = precioPorUni * cantidad * DESCUENTO_5_POR_CIENTO;

		 }
	 }
	 return precioTotal;
 }

 void darPrecioTotal(float precioTotal) {
	 cout << "El precio total de su pedido es: $" << precioTotal << endl;
 }

 float pedirAbono(string mensaje) {
	float numeroComa;
	cout << "¿Con cuanto abonara? $"; 
	cin >> numeroComa;
	return numeroComa;
 }

 float calcularVuelto(float abono, float precioTotal) {
	 float vuelto;
	 vuelto = abono - precioTotal;
	 return vuelto;
 }

 void darVuelto(float vuelto) {
	 cout << "Su vuelto es: $" << vuelto << endl;
	 cout << " " << endl;
	 cout << " " << endl;
	 cout << " " << endl;//para que el resumen aparezca mas abajo
 }

 string calcularResumen(string mensajeResumen) {
	 string cadena;
	 cout << mensajeResumen;
	 return cadena;
 }

 void darResumen(float precioUni, int cantidad, char formaDePago, float precioTotal,float abono, float vuelto) {
	 cout << "Precio de la unidad $" << precioUni << endl;
	 cout << "Cantidad de unidades: " << cantidad << endl;
	 cout << "Forma de pago: " << formaDePago << endl;
	 cout << "Precio total: $" << precioTotal << endl;
	 cout << "Abona con: $" << abono << endl;
	 cout << "Vuelto: $" << vuelto << endl;




	 cout << "Muchas gracias, hasta luego" << endl;

 }

void main() {
	setlocale(LC_ALL, "spanish");

	string nombre;

	float precioPorUni;

	int cantidad;

	char formaDePago;

	float precioTotal;

	float abono;

	float vuelto;

	string resumen;

	nombre = pedirNombre ("Ingrese su nombre");


	saludar(nombre);

	precioPorUni = pedirPrecioUni("Por favor, ingrese el precio de lo que va a llevar: $");

	cantidad = pedirCantidad("Seleccione la cantidad : ");

	formaDePago = pedirPago("¿Pagara con efectivo o con tarjeta? (seleccionar E para efectivo o T para tarjeta): ");

	precioTotal = condicionales(precioPorUni, cantidad, formaDePago);

	darPrecioTotal(precioTotal);

	abono = pedirAbono("¿Con cuanto abonara?");

	vuelto = calcularVuelto(abono, precioTotal);

	darVuelto(vuelto);

	resumen = calcularResumen("Resumen de la compra");

	darResumen (precioPorUni,  cantidad,  formaDePago,  precioTotal,  abono, vuelto);

	system("pause");
}