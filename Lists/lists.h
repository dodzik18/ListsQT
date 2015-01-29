#pragma once
#include "node.h"
class Lists
{
public:

    void addToList(int x);
	void addToList(double x);
	void addToList(float x);
    void showList() const;
    void deleteFromList(); //removes first element on the list
    void deleteNthElement(int n); //we are sending index of element that, we want to delete. i.e. fourth element, sixth, etc
    void mergeLists(Lists&, Lists&);
    void swapFirstWithLast();
    void copyEqualToValue();
    void addBeforeGivenValue(int value, int element); //we are inserting -value- just before -element-
    void addAfterGivenValue(int value, int element); //same as above, but it adds -value- after -element-
    void swapGivenValueWithSuccessor(int value);
	void deleteNelementsAfterValue(int value, int element); 
	void invertList();


	Lists();
	explicit Lists(int x);
	~Lists();


	/*getters and setters*/
	Node* getHead() const { return head;}
	int getHeadValue() const { return head->val; }
	void set_Head(Node* node) { head = node; }
	
	size_t getSizeT() const	{ return listSize; }
	void set_ListSize(size_t sizeT) { listSize = sizeT; }

private:
	Node *head = nullptr;
	size_t listSize = 0;
};

/*
	To Do:

	
	
	
	*/
