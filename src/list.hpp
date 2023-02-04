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
        unsigned listSize();

    private:
        ListNode<TYPE> *firstNode;
        ListNode<TYPE> *lastNode;

        unsigned size;
    };
} // namespace LinkedList

#include "list.cpp"

#endif // LINKEDLIST_HPP