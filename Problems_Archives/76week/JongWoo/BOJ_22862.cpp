#include <iostream>

using namespace std;

int n, k;
int arr[1'000'000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int answer = 0;
    int en = 0;
    int oddCnt = 0;

    for (int st = 0; st < n; ++st)
    {
        while ((en < n) && (oddCnt < k))
        {
            if (arr[en] % 2 == 1)
            {
                ++oddCnt;
            }

            ++en;
        }

        while ((en < n) && (arr[en] % 2 == 0))
        {
            ++en;
        }

        answer = max(answer, en - st - oddCnt);

        if (arr[st] % 2 == 1)
        {
            --oddCnt;
        }
    }

    cout << answer << '\n';
}
