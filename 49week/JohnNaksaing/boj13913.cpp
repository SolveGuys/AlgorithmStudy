//3200, 16
#include <bits/stdc++.h>

int visited[100001];

int main() 
{
	memset(visited,-1,sizeof(visited));
	int n, k;
	std::cin >> n >> k;

	struct node 
	{
		int n, t;
	};
	std::queue<node> q;
	q.push({ n,0 });
	visited[n] = 0;

	while (!q.empty()) 
	{
		node front = q.front();
		q.pop();

		if (front.n == k)
		{
			std::cout << front.t << '\n';
			break;
		}

		if (front.n > 0 && visited[front.n-1] == -1) 
		{
			int nx = front.n - 1;
			
			visited[nx] = front.n;
			
			q.push({ nx ,front.t+1});
		}
		if (front.n < 100000 && visited[front.n + 1] == -1)
		{
			int nx = front.n + 1;

			visited[nx] = front.n;

			q.push({ nx ,front.t+1});
		}
		if (front.n * 2 <= 100000 && visited[front.n * 2] == -1)
		{
			int nx = front.n * 2;

			visited[nx] = front.n;

			q.push({ nx ,front.t + 1 });
		}
	}

	int idx = k;
	std::vector<int> hist;
	while (idx != n)
	{
		//std::cout << idx << ' ';
		hist.emplace_back(idx);
		idx = visited[idx];
	}

	std::cout << idx;
	for (auto it = hist.rbegin(); it != hist.rend(); it++) 
	{
		std::cout << ' ' << *it;
	}

	return 0;
}