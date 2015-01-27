#pragma once

/*Containt struct, that is base for Queue and List, it is 'single cell' of both*/
struct Node
{
    Node *next;
	int val;

	friend void swap(Node&, Node&);
};