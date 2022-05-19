#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset2::Task4
{
    int joseph(int n, int k)
    {
        return ((n == 1) ? 1 : (1 + ((joseph(n-1, k) + k - 1) % n)));
    }

    int main()
    {
        int n;
        std :: cin >> n;
        int k;
        std :: cin >> k;
        std :: cout << joseph(n, k) << '\n';
        return 0;
    }
}
