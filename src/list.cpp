#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "list.hpp"

template <typename T>
LinkedList::List<T>::List() : firstNode{nullptr}, lastNode{nullptr}, m_size{0}
{
}

template <typename T>
LinkedList::List<T>::~List()
{
    while (firstNode != nullptr)
    {
        ListNode<T> *tempNode{firstNode};
        firstNode = firstNode->nextNode;
        delete tempNode;
    }
}

template <typename T>
bool LinkedList::List<T>::isEmpty() const
{
    return !m_size;
}

template <typename T>
size_t LinkedList::List<T>::size() const
{
    return m_size;
}

template <typename T>
T LinkedList::List<T>::at(const size_t position) const
{
}

template <typename T>
T LinkedList::List<T>::front() const
{
}

template <typename T>
T LinkedList::List<T>::back() const
{
}
#endif // LINKEDLIST_CPP