#include <iostream>
#include "BookList.h"
using namespace std;

int main()
{
	BookList BibliotekaP£;
	BibliotekaP£.AddBook("Pan Tadeusz", "Adam Mickiewicz", Romance,500,true);
	cout << BibliotekaP£.BookInfo("Pan Tadeusz");
	getchar();
	BibliotekaP£.DeleteBook("Pan Tadeusz");
	BibliotekaP£.AddBook("Pan Tadeusz", "Adam Mickiewicz", Romance, 500, false);
	cout << BibliotekaP£.BookInfo("Pan Tadeusz");
	getchar();
	return 0;
}