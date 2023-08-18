#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 0x7f7f7f7f;

int n, m;
vector<pair<int, int>> adjList[1'001];
int dist[1'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int st = 0, en = 0, cost = 0;

        cin >> st >> en >> cost;
        adjList[st].emplace_back(cost, en);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int st = 0, en = 0;

    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }

    cin >> st >> en;
    dist[st] = 0;
    minHeap.emplace(dist[st], st);

    while (!minHeap.empty())
    {
        int cost = minHeap.top().first;
        int arrive = minHeap.top().second;

        minHeap.pop();

        if (cost != dist[arrive])
        {
            continue;
        }

        for (const auto& p : adjList[arrive])
        {
            if (dist[p.second] > dist[arrive] + p.first)
            {
                dist[p.second] = dist[arrive] + p.first;
                minHeap.emplace(dist[p.second], p.second);
            }
        }
    }

    cout << dist[en] << '\n';
}
