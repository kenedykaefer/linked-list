#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include "list.hpp"
#include <vector>
#include <iostream>

TEST_CASE("isEmpty method", "[capacity],[empty]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE(list.isEmpty() == true);
    }
    SECTION("with elements in the list")
    {
        list.push_back(1);
        REQUIRE(list.isEmpty() == false);
        list.push_back(2);
        REQUIRE(list.isEmpty() == false);
        list.pop_back();
        REQUIRE(list.isEmpty() == false);
        list.pop_back();
        REQUIRE(list.isEmpty() == true);
    }
}

TEST_CASE("size method", "[capacity],[size]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE(list.size() == 0);
    }

    SECTION("with elements in the list")
    {
        int i{0};

        while (++i < 10)
        {
            list.push_back(i);
            REQUIRE(list.size() == i);
        }

        list.push_back(i);
        REQUIRE(list.size() == i);

        while (--i)
        {
            list.pop_back();
            REQUIRE(list.size() == i);
        }

        list.pop_back();
        REQUIRE(list.size() == 0);
    }
}

TEST_CASE("back method", "[element access],[back]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list.back(), std::out_of_range);
    }

    SECTION("with elements in the list")
    {
        int i{0};

        while (++i < 10)
        {
            list.push_back(i);
            REQUIRE(list.back() == i);
        }

        list.push_back(i);
        REQUIRE(list.back() == i);

        while (--i)
        {
            list.pop_back();
            REQUIRE(list.back() == i);
        }

        list.pop_back();
        REQUIRE_THROWS_AS(list.back(), std::out_of_range);
    }
}

TEST_CASE("front method", "[element access],[front]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    }

    SECTION("with elements in the list")
    {
        int i{0};

        list.push_back(100);

        while (++i < 5)
        {
            list.push_back(i);
            REQUIRE(list.front() == 100);
        }

        while (--i)
        {
            list.pop_back();
            REQUIRE(list.front() == 100);
        }

        list.pop_back();
        REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    }
}

TEST_CASE("at method", "[element access],[at]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list.at(0), std::out_of_range);
    }

    SECTION("with elements in the list")
    {
        const int count = 100;

        for (int i = 0; i < count; i++)
        {
            list.push_back(i);
        }

        for (int i = 0; i < count; i++)
        {
            REQUIRE(list.at(i) == i);
        }
    }
}

TEST_CASE("push_back method", "[modifiers],[push_back]")
{
    LinkedList::List<size_t> list;
    const size_t count = 100;

    for (size_t i = 0; i < count; i++)
    {
        list.push_back(i);
        REQUIRE(list.back() == i);
    }

    for (size_t i = 0; i < count; i++)
    {
        REQUIRE(list.at(i) == i);
    }
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
