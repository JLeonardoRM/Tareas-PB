#include<iostream>
#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
using namespace std;

struct persona {

	char nombre[25];
	char apellido[25];
	char numeroC[11];
	char correo[50];
	int cali;
}alumno;


void nuevoAlumno();
void mostrar();
void mostrarEl();
void busqueda();
void eliminar();

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
		case 3:
			busqueda();
			break;
		case 4:
			mostrarEl();
			eliminar();
			break;

		}
	} while (a != 5);
}

void mostrar()
{
	int i = 0;
	system("cls");
	cout << "\n";
	ifstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::in);
	cout << "alumnos" << endl;
	cout << "_______________________" << endl;
	alumnos >> alumno.nombre;
	while (!alumnos.eof())
	{
		alumnos >> alumno.apellido;
		alumnos >> alumno.numeroC;
		alumnos >> alumno.correo;
		cout << "Nombre: " << alumno.nombre;
		cout << " " << alumno.apellido << endl;
		cout << "Numero: " << alumno.numeroC << endl;
		cout << "Correo: " << alumno.correo << endl;
		alumnos >> alumno.nombre;
		cout << "_______________________" << endl;
	}
	alumnos.close();
	system("pause");

}

void busqueda()
{
	int i = 0, elije, z = 0, log, x, y;
	char auxNombre[25], auxN[25];
	while (auxNombre[24])
	{
		auxNombre[i] = '\0';
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
	aux.open("alumnos.txt", ios::out);
	alumnos.open("alumnos.txt", ios::in);

	cout << "\nSi no te sabes el nombre revisa la lista de alumnos.\n Ingrese nombre que desea buscar: " << endl;
	cin >> auxNombre;
	alumnos >> alumno.nombre;
	log = strlen(alumno.nombre);
	while (alumno.nombre[i])
	{
		auxN[i] = alumno.nombre[i];
		i++;
	}
	i = 0;
	cout << "_______________________" << endl;

	while (!alumnos.eof())
	{
		alumnos >> alumno.apellido;
		alumnos >> alumno.numeroC;
		alumnos >> alumno.correo;
		while (alumno.nombre[i])
		{

			if (auxNombre[i] == auxN[i])
			{
				z++;
			}
			i++;
		}
		if (z == log)
		{
			do {
				system("cls");
				cout << "Nombre: " << alumno.nombre;
				cout << " " << alumno.apellido << endl;
				cout << "Numero: " << alumno.numeroC << endl;
				cout << "Correo: " << alumno.correo << endl;
				cout << "_______________________" << endl;
				cout << "\n\n¿Desea editar el numero o correo de este alumno?" << endl;
				cout << "  1)si" << endl;
				cout << "  2)no" << endl;
				cin >> elije;
				if (elije == 1) {
					do {
						cout << "\nIngrese Nuevo Numero: ";
						x = 0;
						z = 0;

						cin >> alumno.numeroC;

						while (alumno.numeroC[x])
						{
							if (!isdigit(alumno.numeroC[x]))
							{

								z = 1;
							}
							x++;
						}


						log = strlen(alumno.numeroC);
						if (log < 8 || log > 11)
						{
							cout << "Verifica que tu numero este correcto" << endl;
							cin >> alumno.numeroC;
							z = z + 1;
						}

					} while (z != 0);
					do
					{

						i = 0; y = 0;
						cout << "\nIngrese Nuevo Correo: ";
						cin >> alumno.correo;
						log = strlen(alumno.correo);
						while (alumno.correo[i])
						{
							if ((alumno.correo[i]) == ('@')) {
								y = 1;
							}
							i++;

						}
						if (y != 0)
						{
							i = 0;
							_strrev(alumno.correo);


							while (alumno.correo[i])
							{
								if ((alumno.correo[i]) == ('m'))
								{
									i++;
									if ((alumno.correo[i]) == ('o'))
									{
										i++;
										if ((alumno.correo[i]) == ('c'))
										{
											i++;
											if ((alumno.correo[i]) == ('.'))
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
									cout << "Error, Debe contener '@' y ''.com''\n";
									Sleep(2000);
								}
								i = log;

							}
							_strrev(alumno.correo);
						}
						else {
							cout << "Error, Debe contener '@' y ''.com''\n";
							Sleep(2000);
						}
					} while (y != 3);
				}

			} while (elije != 2);
		}
		i = 0;
		aux << alumno.nombre << " " << alumno.apellido << " " << alumno.numeroC << " " << alumno.correo << endl;
		while (auxN[i])
		{
			auxN[i] = '\0';
			i++;
		}
		i = 0, z = 0;
		alumnos >> alumno.nombre;
		log = strlen(alumno.nombre);
		while (alumno.nombre[i])
		{
			auxN[i] = alumno.nombre[i];
			i++;
		}
		i = 0;


	}

	alumnos.close();
	aux.close();
	remove("alumnos.txt");
	rename("Auxalumnos.txt", "alumnos.txt");
	cout << "alumnos Guardados.\n" << endl;
	system("pause");

}
void mostrarEl()
{
	int i = 0;
	system("cls");
	cout << "\n";
	ifstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::in);
	cout << "alumnos" << endl;
	cout << "_______________________" << endl;
	alumnos >> alumno.nombre;
	while (!alumnos.eof())
	{
		alumnos >> alumno.apellido;
		alumnos >> alumno.numeroC;
		alumnos >> alumno.correo;
		cout << "Nombre: " << alumno.nombre;
		cout << " " << alumno.apellido << endl;
		cout << "Numero: " << alumno.numeroC << endl;
		cout << "Correo: " << alumno.correo << endl;
		alumnos >> alumno.nombre;
		cout << "_______________________" << endl;
	}
	alumnos.close();

}
void eliminar()
{
	int i = 0, elije, z = 0, log, x, y;
	char auxNombre[25], auxN[25];
	while (auxNombre[24])
	{
		auxNombre[i] = '\0';
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
	aux.open("AUXalumnos.txt", ios::out);
	alumnos.open("alumnos.txt", ios::in);

	cout << "\n Ingrese nombre que desea buscar: " << endl;
	cin >> auxNombre;
	alumnos >> alumno.nombre;
	log = strlen(alumno.nombre);
	while (alumno.nombre[i])
	{
		auxN[i] = alumno.nombre[i];
		i++;
	}
	i = 0;
	cout << "_______________________" << endl;

	while (!alumnos.eof())
	{
		alumnos >> alumno.apellido;
		alumnos >> alumno.numeroC;
		alumnos >> alumno.correo;
		while (alumno.nombre[i])
		{

			if (auxNombre[i] == auxN[i])
			{
				z++;
			}
			i++;
		}
		if (z == log)
		{

			system("cls");
			cout << "Nombre: " << alumno.nombre;
			cout << " " << alumno.apellido << endl;
			cout << "Numero: " << alumno.numeroC << endl;
			cout << "Correo: " << alumno.correo << endl;
			cout << "_______________________" << endl;
			cout << "\n\n¿Desea ELIMINAR este alumno?" << endl;
			cout << "  1)si" << endl;
			cout << "  2)no" << endl;
			cin >> elije;



		}
		i = 0;
		if (elije != 1)
		{
			aux << alumno.nombre << " " << alumno.apellido << " " << alumno.numeroC << " " << alumno.correo << endl;
		}

		while (auxN[i])
		{
			auxN[i] = '\0';
			i++;
		}
		i = 0, z = 0;
		alumnos >> alumno.nombre;
		log = strlen(alumno.nombre);
		while (alumno.nombre[i])
		{
			auxN[i] = alumno.nombre[i];
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

}

void nuevoAlumno()
{
	gets_s(alumno.nombre);
	int x = 0, i = 0, z = 0, log = 0, auxi = 0, y = 0;
	int dec = 0, space = 0;
	string telefono;
	system("cls");
	ofstream alumnos;
	ifstream consulta;

	alumnos.open("alumnos.txt", ios::out | ios::app);
	consulta.open("alumnos.txt", ios::in);
	if (alumnos.is_open() && consulta.is_open())
	{
		do {


			do {
				system("cls");
				x = 0, i = 0, auxi = 0, z = 0;
				space = 0;
				if (dec != 0)
				{
					x = 1;
					dec = 0;
				}
				do
				{
					log = 0;
					system("cls");
					cout << "\nIngrese Nombre del alumno: ";
					fflush(stdin);
					gets_s(alumno.nombre);
					log = strlen(alumno.nombre);
					if (!isalpha(alumno.nombre[i]))
					{
						log = 0;
					}
				} while (log == 0);

				while (alumno.nombre[i])
				{

					if (!isalpha(alumno.nombre[i]))
					{
						if (!iswspace(alumno.nombre[i]))
						{

							auxi = i;
							i = log - 1;
							x = 1;
						}
						else
						{
							while (alumno.nombre[i])
							{
								if (!isalpha(alumno.nombre[i]))
								{
									if (!iswspace(alumno.nombre[i]))
									{
										auxi = i;
										i = log;
										x = 1;
									}
									else
									{
										alumno.apellido[z] = alumno.nombre[i];
										z++;
										i++;
										space++;
										if (space > 1)
										{
											auxi = i;
											i = log;
											x = 1;
										}
									}
								}
								else
								{
									alumno.apellido[z] = alumno.nombre[i];
									z++;
									i++;
								}

							}
							i--;
						}
					}
					else {
						alumno.nombre[i] = alumno.nombre[i];
					}

					i++;

				}
				if (z == 0) {
					alumno.nombre[i] = ' ';
					alumno.nombre[i + 1] = '.';
					alumno.nombre[i + 2] = '\0';
					z++;
				}
			} while (x != 0);


			do {
				system("cls");
				cout << "\nIngrese Numero: ";
				x = 0;
				z = 0;

				cin >> alumno.numeroC;

				while (alumno.numeroC[x])
				{
					if (!isdigit(alumno.numeroC[x]))
					{

						z = 1;
					}
					else {
						cout << "Solo numeros :)" << endl;
					}
					x++;
				}
				system("cls");

				log = strlen(alumno.numeroC);
				if (log < 8 || log > 11)
				{
					cout << "error longitud" << endl;
					z = z + 1;
					Sleep(2000);
				}

			} while (z != 0);//validacion numero

			do
			{
				system("cls");
				i = 0; y = 0;
				cout << "\nIngrese Correo: ";
				cin >> alumno.correo;
				log = strlen(alumno.correo);
				while (alumno.correo[i])
				{
					if ((alumno.correo[i]) == ('@')) {
						y = 1;
					}
					i++;

				}
				if (y != 0)
				{
					i = 0;
					_strrev(alumno.correo);


					while (alumno.correo[i])
					{
						if ((alumno.correo[i]) == ('m'))
						{
							i++;
							if ((alumno.correo[i]) == ('o'))
							{
								i++;
								if ((alumno.correo[i]) == ('c'))
								{
									i++;
									if ((alumno.correo[i]) == ('.'))
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
							cout << "Error, no olvides usar el '@' y el ''.com''";
							Sleep(2000);
						}
						i = log;

					}
					_strrev(alumno.correo);
				}
				else {
					cout << "Error, Debe contener '@' y ''.com''";
					Sleep(2000);
				}
			} while (y != 3);
			alumnos << alumno.nombre << " " << alumno.numeroC << " " << alumno.correo << endl;
			cout << "\n\n desea ingresar otro alumno? ";
			cout << "\n\n 1=si, 2=no \n" << endl;

			cin >> dec;
		} while (dec == 1);
	}
	else
	{
		cout << "Error al abrir el archivo";
		system("pause");

	}
	alumnos.close();

}


