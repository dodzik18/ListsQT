#include <iostream>
#include "queues.h"

Queues::Queues(int x)
{
    head = new Node;
    head->val = x;
    head->next = nullptr;
    tail = head;
}

Queues::~Queues()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
}

void Queues::addToQueue(int x)
{
    Node *ptr = new Node;
    ptr->val = x;
    tail->next = ptr;
    ptr->next = nullptr;
    tail = ptr;
}
void Queues::showQueue()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        std::cout << ptr->val << "->";
        ptr = ptr->next;
    }
    std::cout << "NULL" << std::endl;
}
