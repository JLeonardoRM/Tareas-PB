#include<iostream>
#include<fstream>//creacion y escritura de archivos
#include<stdio.h> //los get_s y manipulacion de archivos
#include<ctype.h>//validar caracteres
#include<string> //manipulacion de caracteres
#include<Windows.h>//USar comando Sleep
using namespace std;

struct persona {

	string nombre;
	char numeroC[50];
	char correo[50];
	char apeP[50];
	char apeM[50];
	char matricula[50];
	int cal1;
	int cal2;
	int cal3;
	string calle;
	string numCasa;
	string colonia;

}contacto;


void nuevoAlumno();
void mostrar();
void busqueda();
void mostrarBusqueda();
/*void eliminar();*/

int main()
{

	int a;
	do
	{
		system("cls");
		cout << "    Menu:\n\n" << endl;
		cout << "    1) Nuevo alumno" << endl;
		cout << "    2) Lista de Alumnos" << endl;
		cout << "    3) Editar alumno" << endl;
		cout << "    4) Eliminar Alumno" << endl;
		cout << "    5) Salir" << endl;
		cout << "\n\nSelecione el numero de la opcion deseada: ";
		cin >> a;

		switch (a)
		{
		case 1:nuevoAlumno();
			break;
		case 2:mostrar();
			break;
			/*case 3:
				system("cls");
				mostrarBusqueda();
				busqueda();
				break;*/
				/*case 4:eliminar();*/
			break;

		}
	} while (a != 5);
}

