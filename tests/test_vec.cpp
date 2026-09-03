#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "vec.hpp"

TEST_CASE("can create vec")
{
    Vec<int> vect;
    CHECK(vect.size() == 0);
}
TEST_CASE("can add to vec")
{
    Vec<int> vect;
    vect.push_back(2);
    CHECK(vect[0] == 2);
}
TEST_CASE("can check capacity vec")
{
    Vec<int> vect;
    CHECK(vect.capacity() == 2);
}
TEST_CASE("can reserve vec")
{
    Vec<int> vect;
    vect.reserve(100);
    CHECK(vect.capacity() == 100);
}
TEST_CASE("can add 10 elements")
{
    Vec<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(7);
    vect.push_back(8);
    vect.push_back(9);
    vect.push_back(10);
    CHECK(vect[9] == 10);
    CHECK(vect.size() == 10);
}
TEST_CASE("can use string type")
{
    Vec<std::string> vect;
    vect.push_back("animal");
    CHECK(vect[0] == "animal");
}
TEST_CASE("can use char type")
{
    Vec<char> vect;
    vect.push_back('a');
    CHECK(vect[0] == 'a');
}
TEST_CASE("can pop item")
{
    Vec<int> vect;
    vect.push_back(1);
    vect.pop_back();
    CHECK(vect.size() == 0);
}
TEST_CASE("can pop string")
{
    Vec<std::string> vect;
    vect.push_back("ab");
    vect.pop_back();
    CHECK(vect.size() == 0);
}
TEST_CASE("can check empty")
{
    Vec<int> vect;
    CHECK(vect.empty() == true);
}
TEST_CASE("can use operator")
{
    Vec<int> vect;
    vect.push_back(15);

    Vec<int> vt = vect;
    CHECK(vt.size() == 1);
    CHECK(vt[0] == 15);
}
TEST_CASE("can use copy operator")
{
    Vec<int> vect;
    vect.push_back(15);

    Vec<int> vt(vect);
    CHECK(vt.size() == 1);
    CHECK(vt[0] == 15);
}
TEST_CASE("can clear a vector")
{
    Vec<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.clear();
    CHECK(vect.size() == 0);
}
TEST_CASE("self push_back")
{
    Vec<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(v[0]);
}