#pragma once
#include <cstddef>
#include <cstdint>

struct Order
{
    uint64_t id = 0;
    uint32_t qty = 0;
    Order *prev = nullptr;
    Order *next = nullptr;
};

class List
{
    Order *head_ = nullptr;
    Order *tail_ = nullptr;
    size_t count_ = 0;

public:
    void push_back(Order *o)
    {
        count_++;
        o->prev = nullptr;
        o->next = nullptr;
        if (head_ == nullptr)
        {
            head_ = tail_ = o;
            return;
        }
        tail_->next = o;
        tail_->next->prev = tail_;
        tail_ = tail_->next;
    };
    void unlink(Order *o)
    {
        if (o->prev)
            o->prev->next = o->next;
        else
            head_ = o->next;
        if (o->next)
            o->next->prev = o->prev;
        else
            tail_ = o->prev;
        o->prev = o->next = nullptr;
        count_--;
    };
    Order *pop_front()
    {
        if (count_ == 0)
            return nullptr;

        Order *front = head_;
        if (count_ == 1)
        {
            head_ = tail_ = nullptr;
        }
        else
        {
            head_ = head_->next;
            head_->prev = nullptr;
        }
        count_--;
        return front;
    };
    Order *front() const
    {
        return head_;
    };
    bool empty() const
    {
        return count_ == 0;
    };
    size_t size() const
    {
        return count_;
    };
};