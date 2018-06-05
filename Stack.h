//Stack implementation using Array
#include "windows.h"
#include <iostream>
class StackArr
{
	int tos;
	int MAX[100];
public:
	StackArr();
	~StackArr();
	
	int push(int data);
	int pop();
	bool isOverflow();
	bool isEmpty();
	bool printData();
	bool Move(StackArr*, StackArr*);
};


//Default constructor to Stack, initializing the array and  tos
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

//insert element at the top of stack
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

//remove element from top of stack
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

//check if stack is empty
bool StackArr::isEmpty()
{
	if(-1 == tos)
		return true;
	else 
		return false;
}

//check if stack is full
bool StackArr::isOverflow()
{
	if(sizeof(MAX) == tos)
		return true;
	else
		return false;
}

bool StackArr::printData()
{
	for(int i=0;i<=this->tos;i++)
	{
		printf("%d ",this->MAX[i]);
	}
	return true;
}

bool StackArr::Move(StackArr* first, StackArr* next)
{
	int data = this->MAX[this->tos];
	if(first->tos == -1 || first->MAX[first->tos] < data)
	{
		first->tos++;
		first->MAX[first->tos] = data;
		this->MAX[this->tos] = 0;
		this->tos--;
		return true;
	}

	if(this->tos == first->tos)
	{
		if(next->tos == -1 || next->MAX[next->tos] < data)
		{
			next->tos++;
			next->MAX[first->tos] = data;
			this->MAX[this->tos] = 0;
			this->tos--;
		}
	}

	if(first->tos == next->tos)
	{
		if(this->tos == -1 || first->MAX[first->tos] < data)
		{
			this->tos++;
			this->MAX[first->tos] = data;
			next->MAX[next->tos] = 0;
			next->tos--;
		}
	}
	return true;
	//return false;
}

//working code
//void runner
//{
//    towers(num, 'A', 'C', 'B');
//    return 0;
//}
//void towers(int num, char frompeg, char topeg, char auxpeg)
//{
//    if (num == 1)
//    {
//        printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
//        return;
//    }
//    towers(num - 1, frompeg, auxpeg, topeg);
//    printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
//    towers(num - 1, auxpeg, topeg, frompeg);
//}



