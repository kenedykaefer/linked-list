#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include "list.hpp"

namespace LinkedList
{
    template <typename NODETYPE>
    class List;

    template <typename NODETYPE>
    class ListNode
    {
        friend class List<NODETYPE>;

    public:
        explicit ListNode(const NODETYPE &data) : m_data{data}, nextNode{nullptr} {}

    private:
        ListNode<NODETYPE> *nextNode;
        NODETYPE m_data;
    };
} // namespace LinkedList

#endif // LISTNODE_HPP