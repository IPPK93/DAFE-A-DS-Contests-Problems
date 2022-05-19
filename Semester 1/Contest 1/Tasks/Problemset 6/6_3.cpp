#include <fstream>
#include <vector>
#include <algorithm>
#include "../../first_contest.h"


namespace FirstContest::Problemset6::Task3
{
    int main()
    {
        int n;
        std :: ifstream ifs{"input.txt"};
        ifs >> n;
        std :: vector<int> arr_t(n);
        std :: vector<int> dep_t(n);
        for(int i = 0; i < n; ++i) ifs >> arr_t[i] >> dep_t[i];
        std :: sort(dep_t.begin(), dep_t.end());
        int platf{1}, minplatf{1};
        for(int i = 1, j = 0; i < n && j < n;)
        {
            if(arr_t[i] <= dep_t[j])
            {
                ++platf;
                ++i;
                if(minplatf < platf) minplatf = platf;
            }
            else
            {
                --platf;
                ++j;
            }
        }
        std :: ofstream ofs{"output.txt"};
        ofs << minplatf;
        return 0;
    }
}