void mostrar()
{
	int i = 0;
	int x = 1, vcolonia = 0;
	system("cls");
	cout << "\n";
	ifstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::in);
	cout << "Contactos" << endl;
	cout << "_______________________" << endl;
	alumnos >> contacto.nombre;
	while (!alumnos.eof())
	{
		x = 1;
		cout << "Nombre: " << contacto.nombre;
		alumnos >> contacto.nombre;
		alumnos >> contacto.apeP;
		alumnos >> contacto.apeM;
		alumnos >> contacto.numeroC;
		alumnos >> contacto.correo;
		alumnos >> contacto.matricula;

		cout << " " << contacto.nombre;
		cout << " " << contacto.apeP << " " << contacto.apeM << endl;
		cout << "Numero: " << contacto.numeroC << endl;
		cout << "Correo: " << contacto.correo << endl;
		cout << "Matricula: " << contacto.matricula << endl;
		cout << "Dirreccion: ";
		do
		{
			alumnos >> contacto.calle;
			cout << contacto.calle << " ";
			i = 0, vcolonia = 0;



			while (contacto.calle[i])
			{
				if ((contacto.calle[i]) == ' ')
				{


				}
				else
				{
					i++;

				}

				if ((contacto.calle[i]) == '.')
				{
					x = 0;
				}

				if (isdigit(contacto.calle[i]))
				{
					vcolonia = 1;
				}
			}
			if (vcolonia != 0)
			{
				cout << ", Colonia ";
			}

		} while (x != 0);
		int promedio;
		alumnos >> contacto.cal1;
		alumnos >> contacto.cal2;
		alumnos >> contacto.cal3;
		promedio = contacto.cal1 + contacto.cal2 + contacto.cal3;
		promedio = promedio / 3;
		cout << "\nPromedio: " << promedio;

		alumnos >> contacto.nombre;
		cout << "\n_______________________" << endl;
	}
	alumnos.close();
	system("pause");

}
/*
void busqueda()
{
	int i = 0, elije, z = 0, log, x, vcolonia = 0;
	char auxMat[25], auxN[25];
	while (auxMat[24])
	{
		auxMat[i] = '\0';
		i++;
	}
	i = 0;
	while (auxN[24])
	{
		auxN[i] = '\0';
		i++;
	}
	i = 0;

	cout << "\n";
	ofstream aux;
	ifstream alumnos;
	aux.open("alumnos.txt", ios::out);
	alumnos.open("alumnos.txt", ios::in);

	cout << "\n Ingrese matricula que desea buscar: " << endl;
	cin >> auxMat;
	alumnos >> contacto.matricula;
	log = strlen(contacto.matricula);
	while (contacto.matricula[i])
	{
		auxN[i] = contacto.nombre[i];
		i++;
	}
	i = 0;
	cout << "_______________________" << endl;

	while (!alumnos.eof())
	{
		x = 1;
		cout << "Nombre: " << contacto.nombre;
		alumnos >> contacto.nombre;
		alumnos >> contacto.apeP;
		alumnos >> contacto.apeM;
		alumnos >> contacto.numeroC;
		alumnos >> contacto.correo;
		alumnos >> contacto.matricula;

		cout << " " << contacto.nombre;
		cout << " " << contacto.apeP << " " << contacto.apeM << endl;
		cout << "Numero: " << contacto.numeroC << endl;
		cout << "Correo: " << contacto.correo << endl;
		cout << "Matricula: " << contacto.matricula << endl;
		cout << "Dirreccion: ";
		do
		{
			alumnos >> contacto.calle;
			cout << contacto.calle << " ";
			i = 0, vcolonia = 0;



			while (contacto.calle[i])
			{
				if ((contacto.calle[i]) == ' ')
				{


				}
				else
				{
					i++;

				}

				if ((contacto.calle[i]) == '.')
				{
					x = 0;
				}

				if (isdigit(contacto.calle[i]))
				{
					vcolonia = 1;
				}
			}
			if (vcolonia != 0)
			{
				cout << ", Colonia ";
			}


		} while (x != 0);
		alumnos >> contacto.nombre;
		cout << "\n_______________________" << endl;


		while (contacto.matricula[i])
		{

			if (auxMat[i] == auxN[i])
			{
				z++;
			}
			i++;
		}
		if (z == log)
		{
			do {

				cout << "\n\n¿Desea editar este alumno?" << endl;
				cout << "  1)si" << endl;
				cout << "  2)no" << endl;
				cin >> elije;
				if (elije == 1)
				{

						void nuevoAlumno();

				}
			} while (elije != 2);
		}
		i = 0;
		aux << contacto.nombre << "  " << contacto.apeP << "  " << contacto.apeM << "  " << contacto.numeroC << "  " << contacto.correo << "  " << contacto.matricula << "  " << contacto.calle << " " << contacto.numCasa << " " << contacto.colonia << "." << "\n\n";
		while (auxN[i])
		{
			auxN[i] = '\0';
			i++;
		}
		i = 0, z = 0;
		alumnos >> contacto.matricula;
		log = strlen(contacto.matricula);
		while (contacto.matricula[i])
		{
			auxN[i] = contacto.matricula[i];
			i++;
		}
		i = 0;


	}

	alumnos.close();
	aux.close();
	remove("alumnos.txt");
	rename("Auxalumnos.txt", "alumnos.txt");
	cout << "Contactos Guardados.\n" << endl;
	system("pause");

}*/
/*
void eliminar()
{
	int i = 0, elije, z = 0, log, x, y;
	char auxMat[25], auxN[25];
	while (auxMat[24])
	{
		auxMat[i] = '\0';
		i++;
	}
	i = 0;
	while (auxN[24])
	{
		auxN[i] = '\0';
		i++;
	}
	i = 0;
	system("cls");
	cout << "\n";
	ofstream aux;
	ifstream alumnos;
	aux.open("AUXalumnos.txt", ios::out);
	alumnos.open("alumnos.txt", ios::in);

	cout << "\n Ingrese nombre que desea buscar: " << endl;
	cin >> auxMat;
	alumnos >> contacto.nombre;
	log = strlen(contacto.nombre);
	while (contacto.nombre[i])
	{
		auxN[i] = contacto.nombre[i];
		i++;
	}
	i = 0;
	cout << "_______________________" << endl;

	while (!alumnos.eof())
	{
		alumnos >> contacto.apellido;
		alumnos >> contacto.numeroC;
		alumnos >> contacto.correo;
		while (contacto.nombre[i])
		{

			if (auxMat[i] == auxN[i])
			{
				z++;
			}
			i++;
		}
		if (z == log)
		{

			system("cls");
			cout << "Nombre: " << contacto.nombre;
			cout << " " << contacto.apellido << endl;
			cout << "Numero: " << contacto.numeroC << endl;
			cout << "Correo: " << contacto.correo << endl;
			cout << "_______________________" << endl;
			cout << "\n\n¿Desea ELIMINAR este contacto?" << endl;
			cout << "  1)si" << endl;
			cout << "  2)no" << endl;
			cin >> elije;



		}
		i = 0;
		if (elije != 1)
		{
			aux << contacto.nombre << " " << contacto.apellido << " " << contacto.numeroC << " " << contacto.correo << endl;
		}

		while (auxN[i])
		{
			auxN[i] = '\0';
			i++;
		}
		i = 0, z = 0;
		alumnos >> contacto.nombre;
		log = strlen(contacto.nombre);
		while (contacto.nombre[i])
		{
			auxN[i] = contacto.nombre[i];
			i++;
		}
		i = 0;


	}

	alumnos.close();
	aux.close();
	remove("alumnos.txt");
	rename("Auxalumnos.txt", "alumnos.txt");
	system("cls");
	cout << "Eliminado.\n" << endl;
	system("pause");

}*/

