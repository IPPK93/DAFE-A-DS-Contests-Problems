#include <iostream>
#include <vector>
#include <algorithm>
#include "../../first_contest.h"


namespace FirstContest::Problemset6::Task2
{
    int main()
    {
        int n;
        std :: cin >> n;
        std :: vector<int> v(n);
        for(auto& i : v) std :: cin >> i;
        int sum{0};
        if(v.size() <= 2) for(auto& i : v) sum += i;
        else
        {
            for(int i = 1; i < v.size(); ++i)
            {
                std :: sort(v.begin(), v.end());
                int temp_sum = v[i - 1] + v[i];
                v.erase(v.begin() + i - 1, v.begin() + i);
                sum += temp_sum;
                v.push_back(temp_sum);
            }
        }
        std :: cout << sum << '\n';
        return 0;
    }
}
