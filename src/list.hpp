#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstddef>
#include "listNode.hpp"

namespace LinkedList
{
    template <typename T>
    class List
    {
    public:
        List();
        ~List();

        bool isEmpty() const;
        size_t size() const;

        T at(const size_t position) const;
        T front() const;
        T back() const;

    private:
        ListNode<T> *firstNode;
        ListNode<T> *lastNode;

        size_t m_size;
    };
} // namespace LinkedList

#include "list.cpp"

#endif // LINKEDLIST_HPP