#include "lists.h"
#include "node.h"
#include <iostream>
#include <vector>


Lists::Lists()
{
	/*simply setting first's element value to zero*/
	Node* head = new Node;
	head->val = 0;
}

Lists::Lists(int x)
{
	addToList(x);
}

/*
each function that is doing something with list have to initialize its own pointer, that can store values, and pointers while moving/deleting/adding other cells
*/
Lists::~Lists()
{
	Node* ptr = head;
	while (ptr != nullptr)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
}

void Lists::addToList(int x)
{
	Node* ptr = new Node;
	ptr->val = x;
	ptr->next = head;
	head = ptr;
	listSize++;
}

void Lists::addToList(double x)
{
	addToList( static_cast<int>(x) );
}

void Lists::addToList(float x)
{
	addToList( static_cast<int>(x) );
}

void Lists::showList() const
{
	Node* ptr = head;
	while (ptr != nullptr)
	{
		std::cout << ptr->val << "->";
		ptr = ptr->next;
	}
	std::cout << "NULL" << std::endl;
	std::cout << "List has " << getSizeT() << " elements." << std::endl;
}

void Lists::deleteFromList()
{
	Node* ptr = head;
	if (ptr != nullptr)
	{
		head = head->next;
		delete ptr;
		listSize--;
	}
}

void Lists::deleteNthElement(int n)
{
	Node* ptr = head;
	int i = 0;
	while ((ptr != nullptr) && (i < n - 1))
	{
		ptr = ptr->next;
		i++;
	}
	if (ptr->next != nullptr)
	{
		Node* temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
		listSize--;
	}
}

void Lists::mergeLists(Lists& list1, Lists& list2)
{
	Node* ptr = list2.head;
	int temp = list2.listSize; //got to use /for(;i<temp;)/ instead of /for(;list2.listSize;)/, dont know why....
	for (int i = 0; i < temp; i++)
	{
		list1.addToList(ptr->val);
		list2.deleteFromList();
		ptr = list2.head;
	}
}

void Lists::swapFirstWithLast()
{
	Node* ptr = head;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}
	Node* temp = new Node; //for swap() purposes

	//---simple swap() operation is done here
	temp->val = head->val;
	head->val = ptr->val;
	ptr->val = temp->val;
}

void Lists::addBeforeGivenValue(int value, int element)
{
	Node* ptr = head;
	if (element == head->val)
	{
		addToList(value);
	}
	else
	{
		while ((ptr != nullptr) && (ptr->next->val != element))
		{
			ptr = ptr->next;
		}

		Node* temp = new Node;
		temp->val = value;
		temp->next = ptr->next;
		ptr->next = temp;
		listSize++;
	}
}

void Lists::copyEqualToValue()
{
	Node* ptr = head;
	while (ptr != nullptr)
	{
		int i = ptr->val;
		for (int j = 0; j < i - 1; j++)
		{
			addBeforeGivenValue(i, i);
		}
		ptr = ptr->next;
	}
}

void Lists::addAfterGivenValue(int value, int element)
{
	Node* ptr = head;
	if (element == head->val)
	{
		addToList(value);
	}
	else
	{
		while ((ptr != nullptr) && (ptr->val != element))
		{
			ptr = ptr->next;
		}
		/* im inserting cell in between */
		Node* temp = new Node;
		temp->val = value;
		temp->next = ptr->next;
		ptr->next = temp;
		listSize++;
	}
}

void Lists::swapGivenValueWithSuccessor(int value)
{
	Node* ptr = head;
	while (ptr->val != value)
	{
		ptr = ptr->next;
	}
	swap(*ptr, *ptr->next);
}

void Lists::deleteNelementsAfterValue(int value, int element)
{
	Node* ptr = head;
	Node* temp = new Node;
	auto delCounter = element; //number of elements to delete
	auto i = 0;
	while (ptr->val != value)
	{
		ptr = ptr->next;
	}
	while ((ptr != nullptr) && (i < delCounter))
	{
		temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
		listSize--;
		i++;
	}
}

void Lists::invertList()
{
	Node*ptr = head;
	std::vector <int> tempToStoreList;
	while (ptr!=nullptr)
	{
		tempToStoreList.push_back(ptr->val);
		ptr = ptr->next;
		deleteFromList();
	}
	for (int i = 0; i < tempToStoreList.size();i++)
	{
		addToList(tempToStoreList[i]);
	}
}