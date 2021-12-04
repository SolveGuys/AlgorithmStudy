#include <iostream>
#define endl '\n'

int dp[2000][2000]{};
int arr[2000]{};
bool IsPalin(int s, int e)
{
    // 계산한적 있다면 
    if (dp[s][e] != -1)
        return dp[s][e];
   
    // s와 e가 동일한 경우
    if (s == e) 
        return dp[s][e] = 1;
    
    // e가 s의 바로 옆 수일 경우. 두 수는 같아야 팰린드롬
    else if (e - s == 1 && arr[s] == arr[e])
        return dp[s][e] = 1;
    
    // s와 e가 두 칸 이상 떨어져있는 경우. 서로 같고 s와 e 사이가 팰린드롬일경우 s e도 팰린드롬
    else if (arr[s] == arr[e] && IsPalin(s + 1, e - 1) == 1) 
        return dp[s][e] = 1;
    
    else return dp[s][e] = 0;

}

int main()
{    
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    std::fill(&dp[0][0], &dp[1999][2000], -1);
    
    int N; // N (1 ≤ N ≤ 2,000)
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }
    int M; // M (1 ≤ M ≤ 1,000,000)
    std::cin >> M;
    while (M--)
    {
        int s, e;
        std::cin >> s >> e;
        std::cout << IsPalin(s - 1, e - 1) << '\n';
    }

    return 0;
}