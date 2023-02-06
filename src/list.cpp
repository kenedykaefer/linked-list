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
T LinkedList::List<T>::at(size_t position) const
{
    if (!m_size)
        throw empty_list();

    if (position >= m_size)
        throw out_of_range(m_size);

    const ListNode<T> *currentNode{firstNode};

    while (position--)
        currentNode = currentNode->nextNode;

    return currentNode->m_data;
}

template <typename T>
T LinkedList::List<T>::front() const
{
    if (!m_size)
        throw empty_list();

    return firstNode->m_data;
}

template <typename T>
T LinkedList::List<T>::back() const
{
    if (!m_size)
        throw empty_list();

    return lastNode->m_data;
}

template <typename T>
void LinkedList::List<T>::push_back(const T &value)
{
}
#endif // LINKEDLIST_CPP