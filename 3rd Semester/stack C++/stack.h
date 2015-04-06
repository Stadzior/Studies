#ifndef _STACK_H_
#define _STACK_H_

class stack
{
public:
	int pop();
	void push(int input);
	void clear();
	stack();
	stack(stack &stos);
	stack operator=(const stack&);
	virtual ~stack();
	int getSize();
private:
	int Size;
	int *content;
};

#endif
