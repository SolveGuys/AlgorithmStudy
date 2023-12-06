#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int durations[1'002];
int inDegrees[1'002];
int totals[1'002];
vector<int> adjList[1'002];

void TopologySort(int target);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n >> k;

		for (int j = 1; j <= n; ++j)
		{
			cin >> durations[j];
			inDegrees[j] = totals[j] = 0;
			adjList[j].clear();
		}

		for (int j = 0; j < k; ++j)
		{
			int x = 0, y = 0;

			cin >> x >> y;
			++inDegrees[y];
			adjList[x].push_back(y);
		}

		int target = 0;

		cin >> target;
		TopologySort(target);
	}
}

void TopologySort(int target)
{
	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegrees[i] == 0)
		{
			totals[i] = durations[i];
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		if (cur == target)
		{
			cout << totals[cur] << '\n';
			break;
		}

		for (int u : adjList[cur])
		{
			totals[u] = max(totals[u], totals[cur] + durations[u]);
			--inDegrees[u];

			if (inDegrees[u] == 0)
			{
				q.push(u);
			}
		}
	}
}
