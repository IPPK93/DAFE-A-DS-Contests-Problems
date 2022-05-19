#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset1::Task6
{
    int main()
    {
        unsigned n;
        std :: cin >> n;
        std :: vector<int> a(n);
        for(unsigned i = 0; i < a.size(); ++i) std :: cin >> a[i];
        for(unsigned i = 0; i < a.size()/2; ++i)
        {
            int tmp = a[i];
            a[i] = a[a.size() - 1 - i];
            a[a.size() - 1 - i] = tmp;
        }
        for(unsigned i = 0; i < a.size(); ++i) std :: cout << a[i] << " ";
        return 0;
    }
}
