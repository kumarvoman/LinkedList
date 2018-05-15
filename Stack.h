//Stack implementation using Array
#include "windows.h"
#include <iostream>
class StackArr
{
public:
	StackArr();
	~StackArr();
	int tos;
	int MAX[100];
	int push(int data);
	int pop();
	bool isOverflow();
	bool isEmpty();
};

StackArr::StackArr()
{
	tos = -1;
	memset(MAX,-1, sizeof(MAX));
}

StackArr::~StackArr()
{
	tos = -1;
	memset(MAX, -1, sizeof(MAX));
}

int StackArr::push(int data)
{
	if(tos == sizeof(MAX))
		return -1;
	else
	{
		tos++;
		MAX[tos] = data;
		return data;
	}
}

int StackArr::pop()
{
	if(-1 == tos)
		return -1;
	else
	{
		int temp = MAX[tos];
		MAX[tos] =-1;
		tos--;
	}
}

bool StackArr::isEmpty()
{
	if(-1 == tos)
		return true;
	else 
		return false;
}

bool StackArr::isOverflow()
{
	if(sizeof(MAX) == tos)
		return true;
	else
		return false;
}

