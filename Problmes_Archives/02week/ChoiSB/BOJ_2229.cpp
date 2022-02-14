#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'
using namespace std;

int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; //  N(1≤N≤1,000)
    cin >> N;
    vector<int>arr(N);
    vector<int>dp(N);
    for (int& n : arr)
    {
        cin >> n;
    }

    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    int minval = min(arr[0], arr[1]);
    int maxval = max(arr[0], arr[1]);
            
    for (int i = 2; i < N; ++i)
    {
        int a = dp[i - 1];
        if (maxval < arr[i])
        {
            a += (arr[i] - maxval);
        }
        else if (minval > arr[i])
        {
            a += (minval - arr[i]);
        }
        int b = dp[i - 2] + abs(arr[i - 1] - arr[i]);

        if (a > b)
        {
            dp[i] = a;
            if (maxval < arr[i])
            {
                maxval = arr[i];
            }
            else if (minval > arr[i])
            {
                minval = arr[i];
            }
        }
        else
        {
            dp[i] = b;
            minval = min(arr[i - 1], arr[i]);
            maxval = max(arr[i - 1], arr[i]);
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}