#include <iostream>
#include <cstdio>
#include "stck.cpp"

int main() {
    Stck stck = Stck<int>();
    stck.push(1);
    stck.push(2);
    stck.push(3);
    stck.push(4);
    std::cout << "TOP = " << stck.top() << std::endl;
    stck.printStack();
    stck.pop();
    std::cout << "TOP = " << stck.top() << std::endl;
    stck.printStack();
    stck.pop();
    std::cout << "TOP = " << stck.top() << std::endl;
    stck.printStack();
}