#include <iostream>
#include <ctime>
#include "matrix.h"
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	matrix macierz1;
	macierz1.RandomInitialize();
	cout << macierz1 << endl;
	getchar();
	matrix macierz2;
	macierz2.RandomInitialize();
	cout << macierz2 << endl;
	getchar();
	macierz2 = macierz1;
	cout << macierz2 << endl;
	getchar();
	/*matrix macierz4;
	macierz4.RandomInitialize(5,5);
	cout <<macierz4<<endl;
	getchar();
	matrix macierz5 = macierz4;
	cout << macierz5<<endl;
	getchar();
	matrix macierz6 = macierz5 - macierz1;
	cout << macierz6 << endl;
	if (macierz4 == macierz5)
	{
		cout << "prawda\n";
	}
	getchar();
	matrix macierzX,macierzY;
	macierzX.RandomInitialize(4,4);
	cout<< macierzX << endl;
	getchar();
	macierzY.RandomInitialize(4,2);
	cout << macierzY << endl;
	getchar();
	matrix macierzZ = macierzX*macierzY;
	cout << macierzZ;
	getchar(); */
	/*matrix macierzA;
	macierzA.RandomInitialize(1, 3);
	cout << macierzA << endl;
	getchar();
	matrix macierzB;
	macierzB.RandomInitialize(4, 2);
	cout << macierzB << endl;
	getchar();
	macierzA *=macierzB;
	cout << macierzA<< endl;
	getchar();*/
	/*matrix macierzXY;
	macierzXY.RandomInitialize(4, 4);
	cout << macierzXY<<endl<<endl<<macierzXY(2, 2)<<endl;
	macierzXY(2, 2, -100.001);
	cout <<endl<< macierzXY(2, 2) << endl<<endl<<macierzXY;
	getchar();*/
	matrix macierzAlfa;
	macierzAlfa.InitializeFromFile(3,3,"input.txt");
	cout <<endl<<macierzAlfa;
	getchar();
	return 0;
}