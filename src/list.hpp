#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstddef>

namespace LinkedList
{
    template <typename T>
    class List
    {
    private:
        class ListNode
        {
            friend class List;

        public:
            ListNode(const T &value);

        private:
            T data;
            ListNode *nextNode;
        };

    public:
        List();
        ~List();

        bool isEmpty() const;
        size_t size() const;

        T at(size_t position) const;
        T front() const;
        T back() const;

        void push_back(const T &value);
        void pop_back();

    private:
        ListNode *firstNode;
        ListNode *lastNode;

        size_t m_size;

        ListNode *newNode(const T &value);
    };
} // namespace LinkedList

#include "list.cpp"

#endif // LINKEDLIST_HPP