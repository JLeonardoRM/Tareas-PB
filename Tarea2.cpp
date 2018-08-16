#include <iostream>
#include <Windows.h>
using namespace std;

char nombre[20], apellido[20], telefono[20];
int edad, a, x = 0;

int main()
{
	do
	{
		a = 0;
		system("cls");
		cout << "    Menu:\n" << endl;
		cout << "    1) Ingresar Datos" << endl;
		cout << "    2) Ver datos ingresados" << endl;
		cout << "    3) Salir\n" << endl;
		cout << "Ingresa un numero segun la opccion deseada: ";
		cin >> a;
		
		switch (a)
		{
		case 1:

			do {
				system("cls");
				cout << "Ingrese su primer nombre....\n\nNombre: ";
				cin >> nombre;
				cout << "\nIngrese su primer apellido....\n\nApellido: ";
				cin >> apellido;

				system("cls");
				cout << "Hola " << nombre << ", " << apellido << ".\n\n";
				Sleep(1500);
				system("cls");
				cout << "Cual es tu edad " << nombre << "?\n\n" << "Edad: ";
				cin >> edad;
				cout << "Y tu numero de telefono?\n\nTelefono: ";
				cin >> telefono;

				x++;
				system("cls");
				cout << "_______________________" << endl;
				cout << "Nombre: " << nombre << ", " << apellido << ".\n" << "Edad: " << edad << " a\xA4os." << endl << "Telefono: +52 " << telefono << "." << endl;
				cout << "_______________________" << endl;
				cout << "\n\nQuieres editar tus datos?\n" << "SI(1)   NO(2)\n";
				cin >> a;

			} while (a != 2);
			system("cls");
			cout << "Eso es todo, ya guardamos tus datos " << nombre << ".\n\n" << endl;
			system("pause");
			break;

		case 2:
			system("cls");
			if (x != 0)
			{
				cout << "_______________________" << endl;
				cout << "Nombre: " << nombre << ", " << apellido << ".\n" << "Edad: " << edad << " a\xA4os." << endl << "Telefono: +52 " << telefono << "." << endl;
				cout << "_______________________" << endl;
				system("pause");
			}
			else
			{
				cout << "Primero ingrese sus datos.....\n\n";
				system("pause");
			}

			break;
		}

	} while (a != 3);

	system("cls");
	cout << "Hasta luego " << nombre << ".\n\n";

	Sleep(1500);

}
