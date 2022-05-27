#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

void darString(string mensaje) {
	cout << mensaje;
}

void darDados(int num1, int num2, int num3, int num4, int num5) {
	cout << " " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;
}

int caras(int minimo, int maximo, string men1, string men2) {
	int num;
	cout << men1;
	cin >> num;
	while ((num < minimo) || (num > maximo)) {
		cout << men2;
		cin >> num;
	}
	return num;
}

int numeroR(int caras) {
	int num;
	num = 1 + rand() % (caras);
	return num;
}

bool nGenerala(int dado1, int dado2, int dado3, int dado4, int dado5) {
	return ((dado1 != dado2) || (dado2 != dado3) || (dado3 != dado4) || (dado4 != dado5));
}

bool distintos(int dado1, int dado2, int dado3, int dado4, int dado5) {
	return (dado1 != dado2 && dado1 != dado3 && dado1 != dado4 && dado1 != dado5 && dado2 != dado3 && dado2 != dado4 && dado2 != dado5 && dado3 != dado4 && dado3 != dado5 && dado4 != dado5);
}

bool verEscalera(int caras) {
	bool logico;
	if (caras = 6) {
		logico = true;
	}
	else {
		logico = false;
	}
	return logico;
}

bool escalera(int dado1, int dado2, int dado3, int dado4, int dado5) {
	return (dado1 + dado2 + dado3 + dado4 + dado5 == 15) || (dado1 + dado2 + dado3 + dado4 + dado5 == 19) || (dado1 + dado2 + dado3 + dado4 + dado5 == 20);
}

void main() {
	setlocale(LC_ALL, "spanish");
	srand(time(NULL));
	const string BIENVENIDA = "Bienvenido/a al simulador de generala.\nEl programa consiste en simular tiradas de 5 dados y mostrar cuantas tiradas fueron necesarias para hacer generala (los 5 dados iguales)\nTambién muestra si hizo escalera, o si todos los numeros fueron distintos, permitiendo elegir las caras de los dados.";
	const string NUMERO_CARAS = "Usted debe elegir la cantidad de caras de los dados: ";
	const string AVANZAR = "Presione enter para empezar";
	const string CARAS_MAL = "El numero que ingresó está fuera de límites, ingrese uno válido";
	const string GENERALA = "¡Felicidades, consiguió la generala! Lo hizo en ";
	const string DISTINTOS = "Tocaron todos dados distintos  ";
	const string ESCALERA = "Le salió escalera ";

	int MINIMO = 3;
	int MAXIMO = 10;

	int dado1;
	int dado2;
	int dado3;
	int dado4;
	int dado5;

	int cara;

	int intentos;
	intentos = 1;

	int todosDif;
	todosDif = 1;

	int esc;
	esc = 1;

	darString(BIENVENIDA);
	cout << endl;
	cara = caras(MINIMO, MAXIMO, NUMERO_CARAS, CARAS_MAL);

	dado1 = numeroR(cara);
	dado2 = numeroR(cara);
	dado3 = numeroR(cara);
	dado4 = numeroR(cara);
	dado5 = numeroR(cara);

	if (verEscalera(cara)) {
		while (nGenerala(dado1, dado2, dado3, dado4, dado5)) {
			intentos++;
			if (distintos(dado1, dado2, dado3, dado4, dado5)) {
				todosDif++;
				if (escalera(dado1, dado2, dado3, dado4, dado5)) {
					esc++;
				}
			}
			dado1 = numeroR(cara);
			dado2 = numeroR(cara);
			dado3 = numeroR(cara);
			dado4 = numeroR(cara);
			dado5 = numeroR(cara);
		}
		cout << ESCALERA << esc << " veces" << endl;

	}
	else {
		while (nGenerala(dado1, dado2, dado3, dado4, dado5)) {
			intentos++;
			if (distintos(dado1, dado2, dado3, dado4, dado5)) {
				todosDif++;
			}
			dado1 = numeroR(cara);
			dado2 = numeroR(cara);
			dado3 = numeroR(cara);
			dado4 = numeroR(cara);
			dado5 = numeroR(cara);
		}
	}
	darString(GENERALA);

	cout << "Usted tardo " << intentos << " tiradas" << endl;

	cout << DISTINTOS << todosDif << " veces" << endl;

	cout << "Ultima tirada ";

	darDados(dado1, dado2, dado3, dado4, dado5);

	system("pause");
}