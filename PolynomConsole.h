#ifndef POLYNOMCONSOLE_H_INCLUDED
#define POLYNOMCONSOLE_H_INCLUDED
#include <string>
#include <vector>
#include "Polynom.h"
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

//Polynom típus helyett PolynomConsole használható
class PolynomConsole: public Polynom
{
    public:
//Konstruktorok
	//Az üres polinomot nullpolinomként értelmezzük
	PolynomConsole();
	//Konstruktor 2 - Egy tömb alapján hoz létre egy új polinomot
	PolynomConsole(double*, int);
	//Konstruktor 3 - Egy vektor alapján hoz létre egy új polinomot
	PolynomConsole(std::vector<double>&);
	//Konstruktor 4 - PolynomConsole készíése Polynomból
	PolynomConsole(const Polynom&);
	//A másoló konstruktor
	PolynomConsole(const PolynomConsole&);
//Műveletek
	//Egy polinomot ír ki a konzolra
	void write() const;
	//Beolvas egy polinomot a konzolról
	void read();
	
	static Polynom readExpression();
//Statikus segédmetódusok
	//Eldönti egy szövegről, hagy valós típusúvá konverálható-e.
	static bool isDouble(std::string&);
	//Egy szöveget részeire tördel egy elválasztó karakter szerint
	static std::vector<std::string> tokenizer(std::string&, char);
};
#endif