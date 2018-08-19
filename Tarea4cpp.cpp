#include <iostream>
#include <math.h>

using namespace std;
float anguloS, radio;
double x, y;

void main()
{
	cout << "  Ingresa el radio y el angulo sexagesimal para encontrar sus coordenadas.....\n\n" << endl;
	cout << "  Radio: ";
	cin >> radio;
	cout << "  Angulo sesagesimal: ";
	cin >> anguloS;

	x = radio * cos(anguloS*3.14159 / 180.0);
	y = radio * (sin(anguloS*2.0*3.14159 / 360.0));
	system("cls");
	cout << "  __________________________" << endl;
	cout << "  Coordenadas (x,y)...\n\n";
	cout << "  Coordenadas: (" << x << "," << y << ")" << endl;
	cout << "  __________________________\n\n";

	system("pause");

}