#pragma once

using namespace std;

template <typename T>
class Vec2
{
private:
    size_t v_size = 0;
    size_t v_cap = 0;
    T *v_data = nullptr;
    void allocate(int);

public:
    Vec2();
    Vec2(const Vec2 &);
    ~Vec2();
    void push_back(T);
    void pop_back();
    void printVec();
    void removeIndex(unsigned int);
    T &operator[](int);
    Vec2 &operator=(const Vec2 &);
};

template <typename T>
Vec2<T>::Vec2()
{
    allocate(10);
}

template <typename T>
Vec2<T>::Vec2(const Vec2 &vect)
{
    T *new_data = new T[vect.v_cap];
    for (size_t i = 0; i < vect.v_cap; i++)
    {
        new_data[i] = vect.v_data[i];
    }

    v_data = new_data;
    v_cap = vect.v_cap;
    v_size = vect.v_size;
}

template <typename T>
Vec2<T>::~Vec2()
{
    delete[] v_data;
}

template <typename T>
void Vec2<T>::allocate(int capacity)
{
    size_t t_cap = capacity + v_cap;
    T *new_data = new T[t_cap];
    for (size_t i = 0; i < v_cap; i++)
    {
        new_data[i] = v_data[i];
    }

    delete[] v_data;
    v_data = new_data;
    v_cap = t_cap;
}

template <typename T>
void Vec2<T>::push_back(T item)
{
    if (v_size == v_cap)
    {
        allocate(v_cap == 0 ? 10 : 2 * v_cap);
    }
    v_data[v_size] = item;
    ++v_size;
}

template <typename T>
void Vec2<T>::pop_back()
{
    if (v_size > 0)
        v_size--;
}

template <typename T>
void Vec2<T>::printVec()
{
    cout << "[Print Start]" << endl;
    for (size_t i = 0; i < v_size; i++)
    {
        cout << "[Item]: " << v_data[i] << endl;
    }
    cout << "[Print End]" << endl;
}

template <typename T>
void Vec2<T>::removeIndex(unsigned int index)
{
    while (index + 1 < v_size)
    {
        v_data[index] = v_data[index + 1];
        index++;
    }

    if (v_size > 0)
        v_size--;
}

template <typename T>
T &Vec2<T>::operator[](int index)
{
    return v_data[index];
}

template <typename T>
Vec2<T> &Vec2<T>::operator=(const Vec2 &vect)
{
    if (this != vect)
    {
        T *new_data = new T[vect.v_cap];
        for (size_t i = 0; i < vect.v_cap; i++)
        {
            new_data[i] = vect.v_data[i];
        }

        delete[] v_data;
        v_data = new_data;
        v_cap = vect.v_cap;
        v_size = vect.v_size;
    }
    return *this;
}
