#include <iostream>
#include "strng.cpp"

using namespace std;

int main() {
    Strng strng;
    strng = "hello";
    std::cout <<  strng << std::endl;
    strng[0] = 'a';
    std::cout <<  strng << std::endl;
    strng += " world";
    std::cout <<  strng << std::endl;
}