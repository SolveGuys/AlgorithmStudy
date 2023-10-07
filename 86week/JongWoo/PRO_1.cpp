#include <iostream>
#include <unordered_set>

using namespace std;

// 2: (1, 1)
// 3: (1, 2), {2, 1}
// 4: (1, 3), (2, 2), {3, 1}
// 5: (1, 4), (2, 3), {3, 2}, {4, 1}
// 6: (1, 5), (2, 4), (3, 3), {4, 2}, {5, 1}

int solution(int N, int number)
{
    int answer = -1;
    
    // us[i]: N을 i개 사용하여 만들 수 있는 수들의 집합
    unordered_set<int> dp[9];
    
    // N을 i개 이어붙인 값을 넣어준다.
    string tmp = to_string(N);
    
    for (int i = 1; i <= 8; ++i)
    {
        dp[i].insert(stoi(tmp));
        tmp.push_back(N + '0');
    }
    
    // 두 집합을 조합하여 나오는 모든 수를 계산한다.
    for (int i = 2; i <= 8; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            for (int a : dp[j])
            {
                for (int b : dp[i - j])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a * b);
                    
                    if (a > b)
                    {
                        dp[i].insert(a - b);
                        dp[i].insert(a / b);
                    }
                    
                    if (a == b)
                    {
                        dp[i].insert(a / b);
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= 8; ++i)
    {
        if (dp[i].find(number) != dp[i].end())
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}
