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
	double cal1;
	double cal2;
	double cal3;
	string calle;
	string numCasa;
	string colonia;

}contacto;


void nuevoAlumno();
void mostrar();
void editar();
void mostrarEliminar();
void eliminar();


int main()
{
	int a;
	do {
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
			mostrarEliminar();
			editar();
	
			break;
		case 4:
			mostrarEliminar();
			eliminar();
			break;

		}
	} while (a!=5);
}

void nuevoAlumno()
{
	int dec;
	do
	{
		int x, i = 0, z, log, auxi, y;

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
			gets_s(contacto.matricula);
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

			} while (z != 0);//Matricula

			
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
			} while (x != 0);//Nombre(s)
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
			} while (x != 0);//Apellido Paterno
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
			} while (x != 0);//Apellido Materno


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
			
			do
			{
				system("cls");
				i = 0; y = 0;
				cout << "Ingrese su Correo Electronico: ";
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
			} while (y != 3);//correo

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


			alumnos <<"  "<< contacto.matricula << "  "<< contacto.nombre << "  " << contacto.apeP << "  " << contacto.apeM << "  " << contacto.numeroC << "  " << contacto.correo << "  " << contacto.calle << " " << contacto.numCasa << " " << contacto.colonia << "." << " " << contacto.cal1 << " " << contacto.cal2 << " " << contacto.cal3 ;
			do
			{
				system("cls");
				z = 0;
				cout << "\n\n desea ingresar mas alumnos? ";
				cout << "\n\n 1=si, 2=no \n" << endl;
				cin >> dec;
				if (dec != 2 && dec != 1)
				{
					z++;
					cout << "Solo puede seleccionar 1 o 2";
					Sleep(1500);
				}

			} while (z != 0);




		}

		alumnos.close();
	} while (dec != 2);
}

void mostrar()
{
	char *cad;
	int i = 0;
	int x = 1, vcolonia = 0, NoApeM = 0;

	system("cls");
	cout << "\n";
	ifstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::in);
	
	cout << "Contactos" << endl;
	cout << "_______________________" << endl;
	
	while (!alumnos.eof())
	{
		if (alumnos.fail())
		{
			system("cls");
			cout << "Primero debes ingresar almenos un alumno\n\n" << endl;
			break;
		}
		x = 1;
		NoApeM = 0, i = 0, vcolonia = 0;
		alumnos >> contacto.matricula;
		cout << "Matricula: " << contacto.matricula << endl;
		alumnos >> contacto.nombre;
		cout << "Nombre: " << contacto.nombre;
		alumnos >> contacto.nombre;
		alumnos >> contacto.apeP;
		alumnos >> contacto.apeM;
		cad = contacto.apeM;

		if (isdigit(cad[0]))
		{
			NoApeM = 1;
		}
		else {
			alumnos >> contacto.numeroC;
		}
		alumnos >> contacto.correo;
		

		cout << " " << contacto.nombre;
		cout << " " << contacto.apeP;
		if (NoApeM == 1)
		{
			cout << endl << "Numero: " << contacto.apeM << endl;

		}
		else
		{
			cout << " " << contacto.apeM << endl;
			cout << "Numero: " << contacto.numeroC << endl;
		}
		cout << "Correo: " << contacto.correo << endl;
		
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
		double promedio;
		alumnos >> contacto.cal1;
		alumnos >> contacto.cal2;
		alumnos >> contacto.cal3;
		cout << "\nCalificaciones: cal 1= " << contacto.cal1 << "  cal 2= " << contacto.cal2 << "  cal 3= " << contacto.cal3;
		promedio = contacto.cal1 + contacto.cal2 + contacto.cal3;
		promedio = promedio / 3;
		cout << "\nPromedio: " << promedio;

		
		cout << "\n_______________________" << endl;
	}
	alumnos.close();
	system("pause");
}

