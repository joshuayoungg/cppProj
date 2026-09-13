#include <iostream>
#include <cstdio>
#include "hashTable.cpp"

using namespace std;

int main() {
    HashTable table = HashTable();
    table.printTable();
    table.insertItem(5, "car");
    table.insertItem(9, "book");
    table.insertItem(12, "song");
    table.insertItem(116, "food");
    table.insertItem(112, "ice");
    table.insertItem(7, "sweet");
    table.printTable();
    table.removeItem(5);
    table.removeItem(12);
    table.printTable();
}