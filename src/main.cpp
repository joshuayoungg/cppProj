#include <iostream>
#include <cstdio>
#include "vec2.cpp"

int main() {
    Vec2<int> vect;
    vect.push_back(2);
    vect.push_back(23);
    vect.push_back(4);
    vect.printVec();
    vect.pop_back();
    vect.printVec();
    vect.push_back(50);
    vect.printVec();
    vect.removeIndex(1);
    vect.printVec();
    Vec2<int> vect2(vect);
    vect2.push_back(9);
    vect2.printVec();
}