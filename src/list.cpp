#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "list.hpp"

template <typename T>
LinkedList::List<T>::ListNode::ListNode(const T &value) : data{value}, nextNode{nullptr}
{
}

template <typename T>
LinkedList::List<T>::List() : firstNode{nullptr}, lastNode{nullptr}, m_size{0}
{
}

template <typename T>
LinkedList::List<T>::~List()
{
    while (firstNode != nullptr)
    {
        ListNode *tempNode{firstNode};
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

    const ListNode *currentNode{firstNode};

    while (position--)
        currentNode = currentNode->nextNode;

    return currentNode->data;
}

template <typename T>
T LinkedList::List<T>::front() const
{
    if (!m_size)
        throw empty_list();

    return firstNode->data;
}

template <typename T>
T LinkedList::List<T>::back() const
{
    if (!m_size)
        throw empty_list();

    return lastNode->data;
}

template <typename T>
typename LinkedList::List<T>::ListNode *LinkedList::List<T>::newNode(const T &value)
{
    try
    {
        return new ListNode(value);
    }
    catch (const std::exception &e)
    {
        throw LinkedList::bad_alloc();
    }
}

template <typename T>
void LinkedList::List<T>::push_back(const T &value)
{
    try
    {
        if (m_size)
        {
            lastNode->nextNode = newNode(value);
            lastNode = lastNode->nextNode;
        }
        else
        {
            firstNode = newNode(value);
            lastNode = firstNode;
        }
        m_size++;
    }
    catch (const std::exception &e)
    {
        throw;
    }
}

template <typename T>
void LinkedList::List<T>::pop_back()
{
    if (firstNode == nullptr)
        throw LinkedList::empty_list();

    ListNode *currentNode{firstNode};

    if (firstNode == lastNode)
    {
        firstNode = lastNode = nullptr;
        delete currentNode;
    }
    else
    {
        while (currentNode->nextNode != lastNode)
            currentNode = currentNode->nextNode;
        lastNode = currentNode;
        delete currentNode->nextNode;
        currentNode->nextNode = nullptr;
    }
    m_size--;
}
#endif // LINKEDLIST_CPP