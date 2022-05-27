#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

char pedirChar(string msj) {
    char caracter;
    cout << msj;
    cin >> caracter;
    return caracter;
}

int busqueda(int numero, int vector[], int tope) {
    int posicion;
    int i = 0;


    while (numero != vector[i] && i < tope) {
        i++;
    }


    if (i == tope) {
        posicion = -1;
    }
    else {
        posicion = i;
    }

    return posicion;
}

int generarRandom(int limite_inferior, int limite_superior, int vec[], int TOPE) {
    int numero;
    int busquedaPosicion;
    numero = limite_inferior + rand() % (limite_superior - limite_inferior);

    busquedaPosicion = busqueda(numero, vec, TOPE);

    while (busquedaPosicion != -1) {
        numero = limite_inferior + rand() % (limite_superior - limite_inferior);
        busquedaPosicion = busqueda(numero, vec, TOPE);
    }
    return numero;
}

void generarTablero(int vector[], int tope, int LIMITE_INFERIOR, int LIMITE_SUPERIOR) {
    int numeroRandom;
    for (int i = 0; i < tope; i++) {
        numeroRandom = generarRandom(LIMITE_INFERIOR, LIMITE_SUPERIOR, vector, tope);
        vector[i] = numeroRandom;

    }
}

void mostrarPelotas(int pelotas, int casillas, int tablero) {
    cout << pelotas << " Esta en el tablero del jugador " << tablero << endl;
    cout << "Le faltan completar " << casillas << " casillas" << endl;
}

void mostrarTABLERO(int vec[], int TOPE, int tab) {
    cout << "Jugador " << tab << " sus n�meros de tablero son: " << endl;
    for (int i = 0; i < TOPE; i++) {
        cout << vec[i] << endl;
    }
}

void ganador(int libre1, int libre2) {
    if (libre1 < libre2) {
        cout << "El ganador del BINGO es el jugador 1" << endl;
    }
    else {
        cout << "El ganador del BINGO es el jugador 2" << endl;
    }
}

void superGanador(int jugador1, int jugador2) {
    if (jugador1 > jugador2) {
        cout << "El ganador de mas partidas fue el jugador 1 que gan� " << jugador1 << " contra " << jugador2 << " veces del jugador 2" << endl;
    }
    else if (jugador1 < jugador2) {
        cout << "El ganador de mas partidas fue el jugador 2 que gan� " << jugador2 << " contra " << jugador1 << " veces del jugador 1" << endl;
    }
    else {
        cout << "Hubo un empate. Ambos jugadores ganaron " << jugador1 << " veces" << endl;
    }
}

int ObtenerBolilla(int LIMITE_INFERIOR, int LIMITE_SUPERIOR, int vecPelotas[])
{
    int pelotas = 0;
    pelotas = generarRandom(LIMITE_INFERIOR, LIMITE_SUPERIOR, vecPelotas, LIMITE_SUPERIOR);

    while (vecPelotas[pelotas] >= 1)
    {
        pelotas = generarRandom(LIMITE_INFERIOR, LIMITE_SUPERIOR, vecPelotas, LIMITE_SUPERIOR);

    }
    vecPelotas[pelotas] ++;
    return pelotas;
}

int main() {
    setlocale(LC_ALL, "spanish");
    srand(time(NULL));
    //constantes
    system("color 70");
    const string BIENVENIDA = "Bienvenidos al Bingo\n2 jugadores\nCada jugador tiene 1 tablero con 9 n�meros\nEl primero en completar su tablero gana\n";
    const string REPETIR = "Oprime R para volver a jugar, si no, presion� cualquier letra: ";
    const string VER_TABLERO = "Si queres ver tu tablero, presiona T, si no, ingrese cualquier letra: ";
    const int CANTIDAD_NUMEROS = 9;
    const int LIMITE_INFERIOR = 1;
    const int LIMITE_SUPERIOR = 30;
    const int TAB1 = 1;
    const int TAB2 = 2;

    //variables
    int numeroRandom;
    int tablero1;
    int tablero2;
    int pelotas;
    int posicion;
    char caracter;
    int jugador1;
    int jugador2;
    int casillaLibres1;
    int casillaLibres2;

    //inicializaci�n
    jugador1 = 0;
    jugador2 = 0;

    //vectores
    int vecTablero1[CANTIDAD_NUMEROS]{ 0 };
    int vecTablero2[CANTIDAD_NUMEROS]{ 0 };
    int vecPelotas[LIMITE_SUPERIOR]{ 0 };

    //desarrollo
    cout << BIENVENIDA;
    system("pause");
    system("cls");
    do {
        casillaLibres1 = CANTIDAD_NUMEROS;
        casillaLibres2 = CANTIDAD_NUMEROS;

        generarTablero(vecTablero1, CANTIDAD_NUMEROS, LIMITE_INFERIOR, LIMITE_SUPERIOR);

        mostrarTABLERO(vecTablero1, CANTIDAD_NUMEROS, TAB1);
        cin.get();

        generarTablero(vecTablero2, CANTIDAD_NUMEROS, LIMITE_INFERIOR, LIMITE_SUPERIOR);

        mostrarTABLERO(vecTablero2, CANTIDAD_NUMEROS, TAB2);
        cin.get();
        system("cls");

        while ((casillaLibres1 > 0) && (casillaLibres2 > 0)) {

            pelotas = ObtenerBolilla(LIMITE_INFERIOR, LIMITE_SUPERIOR, vecPelotas);

            posicion = busqueda(pelotas, vecPelotas, CANTIDAD_NUMEROS);

            cout << "La bolilla que sali� es la n�mero " << pelotas << ": " << endl;
            cin.get();

            posicion = busqueda(pelotas, vecTablero1, CANTIDAD_NUMEROS);

            if (posicion != -1) {
                casillaLibres1--;
                mostrarPelotas(pelotas, casillaLibres1, TAB1);
            }
            else {
                cout << "El jugador 1 no ten�a este n�mero.\nLe quedan " << casillaLibres1 << " casillas por completar para ganar" << endl;
            }
            caracter = pedirChar(VER_TABLERO);
            if ((caracter == 'T') || (caracter == 't')) {
                mostrarTABLERO(vecTablero1, CANTIDAD_NUMEROS, TAB1);
            }
            system("pause");
            system("cls");

            posicion = busqueda(pelotas, vecTablero2, CANTIDAD_NUMEROS);

            if (posicion != -1) {
                casillaLibres2--;
                mostrarPelotas(pelotas, casillaLibres2, TAB2);
            }
            else {
                cout << "El jugador 2 no ten�a este n�mero\nLe quedan " << casillaLibres2 << " casillas por completar para ganar" << endl;
            }
            caracter = pedirChar(VER_TABLERO);
            if ((caracter == 'T') || (caracter == 't')) {
                mostrarTABLERO(vecTablero2, CANTIDAD_NUMEROS, TAB2);
            }
            system("pause");
            system("cls");
        }
        if (casillaLibres1 == 0) {
            jugador1++;
        }
        else {
            jugador2++;
        }

        ganador(casillaLibres1, casillaLibres2);
        caracter = pedirChar(REPETIR);
        system("cls");
    } while ((caracter == 'R') || (caracter == 'r'));
    superGanador(jugador1, jugador2);
    cout << "Hasta luego, esperamos que hayan disfrutado" << endl;
    system("pause");
}