#include <iostream>
#include "lists.h"

Lists::Lists(int x)
{
    addToList(x);
}

Lists::~Lists()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
    //std::cout << "Succes" << std::endl; //check if destructor works
}

void Lists::addToList(int x)
{
    Node *ptr = new Node; //memalloc for *ptr
    ptr->val = x;
    ptr->next = head;
    head = ptr;
    count++;
}

void Lists::showList() const
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        std::cout << ptr->val << "->";
        ptr = ptr->next;
    }
    std::cout << "NULL" << std::endl;
    std::cout << "List has " << getListSize() << " elements." << std::endl;
    //getHeadValue();
}

void Lists::howDoesRandomFunctionWork()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->val == 100) std::cout << ptr->val << "->";

        ptr = ptr->next;
    }
    std::cout << "NULL" << std::endl;
}
void Lists::deleteFromList()
{
    Node *ptr = head;
    if (ptr != nullptr)
    {
        head = head->next;
        delete ptr;
        count--;
    }
}

void Lists::deleteNthElement(int n)
{
    Node*ptr = head;
    int i = 0;
    while ((ptr != nullptr) && (i < n - 1))
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr->next != nullptr)
    {
        Node *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        count--;
    }
}
void Lists::mergeLists(Lists &list1, Lists &list2)
{
    Node *ptr = list2.head;
    int temp = list2.count;  //got to use /for(;i<temp;)/ instead of /for(;list2.count;)/, dont know why....
    for (int i = 0; i < temp; i++)
    {
        list1.addToList(ptr->val);
        list2.deleteFromList();
        ptr = list2.head;
    }
}
void Lists::swapFirstWithLast()
{
    Node *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    Node *temp = new Node; //for swap() purposes

    //---simple swap() operation is done here
    temp->val = head->val;
    head->val = ptr->val;
    ptr->val = temp->val;
}
void Lists::addBeforeGivenX(int value, int element)
{
    Node *ptr = head;
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

        Node *temp = new Node;
        temp->val = value;
        temp->next = ptr->next;
        ptr->next = temp;
        count++;
    }
}

void Lists::copyEqualToValue()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        int i = ptr->val;
        for (int j = 0; j < i - 1; j++)
        {
            addBeforeGivenX(i, i);
        }
        ptr = ptr->next;
    }
}
void Lists::addAfterGivenX(int value, int element)
{
    Node *ptr = head;
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
        Node *temp = new Node;
        temp->val = value;
        temp->next = ptr->next;
        ptr->next = temp;
        count++;
    }
}
void Lists::swapGivenXWithSuccessor(int value)
{
    Node *ptr=head;
    while(ptr->val!=value)
    {
        ptr=ptr->next;
    }
    Node *temp=new Node;
    temp->val=ptr->val;
    ptr->val=ptr->next->val;
    ptr->next->val=temp->val;
    delete temp;
}
void Lists::deleteNElementsAfterX(int value, int element)
{
    Node *ptr=head;
    while(ptr->val!=)
}
