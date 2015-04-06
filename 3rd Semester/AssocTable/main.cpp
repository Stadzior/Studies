#include "table.h"
#include <iostream>

using namespace std;

int  main(int argc, char* argv[])
{
	table Tab1;
	Tab1.AddKey("Zosia", 15);
	cout <<endl<< Tab1.GetValue("Zosia");
	getchar();
	tableNR tab2;
	tab2.AddKey("AsiA", 12);
	cout << tab2.GetValue("asia");
	getchar();
	tab2.SetValue("aSiA", 21);
	cout << tab2.GetValue("AsIa");
	getchar();
	return 0;
}