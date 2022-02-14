#include <iostream>
#include <algorithm>
#include <array>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int MAX_LEN = 50'000;

int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; // N: 50,000 이하
    int L; // 소형기관차의 길이
    array<int, MAX_LEN> arr{};
    array<array<int, MAX_LEN>, 3> dp{}; 
    array<int, MAX_LEN> sum{};

    // Input Data
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cin >> L;

    // 소형기관차가 i번 열차까지 끌때 인원수 합 계산
    queue<int> q;
    int temp{};
    for (int i = 0; i < N; ++i)
    {
        temp += arr[i];
        q.push(arr[i]);
        if (i < L - 1) continue;

        sum[i] = temp;
        temp -= q.front();
        q.pop();
    }

    // 소형기관차가 한 대인 경우
    for(int i = L - 1; i < N; ++i)
    {
        dp[0][i] = max(dp[0][i - 1], sum[i]);
    }
    
    // 소형기관차가 두 대인 경우
    for (int i = (2 * L) - 1; i < N; ++i)
    {
        dp[1][i] = max(dp[1][i - 1], sum[i] + dp[0][i - L]);
    }

    // 소형기관차가 세 대인 경우
    for (int i = (3 * L) - 1; i < N; ++i)
    {
        dp[2][i] = max(dp[2][i - 1], sum[i] + dp[1][i - L]);
    }

    cout << dp[2][N-1];
    return 0;
}