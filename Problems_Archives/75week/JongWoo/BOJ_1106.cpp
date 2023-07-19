#include <iostream>
#include <vector>
#include <utility>

#define MAX 1'000'000 // 1000(최대 목표 고객의 수) * 100(최대 비용)

using namespace std;

int c, n;
vector<pair<int, int>> v; // <cost, customer count>
int dp[MAX + 1]; // dp[i]: i원을 소비하여 얻을 수 있는 최대 고객의 수

//void DFS(int cost, int cnt); // DFS 풀이는 시간 초과

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 1; i <= MAX; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int cost = v[j].first;
            int cnt = v[j].second;

            // 1. 소비할 금액이 j번째 도시의 홍보 비용의 배수인 경우
            if (i % cost == 0)
            {
                // 인원수 x 몫의 값과 비교하여 더 큰 값을 선택한다.
                dp[i] = max(dp[i], cnt * (i / cost));
            }

            // 2. 소비할 금액이 j번째 도시의 홍보 비용보다 큰 경우
            if (i >= cost)
            {
                // j - cost번째 도시를 홍보했을 때의 인원수에 j번째 도시를 홍보했을 때의 인원수를 더한 값과 비교하여 더 큰 값을 선택한다.
                dp[i] = max(dp[i], dp[i - cost] + cnt);
            }
        }

        // 목표 인원 c명 이상을 달성했다면, 그때의 소비할 금액 i가 답이 된다.
        if (dp[i] >= c)
        {
            cout << i << '\n';
            break;
        }
    }
}

//void DFS(int cost, int cnt)
//{
//    if (cnt >= c)
//    {
//        if (cost < answer)
//        {
//            answer = cost;
//        }
//
//        return;
//    }
//
//    for (int i = 0; i < n; ++i)
//    {
//        DFS(cost + v[i].first, cnt + v[i].second);
//    }
//}
