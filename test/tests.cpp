#include <catch2/catch_test_macros.hpp>

#include "list.hpp"

TEST_CASE("empty list", "[capacity],[empty]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE(list.isEmpty() == true);
    }
}

TEST_CASE("list size", "[capacity],[size]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE(list.size() == 0);
    }
}

TEST_CASE("access the last element", "[element access],[back]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS(list.back());
    }
}

TEST_CASE("access the first element", "[element access],[front]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS(list.front());
    }
}

TEST_CASE("access the specified element", "[element access],[at]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS(list.at(0));
    }
}