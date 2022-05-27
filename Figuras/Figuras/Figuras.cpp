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

char pedirChar(string mensaje) {
	char caracter;
	cout << mensaje;
	cin >> caracter;
	return caracter;
}

float areaTr(float lado1Triangulo, float altura){
	float area;
	area = lado1Triangulo * altura / 2;
	return area;
}

float periTr(float lado1Triangulo, float lado2Triangulo, float lado3Triangulo) {
	float peri;
	peri = lado1Triangulo + lado2Triangulo + lado3Triangulo;
	return peri;
}

float areaCu(float ladosCuadrado) {
	float area;
	area = ladosCuadrado * ladosCuadrado;
	return area;
}

float periCu(float ladosCuadrado) {
	float peri;
	peri = ladosCuadrado * 4;
	return peri;
}

float areaCir(float radio, float PI) {
	float area;
	area = radio * radio * PI;
	return area;
}

float periCir(float radio, float PI) {
	float peri;
	peri = radio * 2 * PI;
	return peri;
}

void darArea(string MENSAJE_FINAL_AREA, float area) {
	cout << MENSAJE_FINAL_AREA << area << endl;
}


void darPerimetro(string MENSAJE_FINAL_PERIMETRO, float perimetro) {

	cout << MENSAJE_FINAL_PERIMETRO << perimetro << endl;;
}


void main() {//programa principal

	setlocale(LC_ALL, "spanish");

	//declaración de variables y constantes
		//Triangulo
	float lado1Triangulo;
	float lado2Triangulo;
	float lado3Triangulo;
	float altura;


	//Cuadrado
	float ladosCuadrado;

	//Circulo
	float radio;
	const float PI = 3.1415;

	//generales
	float area;
	float perimetro;

	char figura;

	string nombre;

	const string MENSAJE_BIENVENIDA = "Bienvenido, ingrese su nombre: ";

	const string PEDIR_FIGURA = "Seleccione la figura (C circulo, T triangulo, Q cuadrado): ";

	const string MENSAJE_TRIANGULO1 = "Indique la medida de la base (en centimetros): ";
	const string MENSAJE_TRIANGULO2 = "Indique la medida de un lado (en centimetros): ";
	const string MENSAJE_TRIANGULO3 = "Indique la medida del otro (en centimetros): ";
	const string MENSAJE_TRIANGULO4 = "Indique la altura (en centimetros): ";


	const string MENSAJE_CUADRADO = "Indique la medida de un lado (todos iguales) (en centimetros): ";

	const string MENSAJE_CIRCULO = "Indique el radio del circulo (en centimetros): ";

	const string MENSAJE_FINAL_PERIMETRO = "El perimetro es (centimetros): ";
	const string MENSAJE_FINAL_AREA = "El area es (centimetros cuadrados): ";

	nombre = pedirString(MENSAJE_BIENVENIDA);

	saludar(nombre);

	figura = pedirChar(PEDIR_FIGURA);

	if (figura == 'T' || figura == 't') {
		cout << MENSAJE_TRIANGULO1;
		cin >> lado1Triangulo;
		cout << MENSAJE_TRIANGULO2;
		cin >> lado2Triangulo;
		cout << MENSAJE_TRIANGULO3;
		cin >> lado3Triangulo;
		cout << MENSAJE_TRIANGULO4;
		cin >> altura;

		perimetro = periTr(lado1Triangulo, lado2Triangulo, lado3Triangulo);
		area = areaTr(lado1Triangulo, altura);
	}
	else if (figura == 'Q' || figura == 'q') {
		cout << MENSAJE_CUADRADO;
		cin >> ladosCuadrado;
		area = areaCu(ladosCuadrado);
		perimetro = periCu(ladosCuadrado);
	}
	else if (figura == 'C' || figura == 'c') {
		cout << MENSAJE_CIRCULO;
		cin >> radio;
		area = areaCir(radio, PI);
		perimetro = periCir(radio, PI);
	}



	darArea(MENSAJE_FINAL_AREA, area);

	darPerimetro(MENSAJE_FINAL_PERIMETRO, perimetro);

	system("pause");
}