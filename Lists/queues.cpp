#include <iostream>
#include "queues.h"

Queues::Queues(int x)
{
    head = new Node;
    head->val = x;
    head->next = nullptr;
    tail = head;
    count++;
}

Queues::~Queues()
{
    if(head==nullptr) return;

    Node *ptr = head;

    head = head->next;
    delete ptr;
    ptr = head;
    count--;

}

void Queues::addToQueue(int x)
{
    Node *ptr = new Node;
    ptr->val = x;
    tail->next = ptr;
    ptr->next = nullptr;
    tail = ptr;
    count++;
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
    std::cout << "Queue has " << getQueueSize() << " elements." << std::endl;
}
void Queues::swapFirstWithLast()
{
    if(head->next!=nullptr)
    {
        Node *ptr=new Node;
        ptr->val=tail->val;
        tail->val=head->val;
        head->val=ptr->val;
    }
}
void Queues::delFirstQueueElement()
{
    if(head==nullptr) return; //check if queue isnt empty

    if(count==1)
    {
        delete tail;
        return;
    }
    else
    {
        Node *ptr=head;
        head=head->next;
        delete ptr;
        ptr=head;
    }
    count--;

}

void Queues::mergeQueues(Queues queue1, Queues  &queue2) //test
{
   Node *ptr=new Node;
   ptr->val=queue2.head->val;

   int i=1;

   while((queue2.head!=nullptr)&&(queue2.count>1))
   {
       queue1.addToQueue(ptr->val);
       queue2.delFirstQueueElement();
       ptr->val=queue2.head->val;
   }
   queue1.addToQueue(queue2.tail->val);


       std::cout<<"i:"<<i<<"c1:"<<queue1.count<<"c2:"<<queue2.count<<" ";i++; //debug tool

}

void Queues::delLastQueueElement()  //broken
{
    Node *ptr=head;
    while(ptr->next!=tail)
    {
        ptr=ptr->next;
    }
    delete tail;
    tail=ptr;
    count--;
}
