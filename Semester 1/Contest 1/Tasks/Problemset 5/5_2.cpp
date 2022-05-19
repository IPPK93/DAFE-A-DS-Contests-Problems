#include <iostream>
#include <stack>
#include <string>
#include "../../first_contest.h"


namespace FirstContest::Problemset5::Task2
{
    int main()
    {
        std :: string s1, s2;
        std :: cin >> s1 >> s2;
        std :: stack<char> stac;
        int i{0}, j{0};
        while(i < s1.size())
        {
            stac.push(s1[i]);
            while(!stac.empty() && j < s2.size() && stac.top() == s2[j])
            {
                stac.pop();
                ++j;
            }
            ++i;
        }
        std :: cout << (stac.empty() ? "YES" : "NO") << '\n';
        return 0;
    }
}
