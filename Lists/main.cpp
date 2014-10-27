#include <QCoreApplication>
#include <iostream>
#include <random>
#include <memory>
#include "lists.h"
#include "queues.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 100);
    auto getRandom = [&]() { return distribution(generator); };

    Queues queue1(1);
    for (int i = 0; i < 9; i++)
    {
        queue1.addToQueue(getRandom());
    }

    queue1.showQueue();

    Lists list1(getRandom());
    for(int i=0;i<9;i++)
    {
        list1.addToList(getRandom());
    }
    list1.deleteNthElement(8);
    list1.showList();
    list1.swapFirstWithLast();
    list1.showList();

    //--------dynamic object allocation-------------
    /*unique_ptr<Lists> uptr1 = make_unique<Lists>();
    for (int i = 0; i < 5; i++)
    {
    uptr1->addToList(getRandom());
    }
    uptr1->showList();
    cout << "Type a random number, it will be added to list: ";
    int num; cin >> num;
    uptr1->addToList(num);
    uptr1->showList();*/
    //----------------------------------------------

    return a.exec();
}

