#include "PolynomConsole.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "PolynomConsole.h"
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

int main()
{
	//Képernyőbeállítások
	SetConsoleOutputCP(65001);
	system("color 1f");
	std::cout << "Agy meg egy kifejezést valós eggyütthatós polinomok között:\n" <<
	"(Szóközzel elválasztva add meg az együtthatókat fokszám szerint csökenő rendben)" <<
	"\nÉrtelmezett kommutatív műveletek:\n\tPOLINOM+POLINOM\n\tPOLINOM*POLINOM\n\tPOLINOM+VALÓS\n\tPOLINOM*VALÓS" <<
	std::endl;
	PolynomConsole::readExpression();
	
	
	
	
	
	
	
	/*
	PolynomConsole k;
	k.read();
	const PolynomConsole a(k);
	PolynomConsole b;
	b.read();
	a.write();
	std:: cout << "    *    ";
	b.write();
	std:: cout << "    =    ";
	PolynomConsole c = a * b;
	c.write();
	
	int aa;
	std::cin>>aa;*/
    return 0;
}
