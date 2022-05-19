#include <iostream>
#include <vector>
#include "../../first_contest.h"


namespace FirstContest::Problemset2::Task1
{
    using namespace std;

    int main()
    {
        int n;
        cin >> n;
        int elem;
        vector <int> A;
        vector <int> B;
        for (int i = 0; i < n; ++i)
        {
            cin >> elem;
            A.push_back(elem);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> elem;
            B.push_back(elem);
        }
        int max = A[0];
        int ind = 0;
        vector <int> maxi;
        vector <int> ind_elem;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > max)
            {
                max = A[i];
                ind = i;
            }
            maxi.push_back(max);
            ind_elem.push_back(ind);
        }

        int sum = A[0] + B[0];
        int in_A = 0;
        int in_B = 0;

        for (int i = 0; i <= n; ++i)
        {
            if (B[i] + maxi[i] > sum)
            {
                sum = B[i] + maxi[i];
                in_B = i;
                in_A = ind_elem[i];
            }
        }
        cout << in_A << ' ' << in_B;
        return 0;
    }
}
