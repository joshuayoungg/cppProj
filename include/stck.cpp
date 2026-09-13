#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class Stck
{
private:
    size_t s_size = 0;
    size_t s_cap = 0;
    T *s_data = nullptr;
    void allocate(size_t cap);
    void allocate_copy(const Stck &);

public:
    Stck();
    Stck(const Stck &);
    ~Stck();
    Stck &operator=(const Stck &);
    T top() const;
    void pop();
    void push(T);
    bool empty() const;
    void printStack() const;
    size_t size() const;
};

template <typename T>
size_t Stck<T>::size() const
{
    return s_size;
}

template <typename T>
void Stck<T>::allocate(size_t cap)
{
    T *new_data = new T[cap];
    for (size_t i = 0; i < s_size; i++)
    {
        new_data[i] = s_data[i];
    }

    delete[] s_data;
    s_data = new_data;
    s_cap = cap;
}

template <typename T>
Stck<T>::Stck()
{
    allocate(10);
}

template <typename T>
void Stck<T>::allocate_copy(const Stck &stck)
{
    T *new_data = new T[stck.s_cap];
    for (size_t i = 0; i < stck.s_cap; i++)
    {
        new_data[i] = stck.s_data[i];
    }
    s_data = new_data;
    s_size = stck.s_size;
    s_cap = stck.s_cap;
}

template <typename T>
Stck<T>::Stck(const Stck &stck)
{
    allocate_copy(stck);
}

template <typename T>
void Stck<T>::pop()
{
    if (s_size == 0)
        return;
    s_size--;
}

template <typename T>
T Stck<T>::top() const
{
    if (s_size == 0)
        return T{};

    return s_data[s_size - 1];
}

template <typename T>
bool Stck<T>::empty() const
{
    return s_size == 0;
}

template <typename T>
Stck<T> &Stck<T>::operator=(const Stck &stck)
{
    if (this != &stck)
    {
        delete[] s_data;
        allocate_copy(stck);
    }
    return *this;
}

template <typename T>
void Stck<T>::push(T item)
{
    if (s_size == s_cap)
    {
        allocate(s_cap == 0 ? 10 : 2 * s_cap);
    }

    s_data[s_size] = item;
    s_size++;
}

template <typename T>
void Stck<T>::printStack() const
{
    std::cout << "[PRINT START]" << std::endl;
    for (size_t i = 0; i < s_size; i++)
    {
        std::cout << "[Stack Value] = " << s_data[i] << std::endl;
    }
    std::cout << "[PRINT END]" << std::endl;
}

template <typename T>
Stck<T>::~Stck()
{
    delete[] s_data;
}