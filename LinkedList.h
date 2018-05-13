/**************************************************************
WAP to Check if there is an intersecting node in 2 linked lists
***************************************************************/
//Tasks :
/**************************************************************
Create a Link list,								Done
Insert a node at start,							Done
Insert a node in between after a fix data value,Done
Insert a node at the end,						Done
----------------------------------------------------
Insert a node at a fix index,					Done
----------------------------------------------------
Print all the node values in the list,			Done
Delete a node from start,						Done
Delete a node from middle,						Done
Delete a node from end,							Done
Delete a Link list,								Done
----------------------------------------------------
Delete a node from the given position(index)	Done
----------------------------------------------------
Searching particular element in the list,		Done
Find length of the linked list(Iterative),		Done
Find length of the linked list(Recursive),		Done
Find Nth node in a Linked List from start,		Done
Find Nth node in a Linked List from end,		Done
Swap nodes without swapping data,				
Sorting the Link list in given order,			
Removing duplicate entry from the list			
Detect and Remove Loop from the list			

**************************************************************/

#pragma once
#include "DataStructure.h"
using namespace std;
class LinkedList
{
	private:
		//node *Head;
		int length;
		node *Base;
	public:
		
		//LinkedList( node*);
		LinkedList(void);
		LinkedList(const LinkedList& obj);
		virtual ~LinkedList(void);

	protected:
		int DeleteFromStart(node** head);
		int DeleteFromEnd(node* head);
		int DeleteMiddleNode(node* head, int index); // = DeleteFromAnyPosition(node* head,int index);
		int DeleteList(node* head);

	public:

		node* createNode(int data);
		//Insertion
		int InsertBegin(node** next,int data);
		int InsertNodeInBetween(node* head,int value ,int data);
		int InsertNodeInBetweenAtFixIndex(node* head,int index ,int data);
		int InsertNodeAtEnd(node * head, int data);

		//Get length

		int GetListSizeIterative(node* head);
		int GetListSizeRecursive(node* head);

		//Searching for an element
		node* GetNthNodeFromStart(node* head,int index);
		node* GetNthNodeFromEnd(node* head, int index);
		int SearchElement(node* head, int element);
		int CountOccurance(node* head, int element);

		//swapping the data
		int SwapDataOnly(node* head, int position1, int position2);
		int SwapNode(node* head, int position1, int position2);

		//check if the list has a loop
		int DetectLoop(node* head);

		//delete the loop from the list
		int deleteLoop(node* head);

		//printing the list
		void printList(node *node);
};

//LinkedList::LinkedList(node* root)
//{
//	//memcpy_s(Head, sizeof(node),root, sizeof(root));
//	Head->data = root->data;
//	Head->next = root->next;
//}


LinkedList::LinkedList()
{
	length = 1; //head
}

LinkedList::LinkedList(const LinkedList& obj)
{
	this->Base = obj.Base;
}

LinkedList::~LinkedList()
{
	Base = NULL;
}

//Creates a node
node* LinkedList::createNode(int val)
{
	node* temp = (node*)malloc(sizeof(node));
	if(temp != NULL)
	{
		temp->data = val;
		temp->next = NULL;
	}
	else
	{
		cout<<"Error while creating a node.";
		return NULL;
	}
	return temp;
}

//Insert a new node at the start (head position)
int LinkedList::InsertBegin(node** head,int data)
{
	node* new_node = createNode(data);
	if(new_node != NULL)
	{
		new_node->data = data;
		new_node->next = (*head);
		*head = new_node;
	}
	else
	{
		return 1;
	}
	return 0;
}

//Insert a new node after some position (after fix data value)
int LinkedList::InsertNodeInBetween(node* head,int value ,int data)
{
	node* new_node = createNode(data);
	while (head != NULL)
	{
		if(head->data == value)
		{
			cout<<"Inserting value : "<<data<<" after %d "<< head->data;
			new_node->data = data;
			new_node->next = head->next;
			head->next = new_node;
			break;
		}
		else
		{
			head = head->next;
		}
	}
	return 0;
}

//Insert a node in between after a fix index
int LinkedList::InsertNodeInBetweenAtFixIndex(node *head, int index, int data)
{
	node* new_node = createNode(data);
	int linkCount = 0;
	if(index == 0)
	{
		new_node->data = data;
		new_node->next = head->next;
		head->next = new_node;
	}
	else
	{
		while(linkCount != index)
		{
			if(head->next == NULL && index != linkCount)
			{
				cout<<"There is only %d links present in the list."<< linkCount;
				break;
			}

			head = head->next;
			linkCount++;
		}
	}
	while (head != NULL)
	{
		if(linkCount == index)
		{
			cout<<"Inserting value : "<<data<<" after %d "<< head->data;
			new_node->data = data;
			new_node->next = head->next;
			head->next = new_node;
			break;
		}
		else
		{
			head = head->next;
		}
	}
	return 0;
}

//Insert a node at end
int LinkedList::InsertNodeAtEnd(node * head, int data)
{
	node* new_node = createNode(data);
	while (head != NULL)
	{
		if(head->next == NULL)
		{
			//printf("Inserting value : %d at last\n",data);
			new_node->data = data;
			new_node->next = head->next;
			head->next = new_node;
			break;
		}
		else
		{
			head = head->next;
		}
	}
	return 0;
}

