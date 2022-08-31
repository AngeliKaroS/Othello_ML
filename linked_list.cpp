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
    tail->next = node;
    tail = node;

    return 0;
}

int
LinkedList::delete(int index)
{
    Node* before;
    current = head;
    int idx = 0

    while (current != NULL)
    {
        if (idx == index)
        {
            before->next = current->next
            delete(current);
            return 0;
        }

        idx++;
    }

    printf("index %d is not found", index);

    return -1;
}
