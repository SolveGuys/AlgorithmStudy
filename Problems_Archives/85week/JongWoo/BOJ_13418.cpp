#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;

int parent[1'002];
vector<tuple<int, int, int>> edges; // <weight, u, v>

int GetParent(int v);
void SetUnion(int root1, int root2);

int Kruskal();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int in = 0;

	cin >> in >> in >> in;

	for (int i = 0; i < m; ++i)
	{
		int u = 0, v = 0, w = 0;

		cin >> u >> v >> w;
		edges.emplace_back(w, u, v);
	}

	sort(edges.begin(), edges.end(), greater<>());

	int minFatigue = (n - 1) - Kruskal() + (1 - in);
	
	sort(edges.begin(), edges.end());

	int maxFatigue = (n - 1) - Kruskal() + (1 - in);

	cout << abs(maxFatigue * maxFatigue - minFatigue * minFatigue) << '\n';
}

int GetParent(int v)
{
	if (parent[v] == v)
	{
		return v;
	}

	return parent[v] = GetParent(parent[v]);
}

void SetUnion(int root1, int root2)
{
	if (root1 <= root2)
	{
		parent[root2] = root1;
	}
	else
	{
		parent[root1] = root2;
	}
}

int Kruskal()
{
	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}

	int tot = 0, cnt = 0;

	for (int i = 0; i < edges.size(); ++i)
	{
		int w = get<0>(edges[i]);
		int root1 = GetParent(get<1>(edges[i]));
		int root2 = GetParent(get<2>(edges[i]));

		if (root1 != root2)
		{
			SetUnion(root1, root2);
			tot += w;
			++cnt;

			if (cnt == n - 1)
			{
				break;
			}
		}
	}

	return tot;
}
