#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 0x3fffffff;

int n, m;
int dist[50'002];
vector<pair<int, int>> adjList[50'002]; // <cost, index>

void Dijkstra(int st);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, cow = 0;

		cin >> a >> b >> cow;
		adjList[a].emplace_back(cow, b);
		adjList[b].emplace_back(cow, a);
	}

	Dijkstra(1);
	cout << dist[n] << '\n';
}

void Dijkstra(int st)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // <cost, index>

	for (int i = 0; i <= n; ++i)
	{
		dist[i] = INF;
	}

	dist[st] = 0;
	minHeap.emplace(dist[st], 1);

	while (!minHeap.empty())
	{
		int cow = minHeap.top().first;
		int idx = minHeap.top().second;

		minHeap.pop();

		if (dist[idx] != cow)
		{
			continue;
		}

		for (const auto& p : adjList[idx])
		{
			if (dist[p.second] > dist[idx] + p.first)
			{
				dist[p.second] = dist[idx] + p.first;
				minHeap.emplace(dist[p.second], p.second);
			}
		}
	}
}
