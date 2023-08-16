#include <iostream>

using namespace std;

int n, m;
int vips[41];
int dp[41]; // dp[i]: 좌석이 i개 있을 때, 앉을 수 있는 경우의 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> vips[i];
    }

    // 1. n번 입장권을 가진 사람이 n번 자리에 그대로 앉는 경우
    //    => 남은 n - 1개의 좌석에 대한 경우의 수 = dp[n - 1]
    // 2. n번 입장권을 가진 사람이 n - 1번 자리로 옮겨 앉는 경우
    //    => n - 1번 입장권을 가진 사람은 반드시 n번 자리에 앉아야 한다.
    //    => 남은 n - 2개의 좌석에 대한 경우의 수 = dp[n - 2]
    // 
    // 따라서 점화식은 dp[i] = dp[i - 1] + dp[i - 2], 피보나치 수열과 같다는 것을 알 수 있다.
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // 그러나 중간중간 vip 좌석이 존재하기 때문에 각 구간의 경우의 수를 구해 곱해주어야 답을 구할 수 있다.
    int answer = 1;
    int st = 0;

    for (int i = 0; i < m; ++i)
    {
        int en = vips[i];

        answer *= dp[en - st - 1];
        st = en;
    }

    answer *= dp[n - st];
    cout << answer << '\n';
}
