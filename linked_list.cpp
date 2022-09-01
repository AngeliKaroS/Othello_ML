#include <stdio.h>
#include "linked_list.h"

LinkedList::LinkedList()
{
    Node* node = new Node;

    head = node;
    tail = node;
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
LinkedList::append(struct point* point)
{
    if (tail->value != NULL)
    {
        tail->next = new Node;
        tail = tail->next;
    }

    tail->value = point;

    return 0;
}

int
LinkedList::remove(int index)
{
    Node* before;
    current = head;
    int idx = 0

    while (current != NULL)
    {
        if (idx == index)
        {
            if (current == tail)
                tail = before;

            before->next = current->next
            delete(current);
            return 0;
        }

        idx++;
    }

    printf("index %d is not found", index);

    return -1;
}
