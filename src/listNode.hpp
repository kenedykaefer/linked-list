#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include "list.hpp"

namespace LinkedList
{
    template <typename TYPE>
    class List;

    template <typename NODETYPE>
    class ListNode
    {
        friend class List<NODETYPE>;

    public:
        explicit ListNode(const NODETYPE &data);

    private:
        ListNode<NODETYPE> *nextNode;
        NODETYPE data;
    };
} // namespace LinkedList

#endif // LISTNODE_HPP