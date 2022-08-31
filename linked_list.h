#include "othello.h"

public class Node
{
public:
    Node* next;
    struct point* value;
};

public class LinkedList
{
public:
    int   append(Node node);
    int   delete(int index);
    Node* pop();
    Node* shift();

    void treverse();
    int  get_length();

private:
    Node* head;
    int   length;
};
