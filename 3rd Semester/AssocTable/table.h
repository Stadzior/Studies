#pragma once
#include <string>
using namespace std;

class table
{
protected:
	typedef struct
	{
		int value;
		string key;
	}TableElement;
	TableElement *vector;
	int sizeOfVector;
	void VectorRealloc(int);
	virtual bool CompareKey(string,string);
public:
	int GetValue(string);
	void SetValue(string,int);
	void AddKey(string, int);
	table();
	virtual ~table();
};

string lowerString(string);

class tableNR : public table
{
private:
	bool CompareKey(string, string);
};