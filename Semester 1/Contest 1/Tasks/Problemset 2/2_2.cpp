#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset2::Task2
{
    int Abs(int a)
    {
        return a < 0 ? -a : a;
    }

    int main()
    {
        std :: ios_base :: sync_with_stdio(false);
        unsigned int n;
        std :: cin >> n;
        std :: vector<std :: pair<int, int>> vert(n);
        for(unsigned int i = 0; i < n; ++i)
        {
            std :: cin >> vert[i].first >> vert[i].second;
        }
        double area{0};
        for(unsigned int i = 0; i <= n - 3; ++i)
        {
            area += 0.5 * Abs((vert[i+1].first - vert[0].first)*(vert[i+2].second - vert[0].second)
            - (vert[i+2].first - vert[0].first)*(vert[i+1].second-vert[0].second));
        }
        std :: cout << area;
        return 0;
    }
}
