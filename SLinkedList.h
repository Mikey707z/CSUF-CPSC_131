// Code from:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//

#pragma once

#include <stdexcept>

using namespace std;

template <typename E> class SLinkedList;	// forward declaration to be used when declaring SNode

template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E> *next;				// next item in the list
	friend class SLinkedList<E>;		// provide SLinkedList access
};

template <typename E>
class SLinkedList {				// a singly linked list
public:
	SLinkedList();				// empty list constructor
	~SLinkedList();				// destructor
	bool empty() const;			// is list empty?
	E& front();					// return front element
	void addFront(const E& e);		// add to front of list
	void removeFront();			// remove front item list
	int size() const;					// list size
	int NameNumber(string);			// Function for finding the amount of a certain name
	int LowWeight();			// Function for finding the amount of low weight birth 
	string MostPopName();
private:
	SNode<E>* head;				// head of the list
	int     n;							// number of items
};

template <typename E>
SLinkedList<E>::SLinkedList()			// constructor
	: head(NULL), n(0) { }

template <typename E>
bool SLinkedList<E>::empty() const		// is list empty?
{
	return head == NULL; // can also use return (n == 0);
}

template <typename E>
E& SLinkedList<E>::front() 		// return front element
{
	if (empty()) throw length_error("empty list");
	return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{
	while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {	// add to front of list
	SNode<E>* v = new SNode<E>;		// create new node
	v->elem = e;				// store data
	v->next = head;				// head now follows v
	head = v;				// v is now the head
	n++;
}

template <typename E>
void SLinkedList<E>::removeFront() {		// remove front item
	if (empty()) throw length_error("empty list");
	SNode<E>* old = head;			// save current head
	head = old->next;			// skip over old head
	delete old;				// delete the old head
	n--;
}

template <typename E>
int SLinkedList<E>::size() const {				// list size
	return n;
}

template <typename E>
int SLinkedList<E>::NameNumber(string s) 
{
	SNode<E>* Node = head;
	int count=0;
	while (Node != NULL)
	{
		if (Node->elem.getName() == s) count++;
		Node = Node->next;
	}
	return count;
}
template <typename E>
int SLinkedList<E>::LowWeight() 
{
	int count=0;
	SNode<E>* Node = head;
	while (Node != NULL)
	{
		if (Node->elem.getWeight() < 2500) count++;
		Node = Node->next;
	}
	return count;
}

string SLinkedList<Baby>::MostPopName()
{
	int Most = 1;
	string MostPopular = "";
	SNode<Baby>* Node = head;

	while (Node != NULL)
	{
		string ComparisonName = Node->elem.getName();   //get a name to compare with;
		SNode<Baby>* Next = head->next;
		int Temp = 0;
		if (MostPopular != ComparisonName)
		{
			while (Next != NULL)
			{
				if (ComparisonName == Next->elem.getName()) {
					Temp += 1;
				}
				Next = Next->next;
			}

			if (Temp > Most)
			{
				Most = Temp;
				MostPopular = ComparisonName;
			}
		}
		Node = Node->next;

	}
	return MostPopular;
}
