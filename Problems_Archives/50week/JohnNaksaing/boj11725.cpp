#include <bits/stdc++.h>

int main() 
{
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> connection(n+1);
	std::vector<int> tree(n+1);
	for (int i = 0; i < n-1; i++) 
	{
		int a, b;
		std::cin >> a >> b;
		
		connection[a].emplace_back(b);
		connection[b].emplace_back(a);
	}

	std::queue<int> q;
	q.push(1);

	while (!q.empty()) 
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < connection[here].size(); i++) 
		{
			int next = connection[here][i];
			if (!tree[next])
			{
				tree[next] = here;
				q.push(next);
			}
		}
	}
	
	for (int i = 2; i <= n; i++) 
	{
		std::cout << tree[i] << '\n';
	}
	return  0;
}