void nuevoAlumno()
{

	int x, i = 0, z, log, auxi, y;
	int dec = 1;
	string telefono;
	system("cls");
	ofstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::app);
	if (alumnos.fail())
	{
		cout << "Error al abrir el archivo";
		system("pause");
	}
	else
	{
		getline(cin, contacto.nombre);
		do
		{


			do {
				system("cls");
				cout << "Nombres: " << endl;

				getline(cin, contacto.nombre);

				x = 0, i = 0, auxi = 0;
				while (contacto.nombre[i])
				{

					if (!isalpha(contacto.nombre[i]))
					{
						if (!iswspace(contacto.nombre[i]))
						{
							auxi = i;

							x = 1;
							cout << "Ingrese su nombre por favor...";
							Sleep(1800);
						}

					}

					i++;

				}
			} while (x != 0);
			do {
				system("cls");
				cout << "Apellido Paterno: " << endl;

				gets_s(contacto.apeP);
				log = strlen(contacto.apeP);
				x = 0, i = 0, auxi = 0;
				while (contacto.apeP[i])
				{

					if (!isalpha(contacto.apeP[i]))
					{


						auxi = i;
						i = log - 1;
						x = 1;


					}

					i++;

				}
			} while (x != 0);
			do {
				system("cls");
				cout << "Apellido Materno: " << endl;

				gets_s(contacto.apeM);
				log = strlen(contacto.apeM);
				x = 0, i = 0, auxi = 0;
				while (contacto.apeM[i])
				{

					if (!isalpha(contacto.apeM[i]))
					{


						auxi = i;
						i = log - 1;
						x = 1;


					}

					i++;

				}
			} while (x != 0);


			do {
				system("cls");
				cout << "Numero" << endl;
				x = 0;
				z = 0;

				gets_s(contacto.numeroC);


				while (contacto.numeroC[x])
				{
					if (!isdigit(contacto.numeroC[x]))
					{

						z = 1;
					}
					x++;
				}
				system("cls");

				log = strlen(contacto.numeroC);
				if (log < 8 || log > 12)
				{
					cout << "error longitud" << endl;
					Sleep(1500);
					z = z + 1;
				}

			} while (z != 0);//validacion numero
			do {
				system("cls");
				cout << "Matricula: " << endl;
				x = 0;
				z = 0;

				gets_s(contacto.matricula);


				while (contacto.matricula[x])
				{
					if (!isdigit(contacto.matricula[x]))
					{

						z = 1;
					}
					x++;
				}
				system("cls");

				log = strlen(contacto.matricula);
				if (log < 7 || log > 7)
				{
					cout << "Una matricula se compone de unicamente 7 numeros..." << endl;
					z = z + 1;
					system("pause");
				}

			} while (z != 0);
			do
			{
				system("cls");
				i = 0; y = 0;
				cout << "\n\nIngrese su Correo Electronico: ";
				gets_s(contacto.correo);
				log = strlen(contacto.correo);
				while (contacto.correo[i])
				{
					if ((contacto.correo[i]) == ('@')) {
						y = 1;
					}
					i++;

				}
				if (y != 0)
				{
					i = 0;
					_strrev(contacto.correo);


					while (contacto.correo[i])
					{
						if ((contacto.correo[i]) == ('m'))
						{
							i++;
							if ((contacto.correo[i]) == ('o'))
							{
								i++;
								if ((contacto.correo[i]) == ('c'))
								{
									i++;
									if ((contacto.correo[i]) == ('.'))
									{
										y = 3;
									}
									i = log;
								}
								i = log;
							}
							i = log;
						}
						else {
							cout << "Error, Debe contener '@' y ''.com''";
							Sleep(2000);
						}
						i = log;

					}
					_strrev(contacto.correo);
				}
				else {
					cout << "Error, Debe contener '@' y ''.com''";
					Sleep(2000);
				}
			} while (y != 3);

			system("cls");
			cout << "Direccion\n\nCalle: ";
			getline(cin, contacto.calle);
			cout << "\nNumero exterior: ";
			cin >> contacto.numCasa;
			getline(cin, contacto.colonia);
			cout << "\nColonia: ";
			getline(cin, contacto.colonia);

			do {
				system("cls");
				cout << "Calificaciones\nCalificacion 1: ";

				z = 0;

				cin >> (contacto.cal1);


				if (contacto.cal1 < 0 || contacto.cal1 > 100)
				{
					cout << "Solo valores de 0 a 100..." << endl;
					Sleep(1800);
					z = z + 1;
				}


			} while (z != 0);
			do {
				system("cls");
				cout << "Calificacion 2: ";

				z = 0;

				cin >> (contacto.cal2);


				if (contacto.cal2 < 0 || contacto.cal2 > 100)
				{
					cout << "Solo valores de 0 a 100..." << endl;
					Sleep(1800);
					z = z + 1;
				}


			} while (z != 0);
			do {
				system("cls");
				cout << "Calificacion 3: ";

				z = 0;

				cin >> (contacto.cal3);


				if (contacto.cal3 < 0 || contacto.cal3 > 100)
				{
					cout << "Solo valores de 0 a 100..." << endl;
					Sleep(1800);
					z = z + 1;
				}


			} while (z != 0);


			alumnos << contacto.nombre << "  " << contacto.apeP << "  " << contacto.apeM << "  " << contacto.numeroC << "  " << contacto.correo << "  " << contacto.matricula << "  " << contacto.calle << " " << contacto.numCasa << " " << contacto.colonia << "." << contacto.cal1 << " " << contacto.cal2 << " " << contacto.cal3 << "\n\n";
			cout << "\n\n desea ingresar otro contacto a la alumnos.? ";
			cout << "\n\n 1=si, 2=no \n" << endl;
			if (dec != 1)
			{
				cin >> dec;
			}





		} while (dec != 1);


	}

	alumnos.close();

}

