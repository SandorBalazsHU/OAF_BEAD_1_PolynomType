#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "PolynomConsole.h"
#include "Polynom.h"

//Az üres polinomot nullpolinomként értelmezzük
PolynomConsole::PolynomConsole() : Polynom(){}
//Konstruktor 2 - Egy tömb alapján hoz létre egy új polinomot
PolynomConsole::PolynomConsole(double* t, int n) : Polynom(t,n){}
//Konstruktor 3 - Egy vektor alapján hoz létre egy új polinomot
PolynomConsole::PolynomConsole(std::vector<double>& v) : Polynom(v){}
//Konstruktor 4 - konvertáló
PolynomConsole::PolynomConsole(const Polynom& p) : Polynom(p){}
//A másoló konstruktor
PolynomConsole::PolynomConsole(const PolynomConsole& p) : Polynom(p){}

void PolynomConsole::read()
{
	std::string newPolynomInString;
	std::cin.clear();
	std::getline(std::cin,newPolynomInString);

	std::stringstream in(newPolynomInString);
	std::vector<double> polynom;
	int temp;
	while(in >> temp)
	{
	  polynom.push_back(temp);
	}
	_n = polynom.size();
	_p = new double[_n];
	for(int i=0; i<_n; i++)
	{
		_p[i] = polynom[_n-i-1];
	}
}
bool isDouble(std::string& str)
{
    char* endptr = 0;
    strtod(str.c_str(), &endptr);
    if(*endptr != '\0' || endptr == str.c_str()) return false;
    return true;
}
Polynom PolynomConsole::readExpression()
{
	std::string newPolynomInString;
	std::cin.clear();
	std::getline(std::cin,newPolynomInString);
	
	std::vector<std::string> expression = PolynomConsole::tokenizer(newPolynomInString, ' ');
	expression.push_back("=");
	size_t flag = 0 ;
	std::vector<PolynomConsole> polynoms;
	std::vector<std::string> operations;
	std::vector<double> elements;
	for (size_t i = 0; i<expression.size(); ++i)
	{
		if(isDouble(expression[i]))
		{
			elements.push_back(strtod(expression[i].c_str(),NULL));
		}
		else
		{
			operations.push_back(expression[i]);
			polynoms.push_back(PolynomConsole(elements));
			elements.clear();
		}
	}
	std::cout << "(";
	for (size_t i = 0; i<polynoms.size()-1; ++i)
	{
		polynoms[i].write();
		std::cout << ")  " << operations[i] << "  (";
	}
	polynoms[polynoms.size()-1].write();
	std::cout << ")  " << operations[polynoms.size()-1] << "  ";
	
	PolynomConsole tmp = polynoms[0];
	for (size_t i = 0; i<polynoms.size()-1; ++i)
	{
		if(operations[i] == "+") 
		{
			tmp = tmp + polynoms[i+1];
		}
		if(operations[i] == "*") 
		{
			tmp = tmp * polynoms[i+1];
		}
	}
	tmp.write();

	return tmp;
}
std::vector<std::string> PolynomConsole::tokenizer(std::string &text, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream stream(text);
    std::string token;
    while(std::getline(stream,token,delimiter))
    {
		if(token != "") tokens.push_back(token);
    }
	return tokens;
}
void PolynomConsole::write() const
{
	//std::cout.precision(3);
	for(int i=_n-1; i>0; i--)
	{
		if(_p[i] != 0)
		{
			if(_p[i] != 1) std::cout << _p[i];
			if(i != 1) std::cout << "x^" << i;
			else std::cout << "x"; 
			bool l = false;
			for(int j=i-1; j>=0; j--) if(_p[j] != 0) l =  true;
			if(l) std::cout << " + ";
		}
	}
	if(_p[0] != 0) std::cout << _p[0];
}
