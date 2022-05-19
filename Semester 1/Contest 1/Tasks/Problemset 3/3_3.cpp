#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset3::Task3
{
    void find_intersection(const std :: vector<int>& a, int elem, int& l, int& r)
    {
        if(a.front() == elem)
        {
            std :: cout << elem << ' ';
            return ;
        }
        if(a.front() > elem || a.back() < elem) return ;
        while(a[r] < elem)
        {
            l = r;
            r = (2*r < a.size() ? 2*r : a.size() - 1);
        }
        while(r - l > 1)
        {
            int mid = l + (r-l)/2;
            if(a[mid] < elem) l = mid;
            else if(a[mid] > elem) r = mid;
            else
            {
                std :: cout << elem << ' ';
                return ;
            }
        }
        if(a[l] == elem || a[r] == elem) std :: cout << elem << ' ';
        return ;
    }

    int main()
    {
        unsigned int n, m;
        std :: cin >> n >> m;
        std :: vector<int> a(n), b(m);
        for(auto& i : a) std :: cin >> i;
        for(auto& j : b) std :: cin >> j;
        int l{0}, r{1};
        for(int i = 0; i < m; ++i)
            find_intersection(a, b[i], l, r);
        return 0;
    }
}
