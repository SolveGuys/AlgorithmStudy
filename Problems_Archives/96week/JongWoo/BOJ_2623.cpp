#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int inDegrees[1'002];
vector<int> adjList[1'002];

void TopologySort();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int k = 0;

		cin >> k;

		int st = 0, en = 0;

		cin >> st;

		for (int j = 0; j < k - 1; ++j)
		{
			cin >> en;
			adjList[st].push_back(en);
			++inDegrees[en];
			st = en;
		}
	}

	TopologySort();
}

void TopologySort()
{
	vector<int> answer;
	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegrees[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();

		q.pop();
		answer.push_back(cur);

		for (int u : adjList[cur])
		{
			--inDegrees[u];

			if (inDegrees[u] == 0)
			{
				q.push(u);
			}
		}
	}

	if (answer.size() == n)
	{
		for (int u : answer)
		{
			cout << u << '\n';
		}
	}
	else
	{
		cout << 0 << '\n';
	}
}
