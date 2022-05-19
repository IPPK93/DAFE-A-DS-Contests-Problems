#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset1::Task2
{
    int main()
    {
        int n;
        std :: cin >> n;
        for(int i = 2; n != 1;)
        {
            if(!(n % i))
            {
                n /= i;
                std :: cout << i << " ";
            }
            else ++i;
        }
        return 0;
    }
}
