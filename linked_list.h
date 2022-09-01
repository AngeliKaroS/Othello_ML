#pragma once

#include "othello.h"

class Node
{
public:
    Node* next;
    struct point* value;
};

class LinkedList
{
public:
    int   append(Node node);
    int   remove(int index);
    Node* pop();
    Node* shift();

    void treverse();
    int  get_length();

private:
    Node* head;
    Node* tail;
    int   length;
};
