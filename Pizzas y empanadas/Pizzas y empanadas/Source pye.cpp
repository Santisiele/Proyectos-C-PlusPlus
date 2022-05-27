#include<iostream> //Con estas lineas me conecto a teclado y pantalla
using namespace std;

//Definición del programa principal
void main() {
	string nombreUsuario; //Declaración de variable nombreUsuario
	string Contraseña; //Declaración variable contraseña
	int pizzasMuzzarella;
	int pizzasNapolitana;
	int pizzasJamonYMorrones;
	int pizzasFugazzeta;
	int empanadasCarne;
	int empanadasPollo;
	int empanadasJYQ;
	int cocciónPizzas;
	int cocciónEmpanadas;
	int PRECIO_EMPANDAS;
	int PRECIO_PIZZAS;
	int propina;
	int abono;
	PRECIO_EMPANDAS = 35;
	PRECIO_PIZZAS = 110;
	int precioTotal;




	cout << "Bienvenido" << endl;

	cout << "Ingrese nombre de usuario:" << endl;
	cin >> nombreUsuario; //Ingresar valor para nombreUsuario

	cout << "Su nombre de usuario es: " << nombreUsuario << endl;


	cout << "Ingrese su contrasenia por favor:" << endl;
	cin >> Contraseña;

	cout << "Su contrasenia es:" << Contraseña << endl;

	cout << "Cada empanada cuesta:$ " << PRECIO_EMPANDAS;
	cout << ". Mientras que cada pizza cuesta:$
		" << PRECIO_PIZZAS << endl;
	cout << "Seleccione cantidad de empanadas de carne:" << endl;
	cin >> empanadasCarne;
	cout << "Seleccione cantidad de empanadas de pollo:" << endl;
	cin >> empanadasPollo;
	cout << "Seleccione cantidad de empanadas de JYQ:" << endl;
	cin >> empanadasJYQ;
	cout << "Seleccione cantidad de pizzas de muzzarella:" << endl;
	cin >> pizzasMuzzarella;
	cout << "Seleccione cantidad de pizzas a la napolitana:" << endl;
	cin >> pizzasNapolitana;
	cout << "Seleccione cantidad de pizzas de fugazzeta:" << endl;
	cin >> pizzasFugazzeta;
	cout << "Seleccione cantidad de pizzas de jamon y morrones:" << endl;
	cin >> pizzasJamonYMorrones;

	cout << "Seleccione el formato de la pizza(mas de 5 sera a media masa y 5 o menos sera a la piedra):" << endl;
	cin >> cocciónPizzas;


	cout << "Seleccione el formato de las empanadas (mas de 5 sera al horno y menos de 5 sera fritas)" << endl;
	cin >> cocciónEmpanadas;
	cout << "Seleccione la cantidad de propina" << endl;
	cin >> propina;

	cout << "Resumen del pedido:" << endl;
	cout << "Empanadas de carne: " << empanadasCarne << endl;
	cout << "Empanadas de pollo:" << empanadasPollo << endl;
	cout << "Empanadas de JYQ:" << empanadasJYQ << endl;
	cout << "Pizzas de Muzza:" << pizzasMuzzarella << endl;
	cout << "Pizzas de fugazzeta:" << pizzasFugazzeta << endl;
	cout << "Pizzas a la napoitana" << pizzasNapolitana << endl;
	cout << "Pizzas de jamon y morrones:" << pizzasJamonYMorrones << endl;
	cout << "Coccion de empanadas (mas de 5 al horno, 5 o menos fritas)" << cocciónEmpanadas << endl;
	cout << "Coccion de pizzas (mas de 5 media masa, 5 o menos a la piedra)" << cocciónPizzas << endl;

	cout << "Numero total de pizzas:" << pizzasMuzzarella + pizzasFugazzeta + pizzasJamonYMorrones + pizzasNapolitana << endl;
	cout << "Numero total de empanadas:" << empanadasCarne + empanadasJYQ + empanadasPollo << endl;


	cout << "Precio del pedido:$" << PRECIO_EMPANDAS * empanadasCarne + PRECIO_EMPANDAS * empanadasPollo + PRECIO_EMPANDAS * empanadasJYQ + PRECIO_PIZZAS * pizzasFugazzeta + PRECIO_PIZZAS * pizzasJamonYMorrones + PRECIO_PIZZAS * pizzasMuzzarella + PRECIO_PIZZAS * pizzasNapolitana + propina << endl;
	precioTotal = PRECIO_EMPANDAS * empanadasCarne + PRECIO_EMPANDAS * empanadasPollo + PRECIO_EMPANDAS * empanadasJYQ + PRECIO_PIZZAS * pizzasFugazzeta + PRECIO_PIZZAS * pizzasJamonYMorrones + PRECIO_PIZZAS * pizzasMuzzarella + PRECIO_PIZZAS * pizzasNapolitana + propina;


	cout << "Con cuanto abonara su pedido ? " << endl;
	cin >> abono;
	cout << "su vuelto sera: $" << abono - precioTotal << endl;

	cout << "Su pedido esta siendo procesado, le llegara en 1 h aproximadamente, gracias" << endl;
	system("pause");
}