#include "listNode.hpp"

template <typename NODETYPE>
LinkedList::ListNode<NODETYPE>::ListNode(const NODETYPE &data) : data{data}, nextNode{nullptr}
{
}