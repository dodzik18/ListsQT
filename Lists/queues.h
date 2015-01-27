#pragma once
#include "node.h"

class Queues
{
    
public:

    void addToQueue(int x);
    void showQueue();
    void swapFirstWithLast();
    void delFirstQueueElement(); //removes first element from queue
    void delLastQueueElement(); //removes last element from queue
    void mergeQueues(Queues&, Queues&);

	size_t getQueueSize() const { return count; };

	void getHeadAndTailVal() const;;

	Queues(int x);
	~Queues();
private:
	Node *head = nullptr;
	Node *tail = nullptr;
	size_t count = 0;
	
};
