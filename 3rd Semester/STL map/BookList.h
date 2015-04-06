#pragma once
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef enum categories
{
	Criminal,
	Romance,
	Adventure,
}categoryList;

typedef struct
{
	string author;
	string category;
	int bookSize;
	bool status;
}_bookInfo;

class BookList
{
private:
	map < string, _bookInfo> Book;

public:
	void AddBook(string,string,categoryList,int,bool);
	string BookInfo(string);
	void DeleteBook(string);
	void ClearBookList();
	BookList();
	virtual ~BookList();
};