void mostrarBusqueda()
{
	int i = 0;
	int x = 1, vcolonia = 0;
	string clave;
	system("cls");
	cout << "\n";
	ifstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::in);
	cout << "Contactos" << endl;
	cout << "_______________________" << endl;
	alumnos >> contacto.nombre;
	while (!alumnos.eof())
	{
		x = 1;
		cout << "Nombre: " << contacto.nombre;
		alumnos >> contacto.nombre;
		alumnos >> contacto.apeP;
		alumnos >> contacto.apeM;
		alumnos >> contacto.numeroC;
		alumnos >> contacto.correo;
		alumnos >> contacto.matricula;

		cout << " " << contacto.nombre;
		cout << " " << contacto.apeP << " " << contacto.apeM << endl;
		cout << "Numero: " << contacto.numeroC << endl;
		cout << "Correo: " << contacto.correo << endl;
		cout << "Matricula: " << contacto.matricula << endl;
		cout << "Dirreccion: ";
		do
		{
			alumnos >> contacto.calle;
			cout << contacto.calle << " ";
			i = 0, vcolonia = 0;



			while (contacto.calle[i])
			{
				if ((contacto.calle[i]) == ' ')
				{


				}
				else
				{
					i++;

				}

				if ((contacto.calle[i]) == '.')
				{
					x = 0;
				}

				if (isdigit(contacto.calle[i]))
				{
					vcolonia = 1;
				}
			}
			if (vcolonia != 0)
			{
				cout << ", Colonia ";
			}

		} while (x != 0);


		alumnos >> contacto.nombre;
		cout << "\n_______________________" << endl;
	}


	alumnos.close();
	system("pause");

}
