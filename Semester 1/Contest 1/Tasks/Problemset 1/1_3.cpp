#include <iostream>
#include "../../first_contest.h"


namespace FirstContest::Problemset1::Task3
{
    class Zero {};

    int gcd(int a, int b)
    {
        if(a == 0 && b == 0) throw Zero();
        if(a == 0 || b == 0) return (a == 0 ? b : a);
        while(a != b) ((a > b) ? (a -= b) : (b -= a));
        return a;
    }

    int main()
    try
    {
        int a, b, c, d;
        std :: cin >> a >> b >> c >> d;
        int m = ((a*d)+(b*c))/gcd(a*d+b*c, b*d);
        int n = b*d/gcd(a*d+b*c, b*d);
        std :: cout << m << " " << n << std :: endl;
        return 0;
    }
    catch (Zero)
    {
        std :: cerr << "0/0 does not exist" << std :: endl;
        return -1;
    }
}
