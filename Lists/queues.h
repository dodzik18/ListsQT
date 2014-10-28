#pragma once
#include "node.h"

class Queues
{
    Node *head = nullptr;
    Node *tail = nullptr;
    unsigned getQueueSize() const { };
    void getHeadAndTailVal() const { };
public:
    Queues(int x);
    ~Queues();
    void addToQueue(int x);
    void showQueue();
    void swapFirstWithLast();
    void mergeQueues(Queues &queue1, Queues  &queue2);
    void delFirstQueueElement(); //removes first element from queue
    void delLastQueueElement(); //removes last element from queue
};
