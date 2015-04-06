#include <iostream>
#include "stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	stack stos;
	int i;
	for (i = 0; i < 5; i++)
	{
		stos.push(i);
	}
	stack stos2=stos;
	stack stos3;
	stos3 = stos;
	cout<<"------------------\n";
	for (i = 0; i < 6;i++)
	{
		try
		{
			cout << stos.pop() << endl;
		}
		catch (std::exception &) //// Nale¿y ³apaæ referencje
		{
			cout << "Stos pusty\n";
		}
	}
	
	return 0;
}
