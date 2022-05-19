#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset1::Task1
{
    int main()
    {
        int n;
        std :: cin >> n;
        int sum = n/5 + n/25 + n/125 + n/625;
        std :: cout << sum;
        return 0;
    }
}
