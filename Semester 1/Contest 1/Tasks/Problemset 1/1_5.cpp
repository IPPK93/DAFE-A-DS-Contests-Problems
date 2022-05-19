#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset1::Task5
{
    int main()
    {
        int n;
        std :: cin >> n;
        int sqr{0};
        for(int i = 1; i <= n; ++i)
        {
            sqr += i + i - 1;
            std :: cout << sqr << " ";
        }
        return 0;
    }
}
