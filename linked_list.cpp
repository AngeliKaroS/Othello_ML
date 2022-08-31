#include <stdio.h>
#include "linked_list.h"

LinkedList::LinkedList()
{
    Node* node = new Node;

    head = node;
}

~LinkedList::LinkedList()
{
    node* current = head;
    node* next;

    while (current != NULL)
    {
        next = current->next;
        delete(current);
    }
}

int
LinkedList::append(Node* node)
{
}
