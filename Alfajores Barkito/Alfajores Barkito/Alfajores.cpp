#include <iostream>
using namespace std;

string pedirString(string mensaje) {
	string cadena;
	cout << mensaje;
	cin >> cadena;
	return cadena;
}


void saludar(string mensaje, string nombre) {
	cout << mensaje << nombre << endl;
}

float pedirFloat(string mensaje) {
	float numeroComa;
	cout << mensaje << endl;
	cin >> numeroComa;
	return numeroComa;
}

bool estaEnRango(float radio, float RADIO_MINIMO, float RADIO_MAXIMO, string talfajor) {
	bool logico;
	if ((radio >= RADIO_MINIMO) && (radio <= RADIO_MAXIMO)) {
		logico = true;
	}
	else {
		logico = false;
	}
	return logico;
}

bool alfajorValido(string talfajor) {
	bool logico;
	if ((talfajor != "simple") || (talfajor != "SIMPLE") || (talfajor != "doble") || (talfajor != "DOBLE") || (talfajor != "triple") || (talfajor != "TRIPLE")) {
		logico = true;
	}
	else {
		logico = false;
	}
	return logico;
}

float cPrecioF(float A_SIMPLE, float A_DOBLE, float A_TRIPLE, string talfajor) {
	float valorFijo;
	if ((talfajor == "simple") || (talfajor == "SIMPLE")) {
		valorFijo = A_SIMPLE;
	}
	else if ((talfajor == "doble") || (talfajor == "DOBLE")) {
		valorFijo = A_DOBLE;
	}
	else if ((talfajor == "triple") || (talfajor == "TRIPLE")) {
		valorFijo = A_TRIPLE;
	}
	return valorFijo;
}

float calcularPreciototal(float valorFijo, float OPERANDO, float diametro) {
	float precioTotal;
	precioTotal = valorFijo + (diametro * OPERANDO);
	return precioTotal;
}

void darPrecioTotal(string PRECIO_VENTA, float precioTotal) {
	cout << PRECIO_VENTA << precioTotal << endl;
}

void main() {

	setlocale(LC_ALL, "spanish");

	string nombre;
	//CONSTANTES
	const string MENSAJE_BIENVENIDA = "Bienvenido/a, ingrese su nombre: ";
	const string PEDIR_RADIO = "Ingrese el radio del alfajor por favor: ";
	const string PEDIR_TIPO = "Ingrese el tipo de alfajor por favor (simple, doble o triple): ";
	const string PRECIO_VENTA = "El precio de venta es: $";
	const string RADIO_NO_VALIDO = "ALFAJOR DESECHADO";
	const string TIPO_NO_VALIDO = "ERROR DE TIPO DE ALFAJOR";
	const string FIN = "Hasta luego, muchas gracias por confiar en alfajores barkito. Hasta luego ";
	const float A_SIMPLE = 10;
	const float A_DOBLE = 15;
	const float A_TRIPLE = 20;
	const float OPERANDO = 5;
	const float RADIO_MINIMO = 3;
	const float RADIO_MAXIMO = 5;

	//variables
	string talfajor;
	float radio;
	float diametro;
	float precioTotal;
	float valorFijo;

	nombre = pedirString(MENSAJE_BIENVENIDA);

	saludar("Bienvenido/a ", nombre);

	radio = pedirFloat(PEDIR_RADIO);

	diametro = radio * 2;

	if (estaEnRango(radio, RADIO_MINIMO, RADIO_MAXIMO, talfajor)) {
		if (!alfajorValido(talfajor)) {
			cout << TIPO_NO_VALIDO << endl;
		}
		else {
			talfajor = pedirString(PEDIR_TIPO);

			valorFijo = cPrecioF(A_SIMPLE, A_DOBLE, A_TRIPLE, talfajor);

			precioTotal = calcularPreciototal(valorFijo, OPERANDO, diametro);

			darPrecioTotal(PRECIO_VENTA, precioTotal);
		}
	}
	else {
		cout << RADIO_NO_VALIDO << endl;
	}

	saludar(FIN, nombre);

	system("pause");
}
