#include "stack.h"
#include <iostream>
using namespace std;
stack::stack()
{
	cout << "Utworzono obiekt\n";
	this->Size = 0;
	this->content= new int[this->Size];
}
stack::stack(stack &stack)
{
	this->Size = stack.Size;
	this->content = new int[this->Size];
	for (int i = 0; i < (this->Size); i++)                 
	{
		this->content[i] = stack.content[i];
	}
}

stack stack::operator=(const stack &stack)
{
	if (this == &stack)
	{
		return *this;
	}
	else
	{
		this->Size = stack.Size;
		delete[]this->content;
		this->content = new int[this->Size];
		for (int i = 0; i < (this->Size); i++)
		{
			this->content[i] = stack.content[i];
		}
	}
	return *this;
}

stack::~stack()
{
	delete[]content;
}

void stack::clear()
{
	this->Size = 0;
	delete []content;
	this->content=new int[this->Size];
}

void stack::push(int input)
{
	int temp[this->Size],i;
	for(i=0;i<this->Size;i++)
	{
		temp[i]=this->content[i];
	}
	delete []content;
	this->Size=(this->Size)+1;
	this->content=new int[this->Size];
	for(i=0;i<(this->Size)-1;i++)
	{
		this->content[i]=temp[i];
	}
	this->content[Size-1]=input;
}

int stack::pop()
{
	if (this->Size==0)
	{
		throw std::exception();
	}
	else
	{
		this->Size=(this->Size)-1;
		return this->content[Size];
		int temp[this->Size],i;
		for(i=0;i<this->Size;i++)
		{
			temp[i]=this->content[i];
		}
		delete []content;
		this->content=new int[this->Size];
		for(i=0;i<this->Size;i++)
		{
			this->content[i]=temp[i];
		}
	}
}
