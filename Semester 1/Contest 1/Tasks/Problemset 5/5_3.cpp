#include <iostream>
#include <stack>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset5::Task3
{
    // 4 30 30 10 40 20 10 10 40

    using namespace std;

    struct bar
    {
        int x0, x1;
        int h;
    };

    typedef stack< bar, vector<bar> > bstack;

    int main()
    {
        int n;
        cin >> n;
        bstack sq;
        int x{0}, maxS{0};
        for(int i = 0; i < n; ++i)
        {
            int w, h;
            cin >> w >> h;
            while(!sq.empty() && h < sq.top().h)
            {
                int s;
                s = sq.top().h * (x - sq.top().x0);
                if(maxS < s) maxS = s;
                sq.pop();
            }
            bar b;
            b.x0 = (!sq.empty() ? sq.top().x1 : 0);
            b.x1 = x + w;
            b.h = h;
            x += w;
            sq.push(b);
        }
        while(!sq.empty())
        {
            int s;
            s = sq.top().h * (x - sq.top().x0);
            if(maxS < s) maxS = s;
            sq.pop();
        }
        cout << maxS << endl;

        return 0;
    }
}
