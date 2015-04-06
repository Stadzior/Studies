#pragma once
#include "table.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void table::VectorRealloc(int NewSize)
{
	TableElement *temp;
	int i;
	temp = new TableElement[NewSize];
	if (NewSize < sizeOfVector)
	{
		sizeOfVector = NewSize;
	}
	for (i = 0; i < this->sizeOfVector; i++)
	{
		temp[i] = this->vector[i];
	}
	delete[]this->vector;
	this->vector = temp;
	sizeOfVector = NewSize;
}

bool table::CompareKey(string key1, string key2)
{
	if (key1 == key2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int table::GetValue(string key)
{
	int i=0;
	bool keyExists = false;
	do
	{
		if (CompareKey(vector[i].key,key))
		{
			keyExists = true;
			break;
		}
		i++;
	} while (i < sizeOfVector);
	try{
		if (keyExists == false)
		{
			throw(exception());
		}
		else
		{
			return vector[i].value;
		}
	}
	catch (exception)
	{
		cout << "Nie ma takiego klucza.";
		return -1;
	}
}

void table::SetValue(string key,int value)
{
	int i = 0;
	bool keyExists = false;
	do
	{
		if (CompareKey(vector[i].key, key))
		{
			keyExists = true;
			vector[i].value = value;
			break;
		}
		i++;
	} while (i < sizeOfVector);
	try{
		if (keyExists == false)
		{
			throw(exception());
		}
	} catch (exception)
	{
		cout << "Nie ma takiego klucza.";
	}
}

void table::AddKey(string key, int value)
{
	int OldSize = sizeOfVector;
	VectorRealloc(sizeOfVector + 1);
	vector[OldSize].key = key;
	vector[OldSize].value = value;
}

table::table()
{
	this->vector = new TableElement[0];
	this->sizeOfVector = 0;
}

table::~table()
{
	delete[]this->vector;
}

string lowerString(string input)
{
	transform(input.begin(), input.end(), input.begin(), tolower);
	return input;
}

bool tableNR::CompareKey(string key1, string key2)
{
	string temp1=lowerString(key1);
	string temp2=lowerString(key2);
	if (temp1 == temp2)
	{
		return true;
	}
	else
	{
		return false;
	}
}