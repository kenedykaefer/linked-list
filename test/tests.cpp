#include <catch2/catch_test_macros.hpp>

#include "list.hpp"

TEST_CASE("empty list", "[capacity],[empty]")
{
    LinkedList::List<int> list;

    SECTION("new list")
    {
        REQUIRE(list.isEmpty() == true);
    }
}

TEST_CASE("list size", "[capacity],[size]")
{
    LinkedList::List<int> list;

    SECTION("new list")
    {
        REQUIRE(list.size() == 0);
    }
}