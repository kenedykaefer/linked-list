#include "list.hpp"

template <typename TYPE>
LinkedList::List<TYPE>::List()
{
    firstNode = nullptr;
    lastNode = nullptr;

    size = 0;
}

template <typename TYPE>
LinkedList::List<TYPE>::~List()
{
    while (firstNode != nullptr)
    {
        ListNode<TYPE> *tempNode{firstNode};
        firstNode = firstNode->nextNode;
        delete tempNode;
    }
}

template <typename TYPE>
bool LinkedList::List<TYPE>::isEmpty()
{
    return !size;
}

template <typename TYPE>
unsigned LinkedList::List<TYPE>::listSize()
{
    return size;
}

void a()
{
    LinkedList::List<int> a;
    a.isEmpty();
    a.listSize();
}