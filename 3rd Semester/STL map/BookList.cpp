#pragma once
#include "BookList.h"

using namespace std;

void BookList::AddBook(string Key, string Author, categoryList Category, int BookSize, bool Status)
{
	_bookInfo Infoz;
	Infoz.author = Author;
	string tmpCategory;
	switch (Category)
	{
		case Criminal:
		{
			tmpCategory = "Criminal";
			break;
		}

		case Romance:
		{
			tmpCategory = "Romance";
			break;
		}

		case Adventure:
		{
			tmpCategory = "Adventure";
			break;
		}
		default:
		{
			tmpCategory = "???";
			break;
		}
	}
	Infoz.category = tmpCategory;
	Infoz.bookSize = BookSize;
	Infoz.status = Status;
	Book.insert(pair<string,_bookInfo>(Key,Infoz) );
}

string BookList::BookInfo(string key)
{
	string displayString;
	displayString.append("\nAuthor: ");
	displayString.append(Book[key].author);
	displayString.append("\nCategory: ");
	displayString.append(Book[key].category);
	displayString.append("\nSize of Book: ");
	string tmpBookSize = to_string(Book[key].bookSize);
	displayString.append(tmpBookSize);
	displayString.append("\nIs it available?: ");
	if (Book[key].status)
	{
		displayString.append("Yes");
	}
	else 
	{
		displayString.append("No");
	}
	return displayString;
}

void BookList::DeleteBook(string key)
{
	Book.erase(key);
}

void BookList::ClearBookList()
{
	Book.clear();
}

BookList::BookList()
{
}

BookList::~BookList()
{
}