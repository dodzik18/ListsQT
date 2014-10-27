#pragma once
#include "node.h"

class Lists
{
    Node *head = nullptr;
    size_t count = 0;
    unsigned getListSize() const { return count; }
    void getHeadValue() const{ std::cout << head->val << std::endl; }  //debug tool

public:
    Lists(int x);
    Lists() {};  //to let unique_ptr<> work
    ~Lists();
    void addToList(int x);
    void showList() const;
    void howDoesRandomFunctionWork();
    void deleteFromList(); //removes first element on the list
    void deleteNthElement(int n); //we are sending index of element that, we want to delete. i.e. fourth element, sixth, etc
    void mergeLists(Lists &list1, Lists &list2);
    void swapFirstWithLast();
    void copyEqualToValue();
    void addBeforeGivenX(int value, int element); //we are inserting -value- just before -element-
    void addAfterGivenX(int value, int element); //same as above, but it adds -value- after -element-
};
