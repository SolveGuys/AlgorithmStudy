#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges; // <cost, a, b>
vector<int> parents;

void Kruskal();
int GetRoot(int v);
void SetUnion(int root1, int root2);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	edges.resize(m);
	parents.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, cost = 0;

		cin >> a >> b >> cost;
		edges[i] = make_tuple(cost, a, b);
	}

	for (int i = 1; i <= n; ++i)
	{
		parents[i] = i;
	}

	Kruskal();
}

void Kruskal()
{
	sort(edges.begin(), edges.end());

	int totCost = 0, selected = 0;

	for (int i = 0; i < edges.size(); ++i)
	{
		int a = 0, b = 0, cost = 0;

		tie(cost, a, b) = edges[i];

		int root1 = GetRoot(a);
		int root2 = GetRoot(b);

		if (root1 != root2)
		{
			SetUnion(root1, root2);
			++selected;

			if (selected == n - 1)
			{
				break;
			}

			totCost += cost;
		}
	}

	cout << totCost << '\n';
}

int GetRoot(int v)
{
	if (v != parents[v])
	{
		parents[v] = GetRoot(parents[v]);
	}

	return parents[v];
}

void SetUnion(int root1, int root2)
{
	if (root1 < root2)
	{
		parents[root2] = root1;
	}
	else
	{
		parents[root1] = root2;
	}
}