void mostrarEliminar()
{
	char *cad;
	int i = 0;
	int x = 1, vcolonia = 0, NoApeM = 0;

	system("cls");
	cout << "\n";
	ifstream alumnos;
	alumnos.open("alumnos.txt", ios::out | ios::in);

	cout << "Contactos" << endl;
	cout << "_______________________" << endl;

	while (!alumnos.eof())
	{
		if (alumnos.fail())
		{
			system("cls");
			cout << "Primero debes ingresar almenos un alumno\n\n" << endl;
			break;
		}
		x = 1;
		NoApeM = 0, i = 0, vcolonia = 0;
		alumnos >> contacto.matricula;
		cout << "Matricula: " << contacto.matricula << endl;
		alumnos >> contacto.nombre;
		cout << "Nombre: " << contacto.nombre;
		alumnos >> contacto.nombre;
		alumnos >> contacto.apeP;
		alumnos >> contacto.apeM;
		cad = contacto.apeM;

		if (isdigit(cad[0]))
		{
			NoApeM = 1;
		}
		else {
			alumnos >> contacto.numeroC;
		}
		alumnos >> contacto.correo;


		cout << " " << contacto.nombre;
		cout << " " << contacto.apeP;
		if (NoApeM == 1)
		{
			cout << endl << "Numero: " << contacto.apeM << endl;

		}
		else
		{
			cout << " " << contacto.apeM << endl;
			cout << "Numero: " << contacto.numeroC << endl;
		}
		cout << "Correo: " << contacto.correo << endl;

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
		double promedio;
		alumnos >> contacto.cal1;
		alumnos >> contacto.cal2;
		alumnos >> contacto.cal3;
		cout << "\nCalificaciones: cal 1= " << contacto.cal1 << "  cal 2= " << contacto.cal2 << "  cal 3= " << contacto.cal3;
		promedio = contacto.cal1 + contacto.cal2 + contacto.cal3;
		promedio = promedio / 3;
		cout << "\nPromedio: " << promedio;


		cout << "\n_______________________" << endl;
	}
	alumnos.close();
	
}

void eliminar()
{
	
	char BuscarMat[25], AuxBuscarMat[25];
	char *cad;
	int i = 0, z = 0, opcion = 0,y=0;
	int x = 1, vcolonia = 0, NoApeM = 0;
	int text=0;

	ofstream aux;
	ifstream alumnos;
	aux.open("AuxAlumnos.txt", ios::out);
	alumnos.open("alumnos.txt", ios::in);

	cout << "\n Ingrese MATRICULA que desea ELIMINAR: " << endl;
	cin >> BuscarMat;
	system("cls");
	cout << "_______________________" << endl;
	while (!alumnos.eof())
	{
		z = 0,x=1,i=0;
		alumnos >> contacto.matricula;
		while (contacto.matricula[i])
		{

			AuxBuscarMat[i] = contacto.matricula[i];
			i++;
		}
		i = 0;
		while (contacto.matricula[i])
		{

			if (BuscarMat[i] == AuxBuscarMat[i])
			{
				z++;
			}
			i++;
		}
		if(z==7)
		{
			
			text++;
			alumnos >> contacto.nombre;

			alumnos >> contacto.nombre;

			alumnos >> contacto.apeP;

			alumnos >> contacto.apeM;
			cad = contacto.apeM;

			if (isdigit(cad[0]))
			{
				NoApeM = 1;
			}
			else {
				alumnos >> contacto.numeroC;

			}
			alumnos >> contacto.correo;
			
			do
			{
				i = 0;
				alumnos >> contacto.calle;
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

				}
				
			} while (x != 0);
			alumnos >> contacto.cal1;
			alumnos >> contacto.cal2;
			alumnos >> contacto.cal3;
			

			
		}
		else
		{
			if(y!=0)
			{
				aux << "  ";
			}
			aux << contacto.matricula<<"  ";
			alumnos >> contacto.nombre;
			aux << contacto.nombre << "  ";
			alumnos >> contacto.nombre;
			aux << contacto.nombre << "  ";
			alumnos >> contacto.apeP;
			aux << contacto.apeP << "  ";
			alumnos >> contacto.apeM;
			cad = contacto.apeM;

			if (isdigit(cad[0]))
			{
				NoApeM = 1;
				aux << contacto.apeM << "  ";
			}
			else {
				alumnos >> contacto.numeroC;
				aux << contacto.apeM << "  ";
				aux << contacto.numeroC << "  ";
			}
			alumnos >> contacto.correo;
			aux << contacto.correo << "  ";
			do
			{
				alumnos >> contacto.calle;
				aux << contacto.calle << "  ";
				
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

					
				}
				

			} while (x != 0);//Direccion
			alumnos >> contacto.cal1;
			alumnos >> contacto.cal2;
			alumnos >> contacto.cal3;
			aux << contacto.cal1 << "  " << contacto.cal2 << "  " << contacto.cal3 ;
			y++;
		}

	}
	alumnos.close();
	aux.close();
	remove("alumnos.txt");
	rename("AuxAlumnos.txt", "alumnos.txt");
	if (text == 0)
	{
		system("cls");
		cout << "No se encontro alumno con la matricula" << BuscarMat<<"\n\n"<<endl;
		system("pause");
	}
	else 
	{
		system("cls");
		cout << "Eliminado.\n" << endl;
		system("pause");
	}


}

void editar()

