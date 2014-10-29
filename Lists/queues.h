#pragma once
#include "node.h"

class Queues
{
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t count=0;
    size_t getQueueSize() const { return count; };
    void getHeadAndTailVal() const { };
public:
    Queues(int x);
    ~Queues();
    void addToQueue(int x);
    void showQueue();
    void swapFirstWithLast();
    void delFirstQueueElement(); //removes first element from queue
    void delLastQueueElement(); //removes last element from queue
    void mergeQueues(Queues queue1, Queues  &queue2);

};
