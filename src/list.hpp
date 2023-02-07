#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstddef>
#include "exceptionList.hpp"
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

        T at(size_t position) const;
        T front() const;
        T back() const;

        void push_back(const T &value);

    private:
        ListNode<T> *firstNode;
        ListNode<T> *lastNode;

        size_t m_size;

        ListNode<T> *newNode(const T &value);
    };
} // namespace LinkedList

#include "list.cpp"

#endif // LINKEDLIST_HPP