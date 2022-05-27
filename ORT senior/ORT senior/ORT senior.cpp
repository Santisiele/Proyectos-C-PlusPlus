#include <iostream>
using namespace std;

string ingresarStr() {
	string cadena;
	cin >> cadena;
	return cadena;
}

void darStr(string mensaje) {
	cout << mensaje;
}

int ingresarInt() {
	int entero;
	cin >> entero;
	return entero;
}

int ingresarEdad(int E_MIN, string msj) {
	int num;
	num = ingresarInt();
	while (num < E_MIN) {
		cout << msj;
		cin >> num;
	}
	return num;
}

int masGrande(int edadGr, int edad) {
	int num;
	if (edadGr > edad) {
		num = edadGr;
	}
	else {
		num = edad;
	}
	return num;
}

bool fin(string apellido, string FIN) {
	return apellido == FIN;
}

bool masde30(int edad) {
	return edad > 30;
}

void main() {
	setlocale(LC_ALL, "spanish");
	const string BIENVENIDA = "Bienvenidos a ORT senior, deberán ingresar su apellido y edad para ser procesados (no menos de 18). Cuando terminan, escribir FIN (mayúsculas)";
	const string M_APELLIDO = "Ingrese su apellido por favor: ";
	const string M_EDAD = "Ingrese su edad por favor: ";
	const string NO_EDAD = "La persona no puede ser menor a 18 años: ";
	const int E_MIN = 18;
	const string FIN = "FIN";

	string apellido;
	int edad;
	int edades;
	int numEdades;
	int edadesSumadas;
	float promedio;
	int edadGr;
	int edadmas30;

	numEdades = 0;
	edadesSumadas = 0;
	promedio = 0; 
	edadGr = 0;
	edadmas30 = 0;


	darStr(BIENVENIDA);
	
	darStr(M_APELLIDO);
	apellido = ingresarStr();

	if (!fin(apellido, FIN)) {
		darStr(M_EDAD);
		edad = ingresarEdad(E_MIN, NO_EDAD);

		numEdades++;
		edadesSumadas = edadesSumadas + edad;

		if (masde30(edad)) {
			edadmas30++;
		}

		promedio = edadesSumadas / numEdades;
		edadGr = masGrande(edadGr, edad);
	}

	while (!fin(apellido, FIN)) {
		darStr(M_APELLIDO);
		apellido = ingresarStr();

		if (!fin(apellido, FIN)) {
			darStr(M_EDAD);
			edad = ingresarEdad(E_MIN, NO_EDAD);

			numEdades++;
			edadesSumadas = edadesSumadas + edad;

			if (masde30(edad)) {
				edadmas30++;
			}

			promedio = edadesSumadas / numEdades;
			edadGr = masGrande(edadGr, edad);
		}
	}

	cout << "Edad promedio: " << promedio << endl;
	cout << "Mayor edad: " << edadGr << endl;
	cout << "Gente mayor a los 30 años: " << edadmas30 << endl;

	system("pause");
}