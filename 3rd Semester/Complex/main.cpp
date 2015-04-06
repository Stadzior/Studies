#include <iostream>
#include "stdio.h"
#include "complex.h"
using namespace std;

int main(int argc, char** argv) 
{
	complex liczba1;
	complex liczba2;
	liczba1.setRe(2);
	liczba1.setIm(1);
	liczba2.setRe(4);
	liczba2.setIm(3);
	complex liczba3;
	complex liczba4 = liczba1;
	(liczba4 /= liczba2) /= liczba2;
	liczba3 = liczba1 / liczba2;
	complex liczba5;
	liczba5 = liczba1 + liczba2;
	cout << liczba1<<endl<<liczba2<<endl<<liczba5;
	getchar();
	return 0;
}