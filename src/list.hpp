#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstddef>
#include <initializer_list>

namespace LinkedList
{
    template <typename T>
    class List
    {
    private:
        class ListNode
        {
        public:
            ListNode(const T &value);
            T data;
            ListNode *nextNode;
        };

    public:
        List();
        List(std::initializer_list<T> values);
        ~List();

        bool isEmpty() const;
        size_t size() const;

        T operator[](size_t position) const;
        T at(size_t position) const;
        T front() const;
        T back() const;

        void push_back(const T &value);
        void pop_back();
        void clear();

        class iterator
        {
        public:
            iterator(ListNode *node = nullptr);

            T &operator*() const;
            bool operator!=(const iterator &other) const;
            bool operator==(const iterator &other) const;
            iterator &operator++();

        private:
            ListNode *m_node;
        };

        iterator begin();
        iterator end();

    private:
        ListNode *firstNode;
        ListNode *lastNode;

        size_t m_size;

        ListNode *newNode(const T &value);
    };
} // namespace LinkedList

#include "list.cpp"

#endif // LINKEDLIST_HPP