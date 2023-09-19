#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100'001;

int n, k;
int dist[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	if (n >= k)
	{
		cout << n - k << '\n';
		cout << 1 << '\n';
	}
	else
	{
		queue<int> q;
		int cnt = 0;

		memset(dist, -1, sizeof(dist));
		dist[n] = 0;
		q.push(n);

		while (!q.empty())
		{
			int cur = q.front();

			q.pop();

			if (cur == k)
			{
				++cnt;
			}

			if ((cur - 1 >= 0) && ((dist[cur - 1] == -1) || (dist[cur - 1] >= dist[cur] + 1)))
			{
				dist[cur - 1] = dist[cur] + 1;
				q.push(cur - 1);
			}

			if ((cur + 1 < MAX) && ((dist[cur + 1] == -1) || (dist[cur + 1] >= dist[cur] + 1)))
			{
				dist[cur + 1] = dist[cur] + 1;
				q.push(cur + 1);
			}

			if ((2 * cur < MAX) && ((dist[2 * cur] == -1) || (dist[2 * cur] >= dist[cur] + 1)))
			{
				dist[2 * cur] = dist[cur] + 1;
				q.push(2 * cur);
			}
		}

		cout << dist[k] << '\n';
		cout << cnt << '\n';
	}
}
