#include "cstddef"

template <typename T>
class Queue
{
private:
    size_t cap_q = 0;
    size_t head = 0; // location of first element
    size_t tail = 0;
    T *data_q = nullptr;
    void allocate(size_t);

public:
    Queue();
    Queue(const Queue &);
    Queue<T> &operator=(const Queue &);
    ~Queue();

    void pop();
    T top();
    bool empty() const;
    size_t size() const;
    void printStack() const;
    void push(T);
};

template <typename T>
void Queue<T>::allocate(size_t cap)
{
    size_t n = tail - head;
    T *new_data = new T[cap];
    for (size_t i = 0; i < n; i++)
    {
        new_data[i] = data_q[head + i];
    }

    delete[] data_q;
    cap_q = cap;
    data_q = new_data;
    head = 0;
    tail = n;
}

template <typename T>
Queue<T>::Queue()
{
    allocate(10);
}

template <typename T>
Queue<T>::Queue(const Queue &qu)
{
    size_t n = qu.tail - qu.head;
    T *new_data = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        new_data[i] = qu.data_q[qu.head + i];
    }

    cap_q = qu.cap_q;
    data_q = new_data;
    head = 0;
    tail = n;
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &qu)
{
    if (this != &qu)
    {
        size_t n = qu.tail - qu.head;
        T *new_data = new T[n];
        for (size_t i = 0; i < n; i++)
        {
            new_data[i] = qu.data_q[qu.head + i];
        }

        delete[] data_q;
        cap_q = qu.cap_q;
        data_q = new_data;
        head = 0;
        tail = n;
    }

    return *this;
}

template <typename T>
void Queue<T>::pop()
{
    if (head == tail)
        return;
    head++;
}

template <typename T>
T Queue<T>::top()
{
    if ((tail - head) == 0)
        T{};
    return data_q[head];
}

template <typename T>
void Queue<T>::push(T item)
{
    if (tail == cap_q)
    {
        allocate(cap_q == 0 ? 10 : 2 * cap_q);
    }
    data_q[tail] = item;
    tail++;
}

template <typename T>
size_t Queue<T>::size() const
{
    return tail - head;
}

template <typename T>
bool Queue<T>::empty() const
{
    return (tail - head) == 0;
}

template <typename T>
void Queue<T>::printStack() const
{
    std::cout << "[PRINT START]" << std::endl;
    for (size_t i = head; i < tail; i++)
    {
        std::cout << "[Stack Value] = " << data_q[i] << std::endl;
    }
    std::cout << "[PRINT END]" << std::endl;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] data_q;
}
