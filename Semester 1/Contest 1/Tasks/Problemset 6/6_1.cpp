#include <iostream>
#include <vector>
#include <algorithm>
#include "../../first_contest.h"


namespace FirstContest::Problemset6::Task1
{
    template <typename T>
    class Heap
    {
    public:

        void push(const T& el)
        {
            elem.push_back(el);
            sift_up(elem.size() - 1);
            return ;
        }

        T& front()
        {
            return elem.front();
        }

        T& back()
        {
            return elem.back();
        }

        int size()
        {
            return elem.size();
        }
        void pop()
        {
            if(!elem.empty()) elem.pop_back();
            return ;
        }

        bool empty()
        {
            return elem.empty();
        }

        T get_max()
        {
            T max = elem.front();
            std :: swap(elem.front(), elem.back());
            pop();
            sift_down(0);
            return max;
        }

    private:
        std :: vector<T> elem;

        void sift_up(int n)
        {
            while(n != 0 && elem[(n-1)/2] < elem[n])
            {
                std :: swap(elem[(n-1)/2], elem[n]);
                n = (n-1)/2;
            }
            return ;
        }

        void sift_down(unsigned int i)
        {
            unsigned int l = 2 * i + 1;
            unsigned int r = l + 1;
            unsigned int mx = i;
            if(r < elem.size() && elem[r] > elem[mx])
                mx = r;
            if(l < elem.size() && elem[l] > elem[mx])
                mx = l;
            if(mx != i)
            {
                std :: swap(elem[i], elem[mx]);
                sift_down(mx);
            }
        }
    };

    int main()
    {
        int n;
        std :: cin >> n;
        Heap<int> hp;
        while(hp.size() != n)
        {
            int el;
            std :: cin >> el;
            hp.push(el);
        }
        int k;
        std :: cin >> k;
        int i{0};
        while(!hp.empty())
        {
            int sum{0};
            std :: vector<int> temp_elems;
            while(!hp.empty() && sum + hp.front() <= k)
            {
                int temp = hp.get_max();
                if(temp != 1) temp_elems.push_back(temp/2);
                sum += temp;
            }
            while(!temp_elems.empty())
            {
                hp.push(temp_elems.back());
                temp_elems.pop_back();
            }
            ++i;
        }
        std :: cout << i << '\n';
        return 0;
    }
}
