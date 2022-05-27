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

float pedirFloat(string mensaje, float RADIO_MINIMO, string msj1,float RADIO_MAXIMO, string msj2) {
	float numeroComa;
	cout << mensaje << RADIO_MINIMO <<msj1 << RADIO_MAXIMO << msj2;
	cin >> numeroComa;
	return numeroComa;
}

float pedirFloatValido(string mensaje, float RADIO_MINIMO, string msj1, float RADIO_MAXIMO,string msj2, string msj){
	float numeroComa;
	numeroComa = pedirFloat(mensaje, RADIO_MINIMO , msj1 , RADIO_MAXIMO,msj2);
	while ((numeroComa<RADIO_MINIMO)||(numeroComa>RADIO_MAXIMO)) {
		numeroComa = pedirFloat(msj, RADIO_MINIMO, msj1, RADIO_MAXIMO,msj2);
	}
	return numeroComa;
}

string pedirAlfajorValido(string mensaje, string msj) {
	string tipo;
	tipo = pedirString(mensaje);
	while ((tipo != "simple") && (tipo != "SIMPLE") && (tipo != "doble") && (tipo != "DOBLE") && (tipo != "triple") && (tipo != "TRIPLE")) {
		tipo = pedirString(msj);
	}
	return tipo;
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
	const string PEDIR_RADIO = "Ingrese el radio del alfajor por favor (en cm). Recuerde que el radio valido esta entre ";
	const string PEDIR_TIPO = "Ingrese el tipo de alfajor por favor (simple, doble o triple): ";
	const string PRECIO_VENTA = "El precio de venta es: $";
	const string RADIO_NO_VALIDO = "Usted ingreso un radio que no es válido, por favor, ingrese otro(en cm). Recuerde que el radio valido esta entre ";
	const string TIPO_NO_VALIDO = "ERROR DE TIPO DE ALFAJOR. Le solicitamos ingresar uno válido (simple, doble o triple): ";
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

	radio = pedirFloatValido(PEDIR_RADIO,RADIO_MINIMO, " y ", RADIO_MAXIMO,": ", RADIO_NO_VALIDO);

	diametro = radio * 2;

	talfajor = pedirAlfajorValido(PEDIR_TIPO, TIPO_NO_VALIDO);

	valorFijo = cPrecioF(A_SIMPLE, A_DOBLE, A_TRIPLE, talfajor);

	precioTotal = calcularPreciototal(valorFijo, OPERANDO,diametro);

	darPrecioTotal(PRECIO_VENTA, precioTotal);

	saludar(FIN, nombre);

	system("pause");
}
