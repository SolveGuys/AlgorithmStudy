#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[102];
int inDegrees[102];
vector<int> adjList[102];

bool BFS(int st);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		++inDegrees[arr[i]];
		adjList[i].push_back(arr[i]);
	}

	vector<int> answer;

	for (int i = 1; i <= n; ++i)
	{
		// 진입차수가 0인 정점은 조건을 만족할 수 없다.
		if (inDegrees[i] == 0)
		{
			continue;
		}

		if (BFS(i))
		{
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';

	for (int v : answer)
	{
		cout << v << '\n';
	}
}

bool BFS(int st)
{
	queue<int> q;
	bool isVisited[102] = {};

	// 처음에 시작 위치는 방문여부를 체크하지 않고 큐에 추가한다.
	q.push(st);

	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		// 다시 시작점으로 돌아올 경우 해당 정점은 조건을 만족한다.
		if ((cur == st) && (isVisited[st]))
		{
			return true;
		}

		for (int v : adjList[cur])
		{
			if (!isVisited[v])
			{
				isVisited[v] = true;
				q.push(v);
			}
		}
	}

	return false;
}
