#include <iostream>
#include "que.cpp"

int main() {
    Queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.printStack();
    qu.pop();
    qu.printStack();
    qu.pop();
    qu.printStack();
}