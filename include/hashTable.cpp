#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10;
    unsigned int length = 0;
    list<pair<int, string>> table[hashGroups];
    pair<int, string> *findHelper(int key);

public:
    bool isEmpty() const;
    int size();
    int hashFunction(int);
    void insertItem(int, string);
    void removeItem(int);
    string findItem(int);
};

bool HashTable::isEmpty() const
{
    return length == 0;
}

int HashTable::size()
{
    return (int)length;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups;
}

string HashTable::findItem(int key)
{
    auto bItr = findHelper(key);
    if (bItr)
    {
        return bItr->second;
    }

    return "";
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];

    auto bItr = findHelper(key);
    if (bItr)
    {
        bItr->second = value;
    }

    cell.emplace_back(key, value);
    length++;
}

void HashTable::removeItem(int key)
{
    if (length == 0)
        return;

    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = findHelper(key);

    if (bItr && bItr->first != -1)
    {
        cell.remove(*bItr);
        length--;
    }
}

pair<int, string> *HashTable::findHelper(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            break;
        }
    }

    if (bItr != end(cell))
    {
        return &(*bItr);
    }

    return nullptr;
}