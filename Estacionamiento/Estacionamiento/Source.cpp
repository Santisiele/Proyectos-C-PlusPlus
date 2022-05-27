#include <iostream>
using namespace std;



string pedirString(string mensajeNombre) {
	string cadena;
	cout << mensajeNombre << endl;
	cin >> cadena;
	return cadena;
}


void saludar(string nombre) {
	cout << "Bienvenido " << nombre << endl;
}

int pedirHora(string mensaje, int APERTURA, int CIERRE) {
	int entero;
	cout << mensaje;
	cin >> entero;
	return entero;
}

bool hValido(int hora) {
	bool logico;
	if ((hora>=0) && (hora<24)) {
		logico=true;
	}
	else {
		logico=false;
	}
	return logico;
}

bool estaAbierto(int hora, int APERTURA, int CIERRE) {
	bool logico;
	if ((hora >= APERTURA) && (hora <= CIERRE)) {
		logico = true;
	}
	else {
		logico = false;
	}
	return logico;
}
 


void main() {

	setlocale(LC_ALL, "spanish");

	string nombre;

	const string MENSAJE_BIENVENIDA = "Bienvenido, ingrese su nombre: ";
	const string PEDIR_HORARIO = "Por favor, ingrese el horario en el que quiere dejar su auto: ";
	const string ABIERTO = "El estacionamiento esta abierto a esa hora, puede dejar el auto";
	const string CERRADO = "El estacionamiento NO esta abierto a esa hora, lo sentimos";
	const string NO_VALIDO = "Ha ingresado una hora incorrecta - ESTACIONAMIENTO BRUSELAS (el dia va de 0 a 23 ;)";
	const int APERTURA = 10;
	const int CIERRE = 18;

	int hora;

	nombre = pedirString(MENSAJE_BIENVENIDA);

	saludar(nombre);

	hora = pedirHora(PEDIR_HORARIO, APERTURA, CIERRE);

	if (hValido(hora) == false) {
		cout << NO_VALIDO << endl;
	}
	else {
		if (estaAbierto(hora, APERTURA, CIERRE) == true) {
			cout << ABIERTO << endl;
		}
		else {
			cout << CERRADO << endl;
		}

	}
	system("pause");
}