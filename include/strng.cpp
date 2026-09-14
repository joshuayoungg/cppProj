#pragma once

#include <cstddef>
#include <iostream>

class Strng
{
private:
    size_t s_size = 0;
    size_t s_cap = 0;
    char *data = nullptr;
    void allocate(size_t cap);
    void allocate_copy(const Strng &strng);
    Strng(char *, size_t cap, size_t size);

public:
    Strng();
    Strng(const Strng &strng);
    ~Strng();
    size_t size() const;
    bool empty() const;
    void push_back(const char c);
    int removeIndex(unsigned int index);
    int insert(unsigned int index, const char c);
    Strng &operator=(const Strng &strng);
    Strng &operator=(const char *);
    Strng &operator+=(const Strng &strng);
    Strng &operator+=(const char *);
    char &operator[](size_t index);
    const char &operator[](size_t index) const;
    Strng operator+(const char *ndata) const;
    Strng operator+(const Strng &strng) const;

    void printStrng() const;
};

void Strng::allocate(size_t cap)
{
    char *new_data = new char[cap];
    for (size_t i = 0; i < s_size; i++)
    {
        new_data[i] = data[i];
    }

    delete[] data;
    s_cap = cap;
    data = new_data;
}

void Strng::allocate_copy(const Strng &strng)
{
    char *new_data = new char[strng.s_cap];
    for (size_t i = 0; i < strng.s_size; i++)
    {
        new_data[i] = strng.data[i];
    }

    delete[] data;
    s_cap = strng.s_cap;
    s_size = strng.s_size;
    data = new_data;
}

Strng::Strng()
{
    allocate(10);
}

Strng::Strng(const Strng &strng)
{
    allocate_copy(strng);
}

Strng::Strng(char *ndata, size_t ncap, size_t nsize)
{
    data = ndata;
    s_cap = ncap;
    s_size = nsize;
}

void Strng::push_back(const char c)
{
    if (s_size == s_cap)
    {
        allocate(s_cap == 0 ? 10 : 2 * s_cap);
    }

    data[s_size] = c;
    s_size++;
}

int Strng::insert(unsigned int index, const char c)
{
    if (index > s_size)
        return -1;

    if (s_size == s_cap)
    {
        allocate(s_cap == 0 ? 10 : 2 * s_cap);
    }

    for (size_t i = s_size; i > index; i--)
    {
        data[i] = data[i - 1];
    }

    // found the index location
    data[index] = c;
    s_size++;
    return 1;
}

int Strng::removeIndex(unsigned int index)
{
    if (index >= s_size)
        return -1;

    for (size_t i = index; i + 1 < s_size; i++)
    {
        data[i] = data[i + 1];
    }

    s_size--;
    return 1;
}

Strng &Strng::operator=(const Strng &strng)
{
    if (this != &strng)
    {
        allocate_copy(strng);
    }

    return *this;
}

Strng &Strng::operator=(const char *ndata)
{
    const char *first = ndata;
    size_t counter = 0;
    while (*first)
    {
        ++first;
        ++counter;
    }

    if (s_cap <= counter)
    {
        allocate(2 * (s_cap + counter));
    }

    for (size_t i = 0; i < counter; i++)
    {
        data[i] = ndata[i];
    }
    s_size = counter;
    return *this;
}

Strng Strng::operator+(const Strng &strng) const
{
    size_t ncap = 2 * (s_size + strng.s_size);
    char *new_data = new char[ncap];
    size_t nsize = 0;
    for (size_t i = 0; i < s_size; i++)
    {
        new_data[i] = data[i];
        nsize++;
    }
    size_t tmpSize = nsize;
    for (size_t i = 0; i < strng.s_size; i++)
    {
        new_data[tmpSize + i] = strng.data[i];
        nsize++;
    }

    return Strng(new_data, ncap, nsize);
}

Strng Strng::operator+(const char *ndata) const
{
    const char *first = ndata;
    size_t counter = 0;
    while (*first)
    {
        ++first;
        ++counter;
    }

    size_t ncap = 2 * (s_cap + counter);
    char *narr = new char[ncap];

    for (size_t i = 0; i < s_size; i++)
    {
        narr[i] = data[i];
    }

    size_t nsize = s_size;
    for (size_t i = 0; i < counter; i++)
    {
        narr[s_size + i] = ndata[i];
        nsize++;
    }

    return Strng(narr, ncap, nsize);
}

Strng &Strng::operator+=(const Strng &other)
{
    *this = *this + other;
    return *this;
}

Strng &Strng::operator+=(const char *ndata)
{
    *this = *this + ndata;
    return *this;
}

char &Strng::operator[](size_t index)
{
    return data[index];
}

const char &Strng::operator[](size_t index) const
{
    return data[index];
}

size_t Strng::size() const
{
    return s_size;
}

bool Strng::empty() const
{
    return s_size == 0;
}

Strng::~Strng()
{
    delete[] data;
}

inline std::ostream &operator<<(std::ostream &os, const Strng &s)
{
    for (size_t i = 0; i < s.size(); i++)
        os << s[i];
    return os;
}