#include <catch2/catch_test_macros.hpp>

#include "list.hpp"

TEST_CASE("empty list", "[empty]")
{
    LinkedList::List<int> list;

    REQUIRE(list.isEmpty() == true);
    REQUIRE(list.listSize() == 0);
}
