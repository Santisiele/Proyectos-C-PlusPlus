#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

string pedirString(string mensaje) {
	string cadena;
	cout << mensaje ;
	cin >> cadena;
	return cadena;
}

void saludar(string mensaje, string nombre) {
	cout << mensaje << nombre << endl;
}

int pedirNum(string mensaje) {
	int num;
	cout << mensaje;
	cin >> num;
	return num;
}

string validarString(string msj,string msj1) {
	string cadena;
	cadena = pedirString(msj);
	while (cadena != "IA" && cadena != "VS") {
		cadena = pedirString(msj1);
	}
	return cadena;
}

int validarNum(string msj, int maximo, string msj2) {
	int num;
	num = pedirNum(msj);
	while (num > maximo) {
		num = pedirNum(msj2);
	}
	return num;
}

int dVidas(string nivel) {
	int vidas;
	if (nivel == "PRINCIPIANTE") {
		vidas = 19;
	}
	else if (nivel == "AVANZADO") {
		vidas = 9;
	}
	else if (nivel == "MAESTRO") {
		vidas = 7;
	}
	return vidas;
}

string validarEleccion(string mensaje, string msj) {
	string nivel;

	nivel = pedirString(mensaje);

	while ((nivel != "PRINCIPIANTE") && (nivel != "AVANZADO") && (nivel != "MAESTRO")) {
		nivel = pedirString(msj);
	}
	return nivel;
} 

int dRango(string nivel) {
	int numA;
	if (nivel == "PRINCIPIANTE") {
		system("color 16");
		numA = 1 + rand() % (501 - 1);
	}
	else if (nivel == "AVANZADO") {
		system("color 17");
		numA = 1 + rand() % (1001 - 1);
	}
	else if (nivel == "MAESTRO") {
		system("color 12");
		numA = 1 + rand() % (2001 - 1);
	}
	return numA;
}

int calcularVidas(string nivel) {
	int vidas;
	if (nivel == "PRINCIPIANTE") {
		vidas = 19;
	}
	else if (nivel == "AVANZADO") {
		vidas = 9;
	}
	else if (nivel == "MAESTRO") {
		vidas = 7;
	}
	return vidas;
}

bool validarRta(int num, int respuesta) {
	return num == respuesta;
}

int juego(string mensaje,int respuesta, string MALME, string MALMA,int vidas) {
	bool logico;

	int num;

	logico = false;

	num = pedirNum(mensaje);

	while (num != respuesta && vidas>0) {
		vidas--;
			if (num < respuesta) {
				num = pedirNum(MALMA);
			}
			else if (num > respuesta) {
				num = pedirNum(MALME);
			}
	}

	if (validarRta(num, respuesta)) {
		logico = true;
	}
	return logico;

	system("cls");
}

void multijugador(string msj,int intentos1,int intentos2,int respuesta,string MALMA, string MALME,string msj2,string GANO2,string GANO1, string EMPATE,string CORRECTOM,string CORRECTOM2,string msj3,string msj4, string msj5, string msj6) {
	int num;
	num = 0;
	int limite;

	system("color AF");

	limite = pedirNum(msj5);

	respuesta = validarNum(msj,limite,msj6);

	system("cls");

	num = pedirNum(msj3);

	while (num != respuesta) {
		intentos1++;
		if (num < respuesta) {
			num = pedirNum(MALMA);
		}
		else if (num > respuesta) {
			num = pedirNum(MALME);
		}
	}
	if (respuesta == num) {
		cout << CORRECTOM << intentos1 << endl;
	}

	system("pause");
	system("cls");

	respuesta = validarNum(msj, limite, msj6);

	system("cls");

	num = pedirNum(msj4);
	while (num != respuesta) {
		intentos2++;
		if (num < respuesta) {
			num = pedirNum(MALMA);
		}
		else if (num > respuesta) {
			num = pedirNum(MALME);
		}
	}
	if (respuesta == num) {
		cout << CORRECTOM2 << intentos2 << endl;
	}

	system("pause");
	system("cls");

	system("color DE");

	if (intentos1 > intentos2) {
		cout << GANO2 << endl;
	}
	else if (intentos1 < intentos2) {
		cout << GANO1 << endl;
	}
	else {
		cout << EMPATE << endl;
	}
	system("pause");
	system("cls");
}

