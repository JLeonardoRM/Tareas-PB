#include <iostream>

using namespace std;
void BusAlumno();
void EdAlumno();
void BorrarAl();
void Cal();
void EdCal();

int main()
{
	int a;
	do
	{
		system("cls");
		cout << "    Menu:\n\n" << endl;
		cout << "    1) Buscar alumno" << endl;
		cout << "    2) Agregar/Editar alumno" << endl;
		cout << "    3) Eliminar Contacto" << endl;
		cout << "    4) Calificaciones" << endl;
		cout << "    5) Salir" << endl;
		cout << "\n\nSelecione el numero de la opcion deseada: ";
		cin >> a;

		switch (a)
		{
		case 1:
			system("cls");
			BusAlumno();
			system("pause");
			break;
		case 2:
			system("cls");
			EdAlumno();
			system("pause");
			break;
		case 3:
			system("cls");
			BorrarAl();
			system("pause");
			break;
		case 4:
			system("cls");
			Cal();
			EdCal();
			system("pause");
			break;

		}
	} while (a != 5);
}

void BusAlumno() {
	system("cls");
	cout << "Aqui se busca el contacto" << endl;

}
void EdAlumno() {
	system("cls");
	cout << "Aqui se edita el contacto" << endl;

}
void BorrarAl() {
	system("cls");
	cout << "Aqui se borra el contacto" << endl;

}
void Cal() {
	cout << "Aqui se almacenan y editan las calificaciones" << endl;

}
void EdCal() {

}