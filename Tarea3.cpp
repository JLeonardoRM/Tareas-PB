#include <iostream>

using namespace std;
//Esto sacara el angulo interno de un poligono regular
void main()
{
	int lados;
	float resultado;
	cout << "Angulo interno de un poligono regular\n\nIngresa el numero de lados de tu poligono regular..." << endl << "Lados: ";
	cin >> lados;

	resultado = ((lados - 2) * 180) / lados;
	system("cls");
	cout << "Angulo interior: " << resultado << "\xF8." << endl;
	system("pause");
}