#include "pracList.h"


//Destructor to destroy List
List::~List()
{	
	cout << "\nDestroying list...\n";

	Node *ptr = head;	//Declaring node ptr to point to node that head is pointing to 
	while(ptr != NULL && !isEmpty())	//traversing list until end of list of isn't empty
	{
		ptr = head->next;	//ptr moving to the next element
		delete head;	//delete head and node it's pointing to
		head = ptr;	//reset head to point to node that ptr is pointing to
	}	
}

//Inserting element to front of list
void List::addToHead(int info)
{
	//creating a new node and make head point to it
	head = new Node(info, head);	//"info" will be assigned to (data) and "head" to (next) ptr
	if (tail == NULL)	//if list is empty, point tail to what head is pointing to
		tail = head;
}

//Inserting element to the end of the list
void List::addToTail(int info)
{
	//if list is empty, add node to list 
	if (isEmpty())
		head = tail = new Node(info);	//head & tail point to newly inserted node
	else
	{
		//Otherwise, insert node after the last node in list 
		tail->next = new Node(info);
		tail = tail->next;	//Make tail point to the newly inserted node
	}
}

//Inserting element at any position on the list 
void List::addNode(int info, int position)
{
	/*	Just a model to figure out how to add a node
		t          t -> c -> p            t c p
		* * *  =>  *    *    * *      =>  * * * *
	  	  p            	|>(new node)    
	*/
	if (size() < position)
	{
		cout << "Invalid position!" << "\nCannot add " << info 
			 << " at position " << position << "\nSize of list = " 
			 << size() << "\nAdding node at postion " << size() 
			 << "\nStandby...\n";
		addNode(info, size());
	}
	else if (position == 0)
		head = new Node(info, head);
	else
	{
		Node *tmp, *ptr = head, *curr = new Node(info);
		for (int i = 0; i < position; i++)
		{
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next = curr;
		curr->next = ptr;
	}
}

//Removing element from front of the list
int List::deleteFromHead()
{
	int info = head->data;	//storing value of head node to var info
	Node *ptr = head;		//pointing ptr to the node that head is pointing to
	head = head->next;		//pointing head to the next element
	delete ptr;				//deleting ptr & associated node
	
	return info;
}

//Removing element from end of the list
int List::deleteFromTail()
{
	int info = tail->data;	//storing value of tail node to var info
	if (head == tail)		//If there's only one element
	{
		delete head;		//delete it
		head = tail = NULL;	//and make head & tail point to NULL
	}
	else
	{
		Node *ptr;
		//Traverse ptr through the list until you get to the 2nd to last element (tail)
		for(ptr = head; ptr->next != tail; ptr = ptr->next);
		//the following 3 lines are not included in the for loop
		delete tail;	
		tail = ptr;		//since tail was deleted, reset it to the node ptr is pointing to
		tail->next = NULL;	//to make sure that it is the last element on the list
	}
	return info;
}

//Removing element from the list
int List::deleteFromList(int info)
{
	/* Diagram to remove node from list
	   h     t   in=3
	   1 2 3 4
	       p 
         t
	*/
	if (head->data == info && head == tail)
	{	
		delete head;
		head = tail = NULL;
	}
	else if (info == head->data)
	{
		Node *ptr = head;
		head = head->next;
		delete ptr;
	}
	else
	{
		Node *ptr, *tmp;
		for (tmp = head, ptr = head->next; ptr != NULL && !(ptr->data == info); tmp = tmp->next, ptr = ptr->next);
		if (ptr != NULL)
		{
			tmp->next = ptr->next;	
			if (ptr == tail)
			{
				tail = tmp;
				delete ptr;
			}
		}
	}
	return info;
}

void List::printList()
{
	//Check to see if List is empty
	if (isEmpty())
		cout << "List is empty\n";

	Node *ptr = head;
	cout << "\nList: ";
	while(ptr != NULL)	//Print elements on list until you reach the end
	{
		cout << ptr->data << " +-> ";
		ptr = ptr->next;  //move ptr to the next element
	}
	cout << "NULL\n\n";
}

int List::size()
{
	int count = 0;
	for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
		count++;

	return count;
}