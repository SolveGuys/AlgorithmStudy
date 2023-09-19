#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adjList[32'001];
int inDegrees[32'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;

		cin >> a >> b;
		adjList[a].push_back(b);
		++inDegrees[b];
	}

	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegrees[i] == 0)
		{
			minHeap.push(i);
		}
	}

	while (!minHeap.empty())
	{
		int cur = minHeap.top();

		minHeap.pop();
		cout << cur << ' ';

		for (int num : adjList[cur])
		{
			--inDegrees[num];

			if (inDegrees[num] == 0)
			{
				minHeap.push(num);
			}
		}
	}
}
