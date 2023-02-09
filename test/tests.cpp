#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include "list.hpp"
#include <vector>
#include <iostream>

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
        REQUIRE_THROWS_AS(list.back(), std::out_of_range);
    }
}

TEST_CASE("access the first element", "[element access],[front]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    }
}

TEST_CASE("access the specified element", "[element access],[at]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list.at(0), std::out_of_range);
    }
}

TEST_CASE("add element at the end", "[modifiers],[push_back]")
{
    LinkedList::List<int> list;

    auto i = GENERATE(take(100, random(-1000, 1000)));
    list.push_back(i);
    REQUIRE(list.back() == i);
}

TEST_CASE("pop_back method", "[modifiers],[pop_back]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list.pop_back(), std::out_of_range);
    }

    SECTION("with one element in the list")
    {
        list.push_back(1);
        list.pop_back();
        REQUIRE(list.isEmpty() == true);
    }

    SECTION("with elements in the list")
    {
        int i{0};

        while (++i < 100)
            list.push_back(i);

        list.push_back(i);

        while (--i)
        {
            list.pop_back();
            REQUIRE(list.back() == i);
        }

        list.pop_back();

        REQUIRE(list.isEmpty() == true);
    }
}
