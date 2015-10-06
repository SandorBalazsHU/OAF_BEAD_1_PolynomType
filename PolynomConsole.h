#ifndef POLYNOM_H
#define POLYNOM_H

class PolynomConsole : public Polynom
{
    private:

    public:
		Polynom();
		Polynom(int*);
};

Polynom::Polynom()
{
	std::cout << "Hello world!" << std::endl;
}
#endif