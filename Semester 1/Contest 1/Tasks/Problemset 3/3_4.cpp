#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset3::Task4
{
    int Abs(int a)
    {
        return a < 0 ? -a : a;
    }

    size_t find_min(const std :: vector<int>& a, int elem)
    {
        size_t l{0}, r{1};
        if(a.front() >= elem) return 0;
        if(a.back() < elem) return a.size() - 1;
        if(a.back() == elem)
        {
            size_t i = a.size() - 1;
            while(a[i] == elem) --i;
            return ++i;
        }
        while(a[r] < elem)
        {
            l = r;
            r = (2*r < a.size() ? 2*r : a.size() - 1);
        }
        while(r - l > 1)
        {
            size_t mid = l + (r - l)/2;
            if(a[mid] < elem) l = mid;
            else if(a[mid] >= elem)
            {
                while(!(a[mid] >= elem && a[mid-1] < elem)) --mid;
                return ((Abs(a[mid] - elem) < Abs(a[mid - 1] - elem)) ? mid : --mid);
            }
        }
        if(Abs(a[r] - elem) < Abs(a[l] - elem)) return r;
        else return l;
    }

    int main()
    {
        size_t n;
        std :: cin >> n;
        std :: vector<int> a(n);
        for(auto& i : a) std :: cin >> i;
        size_t m;
        std :: cin >> m;
        std :: vector<int> b(m);
        for(auto& i : b) std :: cin >> i;
        for(size_t i = 0; i < b.size(); ++i) std :: cout << find_min(a, b[i]) << ' ';
        return 0;
    }
}
