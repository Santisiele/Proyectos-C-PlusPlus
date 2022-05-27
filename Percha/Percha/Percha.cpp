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

void despedir(string DESPEDIDA, string nombre) {

	cout << DESPEDIDA << nombre << endl;

}

float pedirFloat(string mensaje) {
	float numeroComa;
	cout << mensaje << endl;
	cin >> numeroComa;
	return numeroComa;
}

bool validarT(float lado1, float lado2, float lado3) {
	bool logico;
	if ((lado1 > lado2 + lado3) || (lado2 > lado1 + lado3) || (lado3 > lado1 + lado2)) {
		logico = false;
	}
	else {
		logico = true;
	}
	return logico;
}

bool tEquilareo(float lado1, float lado2, float lado3) {
	bool valido;
	if ((lado1 == lado2) && (lado1 == lado3)) {
		valido = true;
	}
	else {
		valido = false;
	}
	return valido;
}

bool tIsosceles(float lado1, float lado2, float lado3) {
	bool valido;
	if ((lado1 == lado2) || (lado1 == lado3) || (lado2==lado3)) {
		valido = true;
	}
	else {
		valido = false;
	}
	return valido;
}

bool tEscaleno(float lado1, float lado2, float lado3) {
	bool valido;
	if ((lado1 != lado2) && (lado1 != lado3) && (lado2 != lado3)) {
		valido = true;
	}
	else {
		valido = false;
	}
	return valido;
}

void dTriangulo(string EQUILATERO, string ISOSCELES, string ESCALENO, float lado1, float lado2, float lado3) {
	if (tEquilareo(lado1, lado2 ,lado3)) {
		cout << EQUILATERO << endl;
	}
	else if (tIsosceles(lado1, lado2, lado3)) {
		cout << ISOSCELES << endl;
	}
	else if(tEscaleno(lado1, lado2, lado3)){
		cout << ESCALENO << endl;
	}
}


void main() {

	setlocale(LC_ALL, "spanish");

	string nombre;

	const string MENSAJE_BIENVENIDA = "Bienvenido, ingrese su nombre: ";
	const string NO_VALIDO = "La forma de la percha no es válida, por favor, revise el teorema de desigualdad triangular - LA PERCHA";
	const string PEDIRA = "Ingrese el lado A de la percha: ";
	const string PEDIRB = "Ingrese el lado B de la percha: ";
	const string PEDIRC = "Ingrese el lado C de la percha: ";
	const string EQUILATERO = "La percha es equilatero";
	const string ISOSCELES = "La percha es isósceles";
	const string ESCALENO = "La percha es escaleno";
	const string DESPEDIDA = "Muchas gracias por usar LA PERCHA, hasta luego ";

	float lado1;
	float lado2;
	float lado3;

	bool validacion;


	nombre = pedirString(MENSAJE_BIENVENIDA);

	saludar(nombre);

	lado1 = pedirFloat(PEDIRA);

	lado2 = pedirFloat(PEDIRB);

	lado3 = pedirFloat(PEDIRC);

	validacion = validarT(lado1, lado2, lado3);

	if (validacion == false) {
		cout << NO_VALIDO << endl;
	}
	else
	{
		dTriangulo(EQUILATERO, ISOSCELES, ESCALENO, lado1, lado2, lado3);
	}


	despedir(DESPEDIDA, nombre);

	system("pause");
}