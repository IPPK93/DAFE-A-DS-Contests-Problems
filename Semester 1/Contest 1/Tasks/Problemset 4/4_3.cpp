#include <iostream>
#include <vector>
#include <stack>
#include "../../first_contest.h"


namespace FirstContest::Problemset4::Task3
{
    typedef std :: stack<int, std :: vector<int>> d_stack;

    int main()
    {
        unsigned int n;
        std :: cin >> n;
        d_stack first, second;
        for(int a, b, i = 0; i < n; ++i)
        {
            std :: cin >> a >> b;
            if(a == 2)
            {
                if(first.empty() && second.empty() && b != -1)
                {
                    std :: cout << "NO" << '\n';
                    return 0;
                }
                else if(!second.empty())
                {
                    if(b != second.top())
                    {
                        std :: cout << "NO" << '\n';
                        return 0;
                    }
                    second.pop();
                }
                else if(!first.empty())
                {
                    while(!first.empty())
                    {
                        second.push(first.top());
                        first.pop();
                    }
                    if(b != second.top())
                    {
                        std :: cout << "NO" << '\n';
                        return 0;
                    }
                    second.pop();
                }
            }
            else if(a == 3) first.push(b);
        }
        std :: cout << "YES" << '\n';
        return 0;
    }
}
