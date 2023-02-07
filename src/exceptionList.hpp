#ifndef EXCEPTIONLIST_HPP
#define EXCEPTIONLIST_HPP

#include <stdexcept>
#include <cstddef>
#include <string>

namespace LinkedList
{
    class empty_list : public std::out_of_range
    {
    public:
        empty_list() : std::out_of_range{"the list is empty"} {}
    };

    class out_of_range : public std::out_of_range
    {
    public:
        explicit out_of_range(const size_t maxSize) : std::out_of_range("position out of range: 0 <= position < " + std::to_string(maxSize)) {}
    };

    class bad_alloc : public std::bad_alloc
    {
        public:
        const char* what() const noexcept override
        {
            return "allocation of memory failed";
        }
        
    };
} // namespace LinkedList

#endif // EXCEPTIONLIST_HPP