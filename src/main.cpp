#include <iostream>
#include <cstdio>
#include "vec.hpp"

using namespace std;

int main() {
    Vec<int> vect;
    vect.push_back(2);
    int first = vect[0];
    std::cout << "first = " << first << std::endl;
}