//Delete first node in the list
int LinkedList::DeleteFromStart(node** head)
{
	if(head == NULL)
	{
		cout<<"List is empty.\n";
		return 1;
	}
	else
	{
		cout<<"Deleting first node from the list.\n";
		node* temp = *head;
		*head = temp->next;

		temp->data = 0;
		free(temp);
	}
	return 0;
}

//Delete last node from the list
int LinkedList::DeleteFromEnd(node* head)
{
	if(head == NULL)
	{
		cout<<"List is empty.\n";
		return 1;
	}
	else
	{
		while(head->next != NULL)
		{
			node *temp = head;
			head = head->next;
			if(head->next == NULL)
			{
				cout<<"Deleting last node from the list : "<< head->data;
				temp->next = NULL;
				head = temp;
				break;
			}
			free(temp);
		}
	}
	return 0;
}

//Delete a node from middle in the list
int LinkedList::DeleteMiddleNode(node* head, int index)
{
	int count = 0;
	if(head == NULL)
	{
		cout<<"List is empty.\n";
		return 0;
	}
	else
	{
		while(head->next != NULL)
		{
			count++;
			if(index-1 == count)
			{
				cout<<"Deleting from location : "<< index;
				if(head->next->next != NULL)
				{
					head->next = head->next->next;
					break;
				}
				else
				{
					if(head->next->next == NULL)
					{
						head->next = NULL;
					}
				}
			}
			else
			{
				head = head->next;
			}
		}
	}
	return 0;
}

//Delete the whole link list
int LinkedList::DeleteList(node* head)
{
	node *current = head;
	node *next;
	while(current->next != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	memset(head,0, sizeof(head));
	return 0;
}

//Search any element in the list
int LinkedList::SearchElement(node *head, int element)
{
	int volatile count =0; //This will make the compiler understand that this value can be changed from outside.
	while(head->next != NULL)
	{
		count++;
		if(head->data == element)
		{
			break;
		}
		else
			head = head->next;
	}
	if(head->next != NULL)
		cout<<"Element "<<element<<" found at index "<< count;
	else
	{
		cout<<"Element "<<element<<" is not present in the given list.\n";
		return 1;
	}
	return 0;
}

//Get the size of list by iterative way
int LinkedList::GetListSizeIterative(node* head)
{
	length = 1;
	while(head->next != NULL)
	{
		length++;
		head = head->next;
	}
	cout<<"length of the link list is "<<length;
	return length;
}

//Get the size of list by recursive way
int LinkedList::GetListSizeRecursive(node* head)
{
	if(head->next != NULL)
	{
		length++;
		head = head->next;
		if(head->next != NULL)
		{
			GetListSizeRecursive(head);
		}
	}
	if(head->next == NULL)
		cout<<"length of the link list is "<<length;
	return 0;
}
//Get the Nth node from start
node* LinkedList::GetNthNodeFromStart(node* head, int index)
{
	int count =0;
	node* result = head;
	while(result != NULL)
	{
		count++;
		if(count == index)
			return result;
		else
			result = result->next;
	}
}

//Get the Nth node from end
node* LinkedList::GetNthNodeFromEnd(node* head, int index)
{
	int count =0;
	int length = GetListSizeIterative(head);
	if(length < index)
		return NULL;
	else
	{
		index = length - index;
		node* result = head;
		while(result != NULL)
		{
			if(count == index)
				return result;
			else
				result = result->next;
			count++;
		}
	}
}


//Count occurance of particular element and also specify the position
int LinkedList::CountOccurance(node* head, int data)
{
	int count =0, iterator =0;
	int *repLoc = new int[length];
	while(head->next != NULL)
	{
		iterator++;
		if(head->data == data)
		{
			count++;
			repLoc[count] = iterator;
		}
		head = head->next;
	}
	if(count == 0)
		printf("\nvalue %d is not available in the given list.",data);
	else
	{
		printf("\nvalue %d is available %d times in given list.\n", data, count);
		for(int i =1;i<=count;i++)
		{
			if(repLoc[i] != 0)
				printf("%dth occurance at position %d\n",i, repLoc[i]);
			else
				break;
		}
	}
	return count;
}


//Swap data only based on index
int LinkedList::SwapDataOnly(node* head, int loc1, int loc2)
{
	int temp1 =0, temp2 =0, count =0;
	while(head != NULL)
	{
		count++;
		if(count == loc1)
		{
			temp1 = head->data;
		}
		if(count == loc2)
		{
			temp2 = head->data;
		}

		if (0 != temp1 && 0 != temp2)
		{
			if(head->data == temp2)
				head->data = temp1;
			else
				head->data = temp2;
			break;
		}
		head = head->next;
	}
	
	return 1;
}

//Detect loop in the link list
int LinkedList::DetectLoop(node* head)
{
	node  *first = head, *second = head;
	while( first != NULL && second != NULL && second->next != NULL)
	{
		first = first->next;
        second  = second->next->next;
        if (first == second)
        {
           std::cout<<"\nFound Loop";
           return 1;
        }
	}
	std::cout<<"\nLoop not found";

	return 0;
}

//This function prints contents of linked list starting from head
void LinkedList::printList(node *head)
{
	int index =1;
	printf("[%x]->\n",head);
	while (head != NULL)
	{
		//if(head->next != NULL)
		//	printf("[%d|%x]->\n", head->data, head->next);
		//else
		//	printf("[%d|%x]\n", head->data, head->next);
		printf("[%d]->", head->data);
		head = head->next;
		index++;
	}
}