bool eleccion(string modo) {
	return modo == "IA";
}

void main() {
	setlocale(LC_ALL, "spanish");

	const string BIENVENIDA = "Bienvenido al juego 'Guess the number', por favor, ingrese su nombre: ";
	const string NUMERO = "Intente adivinar el número: ";
	const string MALME = "Error, el número incógnito es menor al que usted ingresó: ";
	const string MALMA = "Error, el número incógnito es mayor al que usted ingresó: ";
	const string CORRECTO = "Felicidades, usted acertó el número y ganó el juego";
	const string PERDISTE = "Usted alcanzo el limite de errores y no acerto el número, por lo que perdió - GUESS THE NUMBER";
	const string ELEGIR_NIVEL = "Elige un nivel, principiante, avanzado o maestro (escribir en máyúsculas o no será válido)\nPrincipiante: 20 vidas, 500 números\nAvanzado: 10 vidas, 1000 números\nMAESTRO: 8 vidas, 2000 números\nNivel: ";
	const string NIVEL_INCORRECTO = "Ese nivel no existe, por favor, elija uno válido: Principiante, avanzado o maestro (escribir en máyúsculas o no será válido)\nPrincipiante: 20 vidas, 500 números\nAvanzado: 10 vidas, 1000 números\nMAESTRO: 8 vidas, 2000 números\nNivel: ";
	const string ELEGIR_MODO = "Elija modo de juego: se puede jugar contra la IA o modo VS\nIA: Juega contra la IA y tiene una cantidad determinada de vidas\nJuega contra un amigo, el que adivine el numero en menor cantidad de intentos gana. Cantidad de números a elección\nElija entre IA o VS (mayusculas): ";
	const string MODO_INCORRECTO = "Elija un modo válido\nIA: Juega contra la IA y tiene una cantidad determinada de vidas\nJuega contra un amigo, el que adivine el numero en menor cantidad de intentos gana. Cantidad de números a elección\nElija entre IA o VS (mayusculas): ";
	const string NUMERO_1_1V1 = "Jugador 1, ingrese un número secreto y presione enter: ";
	const string NUMERO_2_1V1 = "Jugador 2, ingrese un número secreto y presione enter: ";
	const string GANO1 = "Ganador: Jugador 1";
	const string GANO2 = "Ganador: Jugador 2";
	const string EMPATE = "EMPATE";
	const string CORRECTOM1 = "Correcto. Cantidad de errores: ";
	const string CORRECTOM2 = "Correcto. Cantidad de errores: ";
	const string NUMERO2 = "Jugador 2, intente adivinar el número incógnito del jugador 1: ";
	const string NUMERO3 = "Jugador 1, intente adivinar el número incógnito del jugador 2: ";
	const string LIMITE = "Elijan del 1 hasta que número son válidos en el juego: ";
	const string PASA_LIMITE = "Ese numero es mayor que el límite, ingrese otro válido: ";

	int error;
	int vidas;
	string nivel;
	string nombre;

	string modo;

	int intentos1;
	int intentos2;
	int respuesta;

	intentos1 = 0;
	intentos2 = 0;
	respuesta = 0;

	

	error = 0;

	int numA; //declaro la variable num de tipo int.
	srand(time(NULL));

	nombre = pedirString(BIENVENIDA);

	saludar("Bienvenido/a ", nombre);

	modo = validarString(ELEGIR_MODO, MODO_INCORRECTO);

	system("pause");
	system("cls");

	if (eleccion(modo)) {
		nivel = validarEleccion(ELEGIR_NIVEL, NIVEL_INCORRECTO);

		numA = dRango(nivel);

		vidas = calcularVidas(nivel);

		if (!juego(NUMERO, numA, MALME, MALMA, vidas)) {
			cout << PERDISTE << endl;
			cout << "El numero incógnito era " << numA << endl;
		}
		else {
			cout << CORRECTO << endl;
		}
	}
	else {
		multijugador(NUMERO_1_1V1, intentos1, intentos2, respuesta, MALMA, MALME, NUMERO_2_1V1, GANO2, GANO1, EMPATE, CORRECTOM1, CORRECTOM2, NUMERO2, NUMERO3,LIMITE,PASA_LIMITE);
	}

	saludar("Hasta luego ", nombre);

	system("pause");
}