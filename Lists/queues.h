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
};
