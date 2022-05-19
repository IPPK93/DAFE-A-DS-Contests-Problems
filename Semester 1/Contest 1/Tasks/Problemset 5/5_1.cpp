#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include "../../first_contest.h"


namespace FirstContest::Problemset5::Task1
{
    char opposite(const char& ch)
    {
        switch (ch)
        {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
        case '(': return ')';
        case '{': return '}';
        case '[': return ']';
        default: throw std::invalid_argument("Given char is not allowed.\n");
        }
    }

    int main()
    {
        std :: stack<char> st;
        std :: string s;
        std :: cin >> s;
        for(unsigned i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case '(': case '{': case '[':
                st.push(s[i]);
                break;
            case ')': case '}': case ']':
                if(st.empty()) st.push(s[i]);
                else if (st.top() == ')' || st.top() == '}' || st.top() == ']') st.push(s[i]);
                else if(s[i] == opposite(st.top())) st.pop();
                else
                {
                    std :: cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
        std :: string left, right;
        while(!st.empty())
        {
            switch (st.top())
            {
            case '(': case '{': case '[':
                right.push_back(opposite(st.top()));
                st.pop();
                break;
            case ')': case '}': case ']':
                left.push_back(opposite(st.top()));
                st.pop();
            }
        }
        std :: cout << left + s + right << std :: endl;
        return 0;
    }
}
