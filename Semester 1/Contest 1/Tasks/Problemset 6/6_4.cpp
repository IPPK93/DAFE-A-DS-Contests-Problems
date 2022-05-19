#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset6::Task4
{
    class pair_heap
    {
    public:
        pair_heap(const std :: vector<int>& v)
        : a{v}
        { }

        void push(int val)
        {
            h.push_back(val);
            sift_up(static_cast<unsigned int>(h.size() - 1));
        }
        unsigned int top() const
        {
            return h.front();
        }
        void pop()
        {
            std :: swap(h.front(), h.back());
            h.pop_back();
            sift_down(0);
        }

    private:
        void sift_up(unsigned int i)
        {
            while(i > 0)
            {
                unsigned int p = (i - 1) / 2;
                if(a[h[i]] <= a[h[p]])
                    return;
                std :: swap(h[i], h[p]);
                i = p;
            }
        }

        void sift_down(unsigned int i)
        {
            unsigned int l = 2 * i + 1;
            unsigned int r = l + 1;
            unsigned int mx = i;
            if(r < h.size() && a[h[r]] > a[h[mx]])
                mx = r;
            if(l < h.size() && a[h[l]] > a[h[mx]])
                mx = l;
            if(mx != i)
            {
                std :: swap(h[i], h[mx]);
                sift_down(mx);
            }
        }
        std :: vector<int> h;
        const std :: vector<int>& a;
    };

    int main()
    {
        unsigned int n;
        std :: cin >> n;
        std :: vector<int> a(n);
        for(auto& i : a) std :: cin >> i;
        unsigned int k;
        std :: cin >> k;
        pair_heap hp(a);
        for(unsigned int i = 0; i < k; ++i) hp.push(i);
        std :: cout << a[hp.top()] << " ";
        for(unsigned int l = 1, r = k; r < a.size(); ++l, ++r)
        {
            hp.push(r);
            while(hp.top() < l) hp.pop();
            std :: cout << a[hp.top()] << " ";
        }
        return 0;
    }
}
