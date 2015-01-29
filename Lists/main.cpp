#include <random>
#include <iostream>
#include "lists.h"
#include "queues.h"
#include "node.h"


using namespace std;

int main()
{
	/* random number generator in accordance with the standard*/
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 100);
    auto getRandom = [&]() { return distribution(generator); };


    Lists list, list2;
    for (int i = 0; i < 10; i++)
    {
        list.addToList(i);
		list2.addToList(getRandom());
    }

    list.showList();

	list.invertList();
	
	list.showList();



    //--------dynamic memory allocation-------------
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

	return 0;
}

