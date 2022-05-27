#include <iostream>
using namespace std;

string pedirCadena(string msj) {
    string cadena;
    cout << msj << endl;
    cin >> cadena;
    return cadena;
}

int pedirEntero(string msj) {
    int entero;
    cout << msj << endl;
    cin >> entero;
    return entero;
}

int pedirEnteroValidado(string msj, string msj2, int minimo) {
    int entero;
    entero = pedirEntero(msj);
    while (entero < minimo) {
        entero = pedirEntero(msj2);
    }
    return entero;
}

char pedirChar(string msj, string msj2, char cond1, char cond2) {
    char caracter;
    cout << msj << endl;
    cin >> caracter;
    while ((caracter != cond1) and (caracter != cond2)) {
        cout << msj2 << endl;
        cin >> caracter;
    }
    return caracter;
}

int busqueda(string cadena, string vector[], int tope) {
    int posicion;
    int i = 0;

    //mientras que no encuentre el apellido Y haya apellidos
    while (cadena != vector[i] && i < tope) {
        i++;
    }

    //no lo encontre?
    if (i == tope) {
        posicion = -1;
    }
    else {
        posicion = i;
    }

    return posicion;
}


int busquedaEntero(int entero, int vector[], int tope) {
    int posicion;
    int i = 0;

    //mientras que no encuentre el apellido Y haya apellidos
    while (entero != vector[i] && i < tope) {
        i++;
    }

    //no lo encontre?
    if (i == tope) {
        posicion = -1;
    }
    else {
        posicion = i;
    }

    return posicion;
}


void empleados(int vector[], int tope, string msj) {
    for (int i = 0; i < tope; i++) {
        cout << msj << i + 1 << " es " << vector[i] << endl;
    }
}

void productos(int vector[], string vec[], int tope, string msj) {
    for (int i = 0; i < tope; i++) {
        cout << msj << i + 1 << " es " << vector[i] << endl;
    }
}

int calcularVendedorMaximo(int vector[], int TOPE) {
    int maximo;
    maximo = 0;

    int posicion;

    for (int i = 0; i < TOPE; i++) {
        if (vector[i] > maximo) {
            maximo = vector[i];
            posicion = i;
        }
        else {

        }
    }
    return posicion;

}

void mostrarFINAL(int vecCANTIDAD[], string vecYATES[], int TOPE) {
    for (int i = 0; i < TOPE; i++) {
        cout << vecYATES[i] << " vendio " << vecCANTIDAD[i] << endl;
    }
}

void mostrarEmpleado(int MayorVendedor, int tarjeta, int efectivo) {
    cout << "El empleado que mas vendio fue el numero: " << MayorVendedor + 1 << endl;
    cout << "Lo recudado por ventas en tarjeta fue : " << tarjeta << endl;
    cout << "Lo recudado por ventas en Efectivo fue : " << efectivo << endl;

}

int main() {
    setlocale(LC_ALL, "spanish");

    //constantes
    const string MENSAJE_DNI = "Por favor, ingrese su numero de DNI: ";
    const string MENSAJE_ERROR = "Hubo un error en el ingreso.\nPor favor, intente nuevamente: ";
    const string MENSAJE_NO_STOCK = "No hay stock.\nPor favor, intente nuevamente: ";
    const string MENSAJE_PAGO = "Ingrese la forma de pago con la que desea abonar:\n('T' para tarjeta y 'E')";
    const string MENSAJE_YATE = "Ingrese el modelo de yate que desea:\nRecuerde que nuestros modelos son:\n-Megayate\n-Catamaran\n-Velero\n-Grande\n-Pequeño";
    const string MENSAJE_EMPLEADO = "Ingrese el empleado que lo atendio:\n(Recuerde que cada uno se identifica por un numero correspondido entre el 0 y 9)";
    const string MENSAJE_VENTAS_EMPLEADOS = "La cantidad de ventas del empleado ";
    const int CANTIDAD_YATES = 5;
    const int CANTIDAD_EMPLEADOS = 10;
    const int FIN_DE_DATOS = 0;
    const char TARJETA = 'T';
    const char EFECTIVO = 'E';
    const float DESCUENTO = 0.9;

    //vectores
    string vecYates[CANTIDAD_YATES]{ "Megayate", "Catamaran", "Velero", "Grande", "Pequenio" };
    int vecPrecios[CANTIDAD_YATES]{ 35000, 32500, 25000, 30000, 15000 };
    int vecStock[CANTIDAD_YATES]{ 10, 11, 12, 13, 14 };
    int vecContadorXYate[CANTIDAD_YATES]{ 0 };
    int vecEmpleados[CANTIDAD_EMPLEADOS]{ 0,1,2,3,4,5,6,7,8,9 };

    //variables
    char formaPago;
    string yate;
    int dni;
    int empleado;
    int posicionEmpleados;
    int posicionYates;
    int precioTotal;
    int recaudacionTarjeta;
    int recaudacionEfectivo;
    int VendedorMaximo;
    int ventas;
    int valor;

    //inicializacion
    recaudacionTarjeta = 0;

    ventas = 0;

    recaudacionEfectivo = 0;

    VendedorMaximo = -1;

    dni = pedirEnteroValidado(MENSAJE_DNI, MENSAJE_ERROR, FIN_DE_DATOS);

    while (dni != 0) {

        yate = pedirCadena(MENSAJE_YATE);

        posicionYates = busqueda(yate, vecYates, CANTIDAD_YATES);

        while (posicionYates == -1) {
            cout << MENSAJE_ERROR;

            yate = pedirCadena(MENSAJE_YATE);

            posicionYates = busqueda(yate, vecYates, CANTIDAD_YATES);
        }

        while (vecStock[posicionYates] == 0) {
            yate = pedirCadena(MENSAJE_NO_STOCK);

            posicionYates = busqueda(yate, vecYates, CANTIDAD_YATES);
        }

        vecContadorXYate[posicionYates]++;

        empleado = pedirEntero(MENSAJE_EMPLEADO);

        posicionEmpleados = busquedaEntero(empleado, vecEmpleados, CANTIDAD_EMPLEADOS);

        while (posicionEmpleados == -1) {
            empleado = pedirEntero(MENSAJE_ERROR + MENSAJE_EMPLEADO);

            posicionEmpleados = busqueda(yate, vecYates, CANTIDAD_YATES);
        }

        formaPago = pedirChar(MENSAJE_PAGO, MENSAJE_ERROR, EFECTIVO, TARJETA);

        vecEmpleados[empleado]++;

        valor = vecPrecios[posicionYates];

        if (formaPago == EFECTIVO) {
            precioTotal = valor * DESCUENTO;
            recaudacionEfectivo = recaudacionEfectivo + precioTotal;

        }
        else {
            precioTotal = valor;
            recaudacionTarjeta = recaudacionTarjeta + precioTotal;
        }


        cout << "Resumen de la venta: " << endl;
        cout << "DNI: " << dni << endl;
        cout << "Precio a pagar: " << precioTotal << endl;

        vecStock[posicionYates]--;

        ventas++;
        
        dni = pedirEnteroValidado(MENSAJE_DNI, MENSAJE_ERROR, FIN_DE_DATOS);
    }

    if (ventas > 0) {
        VendedorMaximo = calcularVendedorMaximo(vecEmpleados, CANTIDAD_EMPLEADOS);
        mostrarFINAL(vecContadorXYate, vecYates, CANTIDAD_YATES);
        mostrarEmpleado(VendedorMaximo, recaudacionTarjeta, recaudacionEfectivo);
    }
    else {
        cout << "No hubo ventas :(" << endl;
    }
    system("pause");
}