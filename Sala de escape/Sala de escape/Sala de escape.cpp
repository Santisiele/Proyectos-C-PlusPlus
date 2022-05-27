#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

string pedirString(string mensaje) {
	string cadena;
	cout << mensaje;
	cin >> cadena;
	return cadena;
}

void saludar(string mensaje,string nombre) {
	cout << mensaje  << nombre << endl;
}

bool validarRta(string cadena, string respuesta) {
	return cadena == respuesta;
}

int salas(string mensaje, int error,string PISTA,string respuesta,string MAL, string BIENVENIDA,string CORRECTO,string PERDISTE, string mensaje2, string PISTA2, string respuesta2, string mensaje3, string PISTA3, string respuesta3) {
	string cadena;
	cout << BIENVENIDA << endl;
	cadena = pedirString(mensaje);

	while (error != 2 && cadena != "PISTA" && cadena != respuesta) {
		error++;
		cadena = pedirString(MAL);
	}
	while (cadena == "PISTA") {
		cadena = pedirString(PISTA);
	}
	if (!validarRta(cadena, respuesta)) {
		error++;
	}
	else {
		cout << CORRECTO << endl;

		cadena = pedirString(mensaje2);

		while (error != 2 && cadena != "PISTA" && cadena != respuesta2) {
			error++;
			cadena = pedirString(MAL);
		}
		while (cadena == "PISTA") {
			cadena = pedirString(PISTA2);
		}
		if (!validarRta(cadena, respuesta2)) {
			error++;
		}
		else {
			cout << CORRECTO << endl;
			cadena = pedirString(mensaje3);

			while (error != 2 && cadena != "PISTA" && cadena != respuesta3) {
				error++;
				cadena = pedirString(MAL);
			}
			while (cadena == "PISTA") {
				cadena = pedirString(PISTA3);
			}
			if (!validarRta(cadena, respuesta3)) {
				error++;
			}
			else {
				cout << CORRECTO << endl;
			}
		}
	}
	if (error == 3) {
		system("cls");
		system("color 04");
		cout << PERDISTE << endl;
	}
	return error;
}

