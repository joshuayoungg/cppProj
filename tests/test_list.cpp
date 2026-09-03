#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "list.hpp"

TEST_CASE("empty list"){
    List list;
    CHECK(list.empty() == true);
}
TEST_CASE("size test"){
     Order a{1, 10};
    List list;
    list.push_back(&a);
    CHECK(list.size() == 1);
}
TEST_CASE("front test"){
    Order a{12, 10}, b{2, 10}, c{3, 10};
    List list;
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    CHECK(list.front()->id == 12);
}
TEST_CASE("push 3 verify order") {
    Order a{12, 10}, b{2, 10}, c{3, 10};
    List list;
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    CHECK(list.front()->id == 12);
    CHECK(list.front()->next->id == 2);
    CHECK(list.front()->next->next->id == 3);
}
TEST_CASE("unlink head"){
    Order ord{12,10};
    Order ord2{3,4};
    List list;
    list.push_back(&ord);
    list.push_back(&ord2);
    list.unlink(&ord);
    CHECK(list.front()->id == 3);
}
TEST_CASE("unlink tail"){
    Order ord{12,10};
    Order ord2{3,4};
    List list;
    list.push_back(&ord2);
    list.push_back(&ord);
    list.unlink(&ord);
    CHECK(list.front()->id == 3);
}
TEST_CASE("unlink middle node"){
    Order ord{12,10};
    Order ord2{3,4};
    Order ord3{13,4};
    List list;
    list.push_back(&ord2);
    list.push_back(&ord);
    list.push_back(&ord3);
    list.unlink(&ord);
    CHECK(list.front()->id == 3);
    CHECK(list.front()->next->id == 13);
}
TEST_CASE("unlink only node"){
    Order ord{12,10};
    List list;
    list.push_back(&ord);
    list.unlink(&ord);
    CHECK(list.empty() == true);
    CHECK(list.front() == nullptr);
}
TEST_CASE("push 3, pop 3"){
    Order ord{12,10};
    Order ord2{13,4};
    Order ord3{15,4};
    List list;
    list.push_back(&ord);
    list.push_back(&ord2);
    list.push_back(&ord3);
    list.pop_front();
    list.pop_front();
    list.pop_front();
    CHECK(list.empty() == true);
    CHECK(list.front() == nullptr);
}
TEST_CASE("push, unlink, push"){
    Order ord{12,10};
    List list;
    list.push_back(&ord);
    list.unlink(&ord);
    list.push_back(&ord);
    CHECK(list.empty() == false);
    CHECK(list.front()->id == 12);
}