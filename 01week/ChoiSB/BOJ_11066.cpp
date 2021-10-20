#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
constexpr int INF = 987'654'321;
vector<int> arr;
// dp[pos][size] : pos 위치에서 size 개수로 묶은 경우 최솟값
vector<vector<int>> dp;
int N;

void solve()
{
    cin >> N;

    arr.resize(N + 1,0);
    dp.resize(N + 1);
    for (int i = 1; i < N + 1; ++i)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i < N + 1; ++i)
    {
        dp[i].resize(N + 1, INF);
    }
    // 초기값 설정
    for (int pos = 1; pos < N + 1; ++pos)
    {
        dp[pos][1] = 0;
    }

    for (int size = 2; size < N; ++size)
    {
        for (int pos = 1; (pos + size - 1) < N + 1; ++pos)
        {
            for (int k = 1; k < size; ++k)
            {
                dp[pos][size] = min(dp[pos][size], dp[pos][k] + dp[pos + k][size - k]);
            }
            dp[pos][size] += arr[pos + size - 1] - arr[pos - 1];
        }
    }

    for (int k = 1; k < N; ++k)
    {
        dp[1][N] = min(dp[1][N], dp[1][k] + dp[1 + k][N - k]);
    }
    dp[1][N] += arr[1 + N - 1];

    cout << dp[1][N] << endl;

    arr.clear();
    dp.clear();
}
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}