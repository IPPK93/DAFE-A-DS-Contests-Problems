#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset3::Task1
{
    int bin(const std :: vector<int>& a, int elem, int l, int r)
    {
        while(r - l > 0)
        {
            if(a[r] >= elem && a[r-1] < elem) return r;
            else
            {
                int mid = l + (r - l)/2;
                if(a[mid] < elem) l = mid;
                else if(a[mid] >= elem && a[mid - 1] < elem) return mid;
                else r = mid;
            }
        }
        return r;
    }

    int finda_(const std :: vector<int>& a, int elem)
    {
        int l = 1;
        int r = 2;
        while(a[r] < elem)
        {
            l = r + 1;
            2*r < int(a.size()) ? r *= 2 : r = int(a.size() - 1);
        }
        return bin(a, elem, l, r);
    }

    int main()
    {
        unsigned n, m;
        std :: cin >> n >> m;
        std :: vector<int> a(n), b(m);
        for(auto& i : a) std :: cin >> i;
        for(auto& j : b) std :: cin >> j;
        for(unsigned i = 0; i < b.size(); ++i)
        {
            if(a.front() >= b[i]) std :: cout << 0 << " ";
            else if(a.back() < b[i]) std :: cout << n << " ";
            else std :: cout << finda_(a, b[i]) << " ";
        }
        std :: cout << '\n';
        return 0;
    }
}
