#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset1::Task4
{
    int main()
    {
        int n;
        std :: cin >> n;
        int a{0};
        for(int i = 2; ; ++i)
        {
            if (n % i == 0)
            {
                a = n/i;
                break;
            }
        }
        int b = n - a;
        std :: cout << a << " " << b << std :: endl;
        return 0;
    }
}
