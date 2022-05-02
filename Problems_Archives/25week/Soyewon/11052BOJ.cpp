 // 백준 11052 - 카드 구매하기
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int p[MAX];
int cost[MAX];

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> p[i]; // Pi 값 차례로 저장
    }

    cost[1] = p[1];

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cost[i] = max(cost[i], cost[i-j] + p[j]); // 2장 살때의 최대값부터 순차적으로 계산
        }
    }

    cout << cost[n] << endl;
}

