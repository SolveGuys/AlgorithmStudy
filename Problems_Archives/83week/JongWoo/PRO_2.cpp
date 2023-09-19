#include <vector>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    long long st = 1, en = 1e18;

    while (st <= en)
    {
        long long md = (st + en) / 2;
        long long cnt = 0;

        for (int t : times)
        {
            cnt += md / t;
            
            if (cnt >= n)
            {
                break;
            }
        }

        if (cnt >= n)
        {
            answer = md;
            en = md - 1;
        }
        else
        {
            st = md + 1;
        }
    }

    return answer;
}
