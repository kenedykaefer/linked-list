#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "listNode.hpp"

namespace LinkedList
{
    template <typename TYPE>
    class List
    {
    public:
        List();
        ~List();

        bool isEmpty();
        unsigned size();

    private:
        ListNode<TYPE> *firstNode;
        ListNode<TYPE> *lastNode;

        unsigned m_size;
    };
} // namespace LinkedList

#include "list.cpp"

#endif // LINKEDLIST_HPP