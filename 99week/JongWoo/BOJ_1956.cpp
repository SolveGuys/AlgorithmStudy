#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 0x3fffffff;

int v, e;
vector<pair<int, int>> adjList[402];
int inDegrees[402];

int Dijkstra(int st);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a = 0, b = 0, dist = 0;

		cin >> a >> b >> dist;
		adjList[a].emplace_back(dist, b);
		++inDegrees[b];
	}

	int answer = INF;

	for (int i = 1; i <= v; ++i)
	{
		// 진출 차수나 진입 차수가 0인 경우에는 BFS 탐색을 수행하지 않는다.
		if ((adjList[i].empty()) || (inDegrees[i] == 0))
		{
			continue;
		}

		answer = min(answer, Dijkstra(i));
	}

	if (answer == INF)
	{
		answer = -1;
	}

	cout << answer << '\n';
}

int Dijkstra(int st)
{
	int ret = INF;
	int dist[402] = {};
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // <가중치, 정점>

	for (int i = 1; i <= v; ++i)
	{
		dist[i] = INF;
	}

	dist[st] = 0;
	minHeap.emplace(dist[st], st);

	while (!minHeap.empty())
	{
		int w = minHeap.top().first;
		int cur = minHeap.top().second;

		minHeap.pop();

		if (w != dist[cur])
		{
			continue;
		}

		for (auto& p : adjList[cur])
		{
			int w = p.first;
			int u = p.second;

			if (dist[u] > dist[cur] + w)
			{
				dist[u] = dist[cur] + w;
				minHeap.emplace(dist[u], u);
			}
			// 다시 시작점으로 돌아올 수 있는 경우, 현재 노드까지의 거리(dist[cur])에 시작점까지의 가중치의 값이 운동 거리가 된다.
			else if (u == st)
			{
				ret = min(ret, dist[cur] + w);
			}
		}
	}

	return ret;
}