{
	double promedio;
	char BuscarMat[25], AuxBuscarMat[25];
	char *cad;
	int i = 0, z = 0, opcion = 0, y = 0;
	int x = 1, vcolonia = 0, NoApeM = 0;
	char auxMat[10];

	ofstream aux;
	ifstream alumnos;
	aux.open("AuxAlumnos.txt", ios::out);
	alumnos.open("alumnos.txt", ios::in);

	cout << "\n Ingrese MATRICULA que desea EDITAR: " << endl;
	cin >> BuscarMat;
	system("cls");
	cout << "_______________________" << endl;
	while (!alumnos.eof())
	{
		z = 0, x = 1;
		alumnos >> contacto.matricula;
		while (contacto.matricula[i])
		{

			AuxBuscarMat[i] = contacto.matricula[i];
			i++;
		}
		i = 0;
		while (contacto.matricula[i])
		{

			auxMat[i] = BuscarMat[i];
			i++;
		}
		i = 0;
		while (contacto.matricula[i])
		{

			if (BuscarMat[i] == AuxBuscarMat[i])
			{
				z++;
			}
			i++;
		}
		if (z == 7)
		{

			alumnos >> contacto.nombre;

			alumnos >> contacto.nombre;

			alumnos >> contacto.apeP;

			alumnos >> contacto.apeM;
			cad = contacto.apeM;

			if (isdigit(cad[0]))
			{
				NoApeM = 1;
			}
			else {
				alumnos >> contacto.numeroC;

			}
			alumnos >> contacto.correo;

			do
			{

				alumnos >> contacto.calle;
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

				}

			} while (x != 0);
			alumnos >> contacto.cal1;
			alumnos >> contacto.cal2;
			alumnos >> contacto.cal3;
			i = 0;
		}
		else
		{
			if (y != 0)
			{
				aux << "  ";
			}
			aux << contacto.matricula << "  ";
			alumnos >> contacto.nombre;
			aux << contacto.nombre << "  ";
			alumnos >> contacto.nombre;
			aux << contacto.nombre << "  ";
			alumnos >> contacto.apeP;
			aux << contacto.apeP << "  ";
			alumnos >> contacto.apeM;
			cad = contacto.apeM;

			if (isdigit(cad[0]))
			{
				NoApeM = 1;
				aux << contacto.apeM << "  ";
			}
			else {
				alumnos >> contacto.numeroC;
				aux << contacto.apeM << "  ";
				aux << contacto.numeroC << "  ";
			}
			alumnos >> contacto.correo;
			aux << contacto.correo << "  ";
			do
			{
				alumnos >> contacto.calle;
				aux << contacto.calle << "  ";

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


				}

			} while (x != 0);//Direccion
			

			
			alumnos >> contacto.cal1;
			alumnos >> contacto.cal2;
			alumnos >> contacto.cal3;
			aux << contacto.cal1 << "  " << contacto.cal2 << "  " << contacto.cal3;
			y++;
		}

	}
	{
	int dec;
	do
	{
		int x, i = 0, z, log, auxi, y;

		string telefono;
		system("cls");

		while (contacto.matricula[i])
		{

			contacto.matricula[i] = auxMat[i];
			i++;
		}
		i = 0;

		cout << "Ingresa nuevos datos del alumno con matricula" << contacto.matricula << endl;


		getline(cin, contacto.nombre);
		do
		{
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
		} while (x != 0);//Nombre(s)
		do
		{
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
		} while (x != 0);//Apellido Paterno
		do
		{
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
		} while (x != 0);//Apellido Materno


		do
		{
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

		do
		{
			system("cls");
			i = 0; y = 0;
			cout << "Ingrese su Correo Electronico: ";
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
		} while (y != 3);//correo

		system("cls");
		cout << "Direccion\n\nCalle: ";
		getline(cin, contacto.calle);
		cout << "\nNumero exterior: ";
		cin >> contacto.numCasa;
		getline(cin, contacto.colonia);
		cout << "\nColonia: ";
		getline(cin, contacto.colonia);

		do
		{
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
		do
		{
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
		do
		{
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


		aux << "  " << contacto.matricula << "  " << contacto.nombre << "  " << contacto.apeP << "  " << contacto.apeM << "  " << contacto.numeroC << "  " << contacto.correo << "  " << contacto.calle << " " << contacto.numCasa << " " << contacto.colonia << "." << " " << contacto.cal1 << " " << contacto.cal2 << " " << contacto.cal3;


		dec = 2;





	} while (dec != 2);
			}//Aqui se edita los datos de la matricula


	alumnos.close();
	aux.close();
	remove("alumnos.txt");
	rename("AuxAlumnos.txt", "alumnos.txt");
	system("cls");
	system("pause");



}