int main() {
	system("color 67");

	setlocale(LC_ALL, "spanish");
	  

	//CONSTANTES
	const string MENSAJE_BIENVENIDA = "Bienvenido/a a la mejor sala de escape 'ESCAPE DEPORTIVO'\nEsta contará con 4 acertijos deportivas en los cuales usted tendrá que resolver escribiendo siempre en mayúsculas.\nSi tiene dudas, puede pedir una pista escribiendo PISTA.\nSi usted tiene 3 errores, perdera el juego\nSolo puede escribir en mayúsculas, de lo contrario, la entrada será inválida. Escribir solo una PALABRA, el apellido\nTiempo máximo: 4 minutos\nIngrese su nombre: ";
	const string BIENVENIDO = "Bienvenido ";

	const string PREGUNTA_1_1 = "Fue nombrado el mejor jugador joven del último mundial de fútbol (2018): ";
	const string PISTA_1_1 = "En ese entonces era juador del PSG (6 letras): ";
	const string RTA_1_1 = "MBAPPE";
	const string PREGUNTA_1_2 = "Enganche, jugó mucho tiempo en boca, ganando las copas libertadores del 2000 y 2007 entre otras: ";
	const string PISTA_1_2 = "El último 10 (8 letras): ";
	const string RTA_1_2 = "RIQUELME";
	const string PREGUNTA_1_3 = "Portugues, fue jugador del real madrid, ganó la champions y perdió una final de una intercontinental: ";
	const string PISTA_1_3 = "En el real jugó de extremo (4 letras): ";
	const string RTA_1_3 = "FIGO";

	const string PREGUNTA_2_1 = "Es el mayor ganador del Roland Garros en la era Open (1968 hasta la actualidad): ";
	const string PISTA_2_1 = "Es español (5 letras): ";
	const string RTA_2_1 = "NADAL";
	const string PREGUNTA_2_2 = "Serbio, llego a ser top 1 del mundo en varios años, entre ellos 2020: ";
	const string PISTA_2_2 = "Organizó una fiesta que contrajo varios casos de COVID (8 letras): ";
	const string RTA_2_2 = "DJOKOVIC";
	const string PREGUNTA_2_3 = "Ganador con argentina de la Copa Davis en 2016 ganando el ultimo partido: ";
	const string PISTA_2_3 = "Su nombre es Federico (8 letras): ";
	const string RTA_2_3 = "DELBONIS";

	const string PREGUNTA_3_1 = "Considerado por muchos el mejor jugador de la historia de la NBA, con el record de promedira 30.1 puntos x partido\ny ganador de 6 anillos: ";
	const string PISTA_3_1 = "Tiene una miniserie de los Bulls llamada 'The last dance' (6 letras): ";
	const string RTA_3_1 = "JORDAN";
	const string PREGUNTA_3_2 = "Uno de los mejores tiradores de 3 de la NBA, juega en los warriors (junio 2020): ";
	const string PISTA_3_2 = "Poscición: Base (5 letras): ";
	const string RTA_3_2 = "CURRY";
	const string PREGUNTA_3_3 = "Alero, debutó en la NBA en cleveland, peró también jugo en Miami Heat y en Los Lakers, 3 anillos y rookie of the year\nentre muchos otros premios y distinciones: ";
	const string PISTA_3_3 = "APODADO 'The King' (5 letras): ";
	const string RTA_3_3 = "JAMES";

	const string PREGUNTA_4_1 = "Club de futbol argentino ganador de 6 copas Libertadores hasta la fecha (junio 2020): ";
	const string PISTA_4_1 = "El que mas copas ganó, el que nunca descendio (4 letras): ";
	const string RTA_4_1 = "BOCA";
	const string PREGUNTA_4_2 = "Club de basquet de Los Angeles. 16 anillos (junio 2020): ";
	const string PISTA_4_2 = "Color predominante en su escudo: amarillo (6 letras): ";
	const string RTA_4_2 = "LAKERS";
	const string PREGUNTA_4_3 = "Club de futbol europeo ganador de 19 ligas domésticas y 6 champions league junto a\nmuchas otras copas (junio 2020): ";
	const string PISTA_4_3 = "You'll never walk alone (9 letras): ";
	const string RTA_4_3 = "LIVERPOOL";

	const string MAL = "Error, vuelva a intentarlo: ";
	const string CORRECTO = "CORRECTO";
	const string PERDISTE_ERRORES = "GAME OVER. Usted cometió 3 errores";
	const string PERDISTE_TIEMPO = "GAME OVER. UUsted tardó mas del tiempo dado´para la resolución";
	const string GANADOR = "Felicidades, usted demostró saber bastante en el área deportiva";

	const string SALA1 = "Bienvenido a la primer sala. Temática: futbolistas ";
	const string SALA2 = "Felicitaciones por llegar hasta aca, la sala 2. Temática: tenistas ";
	const string SALA3 = "Esto se pone mas dìficl, sala 3. Temática: basquetbolistas";
	const string SALA4 = "Bienvenido a la ultima sala, sala 4. Temática: clubes deportivos";

	const string FIN = "Hasta luego ";

	//variables
	string nombre;
	string respuesta;
	int errores;

	time_t tInicial;
	time_t tFinal;
	int tiempo;
	int minutos;
	int segundos;
	int segundos1;
	int minutos1;

	errores = 0;

	tInicial = 0;
	tFinal = 0;


	//llamados

	nombre = pedirString(MENSAJE_BIENVENIDA);

	saludar(BIENVENIDO, nombre);


	system("pause");
	system("cls");
	system("color BC");

	tInicial = time(0);

	errores = salas(PREGUNTA_1_1, errores, PISTA_1_1, RTA_1_1, MAL, SALA1, CORRECTO, PERDISTE_ERRORES, PREGUNTA_1_2,PISTA_1_2, RTA_1_2, PREGUNTA_1_3, PISTA_1_3, RTA_1_3);
	if (errores != 3) {
		system("pause");
		system("cls");
		system("color 70");
		errores = salas(PREGUNTA_2_1, errores, PISTA_2_1, RTA_2_1, MAL, SALA2, CORRECTO, PERDISTE_ERRORES, PREGUNTA_2_2, PISTA_2_2, RTA_2_2, PREGUNTA_2_3, PISTA_2_3, RTA_2_3);
		if (errores != 3) {
			system("pause");
			system("cls");
			system("color 5B");
			errores = salas(PREGUNTA_3_1, errores, PISTA_3_1, RTA_3_1, MAL, SALA3, CORRECTO, PERDISTE_ERRORES, PREGUNTA_3_2, PISTA_3_2, RTA_3_2, PREGUNTA_3_3, PISTA_3_3, RTA_3_3);
			if (errores != 3) {
				system("pause");
				system("cls");
				system("color 16");
				errores = salas(PREGUNTA_4_1, errores, PISTA_4_1, RTA_4_1, MAL, SALA4, CORRECTO, PERDISTE_ERRORES, PREGUNTA_4_2, PISTA_4_2, RTA_4_2, PREGUNTA_4_3, PISTA_4_3, RTA_4_3);
				tFinal = time(0);
				tiempo = tInicial - tFinal;

				minutos1 = tiempo / 60;
				segundos1 = tiempo % 60;
				segundos = segundos1 - segundos1 - segundos1; //pasar de negativo a positivo se me ocurrio así
				minutos = minutos1 - minutos1 - minutos1; //pasar de negativo a positivo se me ocurrio así

				if ((errores != 3)&& (minutos<4)) {
					system("pause");
					system("cls");

					system("color B0");

					cout << GANADOR << endl;

					cout << "Usted tardo " << minutos << ":" << segundos << " en completar la sala de escape" << endl;
				}
				else {
					system("cls");
					system("color 04");
					if (minutos > 4) {
						cout << PERDISTE_TIEMPO << endl;
						cout << "Usted tardo " << minutos << ":" << segundos << " en completar la sala de escape.\nLo sentimos, pero no fue sufiiente :(" << endl;
					}
					else if (errores==3){
						cout << PERDISTE_ERRORES << endl;
					}
				}
			}
			else{
				system("cls");
				system("color 04");
				cout << PERDISTE_ERRORES << endl;
			}
		}
		else {
			system("cls");
			system("color 04");
			cout << PERDISTE_ERRORES << endl;
		}
		}
	system("pause");
	system("cls");


		saludar(FIN, nombre);
		system("pause");
	}