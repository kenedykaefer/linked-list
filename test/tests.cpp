#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "list.hpp"

TEST_CASE("empty list", "[empty]")
{
    LinkedList::List<int> list;

    REQUIRE(list.isEmpty());
    REQUIRE(list.size() == 0);
}