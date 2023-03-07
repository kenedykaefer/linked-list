#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>
#include "list.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>

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

TEST_CASE("list iterator", "[iterator]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE(list.begin() == list.end());

        SECTION("standard for loop")
        {
            for (LinkedList::List<int>::iterator it{list.begin()}; it != list.end(); ++it)
            {
                REQUIRE(false);
            }
        }

        SECTION("range-based for loop")
        {
            for (const auto &v : list)
            {
                REQUIRE(false);
            }
        }
    }

    SECTION("with elements in the list")
    {
        int i{0};

        while (i++ < 100)
        {
            list.push_back(i);
        }

        i = 0;

        SECTION("standard for loop")
        {
            for (LinkedList::List<int>::iterator it{list.begin()}; it != list.end(); ++it)
            {
                REQUIRE(*it == ++i);
            }
        }

        SECTION("range-based for loop")
        {
            for (const auto &v : list)
            {
                REQUIRE(v == ++i);
            }
        }
    }
}

TEST_CASE("clear method", "[clear]")
{
    LinkedList::List<int> list;

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.isEmpty());
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);

    int i{0};

    while (i++ < 10)
    {
        list.push_back(i);
    }

    REQUIRE(list.size() == 10);
    REQUIRE(list.isEmpty() == false);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 10);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.isEmpty());
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}

TEST_CASE("operator[] method", "[element access],[operator],[brackets]")
{
    LinkedList::List<int> list;

    SECTION("with the empty list")
    {
        REQUIRE_THROWS_AS(list[0], std::out_of_range);
        REQUIRE_THROWS_AS(list[1], std::out_of_range);
    }

    SECTION("with elements in the list")
    {
        const int count = 100;

        for (int i = 0; i < count; i++)
        {
            list.push_back(i);
        }

        for (size_t i = 0; i < count; i++)
        {
            REQUIRE(list[i] == i);
        }
    }
}

TEMPLATE_TEST_CASE("list test with", "[template]", int, double, float, char, short, long, long long, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long)
{
    LinkedList::List<TestType> list;

    REQUIRE(list.isEmpty() == true);
    REQUIRE(list.size() == 0);

    TestType value_mim{0};
    TestType value_max{100};
    if (std::is_signed<TestType>::value)
    {
        value_mim = -100;
    }
    else
    {
        value_max = 200;
    }
    const size_t count = 200;
    TestType value{value_mim};

    for (size_t i = 0; i < count; i++)
    {
        list.push_back(value);
        REQUIRE(list.back() == value);
        value++;
    }

    list.push_back(value);

    REQUIRE(list.front() == value_mim);
    REQUIRE(list.back() == value_max);
    REQUIRE(list.size() == (abs(value_mim) + abs(value_max) + 1));
    REQUIRE(list.isEmpty() == false);

    value = value_mim;

    for (size_t i = 0; i < count; i++)
    {
        REQUIRE(list.at(i) == value++);
    }

    value = value_max;

    for (size_t i = 0; i < count; i++)
    {
        list.pop_back();
        REQUIRE(list.back() == --value);
    }

    REQUIRE(list.front() == value_mim);
    REQUIRE(list.front() == list.back());
    REQUIRE(list.size() == 1);
    list.pop_back();
    REQUIRE(list.isEmpty() == true);

    REQUIRE_THROWS_AS(list.pop_back(), std::out_of_range);
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
    REQUIRE_THROWS_AS(list.at(0), std::out_of_range);
}

TEST_CASE("list test with std::string", "[template]")
{
    LinkedList::List<std::string> list;

    REQUIRE(list.isEmpty() == true);
    REQUIRE(list.size() == 0);

    const int value_mim{-100};
    const int value_max{100};
    const size_t count = 200;
    int value{value_mim};
    std::string str;

    for (size_t i = 0; i < count; i++)
    {
        str = "number: " + std::to_string(value);
        list.push_back(str);
        REQUIRE(list.back() == str);
        value++;
    }

    str = "number: " + std::to_string(value);
    list.push_back(str);

    str = "number: " + std::to_string(value_mim);
    REQUIRE(list.front() == str);

    str = "number: " + std::to_string(value_max);
    REQUIRE(list.back() == str);

    REQUIRE(list.size() == (abs(value_mim) + abs(value_max) + 1));
    REQUIRE(list.isEmpty() == false);

    value = value_mim;

    for (size_t i = 0; i < count; i++)
    {
        str = "number: " + std::to_string(value++);
        REQUIRE(list.at(i) == str);
    }

    value = value_max;

    for (size_t i = 0; i < count; i++)
    {
        list.pop_back();
        str = "number: " + std::to_string(--value);
        REQUIRE(list.back() == str);
    }

    str = "number: " + std::to_string(value_mim);
    REQUIRE(list.front() == str);
    REQUIRE(list.front() == list.back());
    REQUIRE(list.size() == 1);
    list.pop_back();
    REQUIRE(list.isEmpty() == true);

    REQUIRE_THROWS_AS(list.pop_back(), std::out_of_range);
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
    REQUIRE_THROWS_AS(list.at(0), std::out_of_range);
}