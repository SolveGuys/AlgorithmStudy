#include <iostream>
#include <queue>

using namespace std;

int n, k;
int stones[5'001];
bool isVisited[5'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> stones[i];
    }

    queue<int> q;

    isVisited[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();

        q.pop();

        if (cur == n)
        {
            cout << "YES\n";
            return 0;
        }

        for (int i = cur + 1; i <= n; ++i)
        {
            if (!isVisited[i])
            {
                int force = (i - cur) * (1 + abs(stones[i] - stones[cur]));

                if (force <= k)
                {
                    isVisited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    cout << "NO\n";
}
