#pragma once
#include <cstddef>

template <typename T>
class Vec
{
private:
    T *v_data = nullptr;
    size_t v_size = 0;
    size_t v_capacity = 0;
    void reallocate(size_t new_cap)
    {
        T *new_data = new T[new_cap];
        for (size_t i = 0; i < v_size; i++)
        {
            new_data[i] = v_data[i];
        }
        delete[] v_data;
        v_data = new_data;
        v_capacity = new_cap;
    }

public:
    Vec()
    {
        reallocate(2);
    }

    Vec(const Vec &vect)
    {
        v_size = vect.v_size;
        v_capacity = vect.v_capacity;
        v_data = new T[vect.v_capacity];
        for (size_t i = 0; i < v_size; i++)
        {
            v_data[i] = vect.v_data[i];
        }
    }
    ~Vec()
    {
        delete[] v_data;
    }

    void reserve(size_t new_cap)
    {
        if (new_cap <= v_capacity)
            return;
        reallocate(new_cap);
    }

    void push_back(const T &value)
    {
        if (v_size == v_capacity)
        {
            T tmp = value; // edge case where you copy from the same vector and it needs to resize, but that causes reallocation
            reallocate(v_capacity * 2);
            v_data[v_size] = tmp;
            v_size++;
            return;
        }
        v_data[v_size] = value;
        v_size++;
    }
    void pop_back()
    {
        if (v_size == 0)
        {
            return;
        }

        v_size--;
    }
    void clear()
    {
        v_size = 0;
    }
    size_t size() const
    {
        return v_size;
    }
    size_t capacity() const
    {
        return v_capacity;
    }
    bool empty() const
    {
        return v_size == 0;
    }

    // operators
    Vec &operator=(const Vec &vect)
    {
        if (this != &vect)
        {
            T *new_data = new T[vect.v_capacity];
            for (size_t i = 0; i < vect.v_size; i++)
            {
                new_data[i] = vect.v_data[i];
            }
            delete[] v_data;
            v_data = new_data;
            v_capacity = vect.v_capacity;
            v_size = vect.v_size;
        }

        return *this;
    }

    T &operator[](size_t index)
    {
        return v_data[index];
    }

    const T &operator[](size_t index) const
    {
        return v_data[index];
    }
};