#ifndef POLYNOM_H_INCLUDED
#define POLYNOM_H_INCLUDED
#include<vector>
//Objektum elvű alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balézs - AZA6NL

//A kódban a polinomot a valós együtthatóik sorozatával reprezentáljuk. (0-együthatóval együtt)
class Polynom
{
    protected:
		//A polinomot reprezentáló dinamikus helyfoglalású tömb első elemére mutató pointer
		double* _p;
		//A polinom elemszáma
		int _n;
		
    public:
	//Konstruktorok
		//Az üres polinomot nullpolinomként értelmezzük
		Polynom();
		//Konstruktor 2 - Egy tömb alapján hoz létre egy új polinomot
		Polynom(double*, int);
		//Konstruktor 3 - Egy vektor alapján hoz létre egy új polinomot
		Polynom(std::vector<double>&);
		//A másoló konstruktor
		Polynom(const Polynom&);
		
	//Műveletek
		//Az értékadó operátor
		Polynom& operator= (const Polynom&);
		
	//Kommutatív műveletek polinom és polinom között
		//Két polinom összeadása (Kommutatív)
		Polynom operator+(const Polynom&) const;
		//Két polinom szorzata (Kommutatív)
		Polynom operator*(const Polynom&) const;
		
	//Kommutatív műveletek polinom és egy konstans között
		//Polinom szorzata konstansal (nem Kommutatív)
		Polynom operator*(const double) const;
		//Polinom szorzata konstansal (A kommutativitás megolsása)
		friend Polynom operator*(const double, const Polynom&);
		//Polinom összeadása konstansal (nem Kommutatív)
		Polynom operator+(const double) const;
		//Polinom összeadása konstansal (A kommutativitás megolsása)
		friend Polynom operator+(const double , const Polynom&);
	
	//Destruktor
		~Polynom();
};
#endif