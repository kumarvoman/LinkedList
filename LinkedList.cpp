#include "stdafx.h"
#include <stdlib.h>r
#include <iostream>
#include "LinkedList.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	node* head = NULL;
	LinkedList s1;
	

	//insert the values at the beginning of list
	s1.InsertBegin(&head, 1);
	s1.InsertNodeAtEnd(head, 2);
	s1.InsertNodeAtEnd(head, 3);
	s1.InsertNodeAtEnd(head, 4);
	s1.InsertNodeAtEnd(head, 5);
	s1.InsertNodeAtEnd(head, 6);
	s1.InsertNodeAtEnd(head, 7);
	s1.InsertNodeAtEnd(head, 8);
	s1.InsertNodeAtEnd(head, 9);
	s1.InsertNodeAtEnd(head, 10);
	s1.InsertNodeAtEnd(head, 10);

	s1.printList(head);

	LinkedList s2 = s1;

	//s1.SwapDataOnly(head, 2,8); //not working as of now

	//head->next->next->next->next = head;// creating the loop for testing
	s1.DetectLoop(head);
	s1.printList(head);

	cout<<"\nprogram terminated.";
	getchar();
	return 0;
}


