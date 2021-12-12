#include <iostream>
#include <array>
#include <algorithm>
int arr[100'000]{}, dp[100'000][5][5]{};
constexpr int cost[5][5] =
{
    {0,2,2,2,2},
    {0,1,3,4,3},
    {0,3,1,3,4},
    {0,4,3,1,3},
    {0,3,4,3,1}
};
constexpr int INF = 987'654'321;
int func(int idx, int left, int right, int tar)
{
    if (idx == tar) return 0;
    int& ret = dp[idx][left][right];
    if (ret != 0) return ret;

    ret = INF;
    const int nextCmd = arr[idx];
    if (nextCmd != left) // 왼발이 있는 곳으로 오른발을 옮길 수 없음. 
    { // 오른발을 옮기는 경우
        ret = std::min(ret, func(idx + 1, left, nextCmd, tar) + cost[right][nextCmd]);
    }
    if (nextCmd != right) // 오른발이 있는 곳으로 왼발을 옮길 수 없음
    { // 왼발을 옮기는 경우
        ret = std::min(ret, func(idx + 1, nextCmd, right, tar) + cost[left][nextCmd]);
    }

    return ret;
}
int main()
{
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    int i = -1;
    do {
        i++;
        std::cin >> arr[i];
    } while (arr[i] != 0);

    int answer = func(0, 0, 0, i);
    std::cout << answer << std::endl;
    return 0;
}