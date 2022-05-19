#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset4::Task1
{
    template <typename T>
    class que
    {
    public:
        que()
        : size_{0}, elem{nullptr}, front_{0}, back_{-1}, capacity_{0}
        { }
        que(int newalloc)
        : size_{0}, elem{new T[newalloc]}, front_{0}, back_{-1}, capacity_{newalloc}
        { }

        ~que()
        {
            if(elem) delete[] elem;
        }

        int size()
        {
            return size_;
        }
        T& front()
        {
            return elem[front_];
        }
        T& back()
        {
            return elem[back_];
        }
        int capacity()
        {
            return capacity_;
        }
        bool empty()
        {
            return size_ == 0 ? true : false;
        }

        void reserve(int newalloc)
        {
            if(newalloc <= capacity_) return ;
            T* newelem = new T[static_cast<unsigned>(newalloc)];
            if(size_ != 0)
            {
                newelem[0] = elem[front_];
                for(int i = 1; front_ != back_; ++i)
                {
                    if(++front_ == capacity_) front_ = 0;
                    newelem[i] = elem[front_];
                }
                newelem[size_ - 1] = elem[back_];
                delete[] elem;
            }
            front_ = 0;
            back_ = size_ - 1;
            elem = newelem;
            capacity_ = newalloc;
        }

        void push_back(const T& el)
        {
            if(capacity_ == 0) reserve(8);
            else if(size_ == capacity_) reserve(2*capacity_);
            if(++back_ == capacity_) back_ = 0;
            elem[back_] = el;
            ++size_;
        }

        void pop_front()
        {
            if(empty()) return ;
            if(++front_ == capacity_) front_ = 0;
            --size_;
        }

    private:
        int size_; //number of elements
        T* elem;
        int front_; // front elem idx
        int back_; // back elem idx
        int capacity_; //allocated memory amount
    };

    int main()
    {
        int n;
        std :: cin >> n;
        que<int> q;
        for(int a, b, i = 0; i < n; ++i)
        {
            std :: cin >> a >> b;
            if(a == 2)
            {
                if((q.empty() && b != -1) || (!q.empty() && q.front() != b))
                {
                    std :: cout << "NO" << '\n';
                    return 0;
                }
                q.pop_front();
            }
            else if(a == 3) q.push_back(b);
        }
        std :: cout << "YES" << '\n';
        return 0;
    }
}
