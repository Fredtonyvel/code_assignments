#ifndef LIST_H
#define LIST_H

#include "Professor.h"
#include <string>

class Node
{
public:
	Professor professor;
	Node *next;
	
	Node()
	{
		next = NULL;
	}
	Node(const Professor &obj, Node *ptr = NULL)
	{
		professor = obj;
		next = ptr;
	}

};

class list
{
private:
	Node *head;
	Node *tail;

public:
	list()
	{
		head = tail = NULL;
	}

	~list();

	int isEmpty()
	{
		return head == NULL;
	}
	void addToHead(const Professor &professor);
	void addToTail();
	void print();
};

#endif /* LIST_H */