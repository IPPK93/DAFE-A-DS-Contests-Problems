#include <iostream>
#include <vector>
#include <stack>
#include "../../first_contest.h"


namespace FirstContest::Problemset5::Task4
{
    struct Token
    {
        enum Type
        {
            EMP, VAL, OP
        };
        Type type;
        int data;
    };

    int priority(const Token& t)
    {
        switch(t.data)
        {
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        }
        return -1;
    }

    std :: istream& operator>>(std :: istream& in, Token& t)
    {
        int nc = in.peek();
        if(nc >= '0' && nc <= '9')
        {
            in >> t.data;
            t.type = Token :: VAL;
        }
        else if(std :: isspace(nc)) t.type = Token :: EMP;
        else
        {
            t.type = Token :: OP;
            t.data = in.get();
        }
        return in;
    }

    std :: ostream& operator<<(std :: ostream& out, const Token& t)
    {
        switch(t.type)
        {
        case Token :: EMP:
            break;
        case Token :: VAL:
            out << t.data;
            break;
        case Token :: OP:
            out << char(t.data);
            break;
        }
        return out;
    }

    typedef std :: vector<Token> Tokens;
    typedef std :: stack<Token, Tokens> TokenStack;

    void calculate(Tokens& pn, TokenStack& pnStack)
    {
        for(unsigned int i = 0; i < pn.size(); ++i)
        {
            if(pn[i].type == Token :: VAL) pnStack.push(pn[i]);
            else
            {
                Token t1 = pnStack.top();
                pnStack.pop();
                Token t0 = pnStack.top();
                pnStack.pop();
                switch(pn[i].data)
                {
                case '+':
                    t0.data += t1.data;
                    break;
                case '-':
                    t0.data -= t1.data;
                    break;
                case '*':
                    t0.data *= t1.data;
                    break;
                case '/':
                    t0.data /= t1.data;
                    break;
                }
                pnStack.push(t0);
            }
        }
    }

    void calc_via_post(TokenStack& pnStack)
    {
        Tokens pn;
        for(Token t; std :: cin >> t && t.type != Token :: EMP;)
        {
            if(t.type == Token :: VAL) pn.push_back(t);
            else switch(t.data)
            {
            case '(':
                pnStack.push(t);
                break;
            case ')':
                while(pnStack.top().data != '(')
                {
                    pn.push_back(pnStack.top());
                    pnStack.pop();
                }
                pnStack.pop();
                break;
            default:
                while(!pnStack.empty() && priority(pnStack.top()) >= priority(t))
                {
                    pn.push_back(pnStack.top());
                    pnStack.pop();
                }
                pnStack.push(t);
                break;
            }
        }
        while(!pnStack.empty())
        {
            pn.push_back(pnStack.top());
            pnStack.pop();
        }
        calculate(pn, pnStack);
        return ;
    }

    int main()
    {
        TokenStack pnStack;
        calc_via_post(pnStack);
        std :: cout << pnStack.top();
        return 0;
    }
}
