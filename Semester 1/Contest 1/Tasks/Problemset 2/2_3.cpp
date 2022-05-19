#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset2::Task3
{
    int main()
    {
        unsigned n;
        std :: cin >> n;
        std :: vector<int> a(n);
        for(unsigned i = 0; i < a.size(); ++i) std :: cin >> a[i];
        unsigned m;
        std :: cin >> m;
        std :: vector<int> b(m);
        for (unsigned i = 0; i < b.size(); ++i) std :: cin >> b[i];
        int k, count{0};
        std :: cin >> k;
        for (int i = 0, j = int(b.size() - 1);;)
        {
            if(a[i] + b[j] < k) ++i;
            else if(a[i] + b[j] > k) --j;
            else
            {
                ++i;
                --j;
                ++count;
            }
            if(i == a.size() || j == -1) break;
        }
        std :: cout << count << std :: endl;

        return 0;
    }
}
