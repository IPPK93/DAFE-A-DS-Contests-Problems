#include <iostream>
#include <vector>
#include <algorithm>
#include "../../first_contest.h"


namespace FirstContest::Problemset3::Task2
{
    // TODO: Change to O(log m) version.

    int main()
    {
        unsigned int n;
        std :: cin >> n;
        std :: vector<int> a(n);
        for(auto& i : a) std :: cin >> i;
        std :: cout <<
        std::distance(std::begin(a), std::max_element(std::begin(a), std::end(a),
            [](const int& lhs, const int& rhs) {return std::make_pair(lhs, &lhs) < std::make_pair(rhs, &rhs);}));

        return 0;
    }
}
