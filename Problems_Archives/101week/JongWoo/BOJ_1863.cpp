#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
int dist[1'000'002];

void BFS();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> f >> s >> g >> u >> d;
	BFS();
}

void BFS()
{
	queue<int> q;

	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	q.push(s);

	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		if (cur == g)
		{
			cout << dist[cur] << '\n';
			return;
		}

		for (int shift : { u, -d })
		{
			int nxt = cur + shift;

			if ((nxt < 1) || (nxt > f) || (dist[nxt] != -1))
			{
				continue;
			}

			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	cout << "use the stairs\n";
}
