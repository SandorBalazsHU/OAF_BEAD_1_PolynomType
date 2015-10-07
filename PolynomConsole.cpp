#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <vector>
#include "PolynomConsole.h"

void PolynomConsole::read()
{
	//Képernyőbeállítások
	setlocale(LC_ALL, "");
	system("cls");
	system("color 1f");
	std::cout << "Új polinom létrehozáságoz szóközzel elválasztva add meg az együtthatókat:" << std::endl;
	string newPolynomInString;
	cin >> newPolynomInString;

	std::stringstream in(s);
	std::vector<double> polynom;
	int temp;
	while(in >> temp)
	{
	  polynom.push_back(temp);
	}
	this = Polynom(&polynom[0],vector.size())
}
void PolynomConsole::write()
{
}