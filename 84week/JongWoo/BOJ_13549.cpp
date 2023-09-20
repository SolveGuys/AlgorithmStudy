#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100'001;

int n, k;
int dist[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	// 수빈이가 동생보다 뒤에 있는(좌표 값이 큰) 경우
	// X - 1로 이동하는 방법 밖에 없다.
	if (n >= k)
	{
		cout << n - k << '\n';
	}
	else
	{
		for (int i = 0; i < MAX; ++i)
		{
			dist[i] = MAX;
		}

		queue<int> q;

		dist[n] = 0;
		q.push(n);

		while (!q.empty())
		{
			int cur = q.front();

			q.pop();

			if (cur == k)
			{
				cout << dist[cur] << '\n';
				break;
			}

			for (int nxt : { cur - 1, cur + 1 })
			{
				if ((nxt < 0) || (nxt >= MAX) || (dist[nxt] <= dist[cur] + 1))
				{
					continue;
				}
				
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}

			int nxt = 2 * cur;

			if ((nxt >= MAX) || (dist[nxt] <= dist[cur]))
			{
				continue;
			}

			dist[nxt] = dist[cur];
			q.push(nxt);
		}
	}
}
