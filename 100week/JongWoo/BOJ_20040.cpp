#include <iostream>

using namespace std;

int n, m;
int parents[500'002];

int GetParent(int v);
void SetUnion(int v1, int v2);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		parents[i] = i;
	}

	int answer = 0;

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;

		cin >> a >> b;

		int root1 = GetParent(a);
		int root2 = GetParent(b);

		if (root1 == root2)
		{
			answer = i + 1;
			break;
		}
		else
		{
			SetUnion(root1, root2);
		}
	}

	cout << answer << '\n';
}

int GetParent(int v)
{
	if (parents[v] != v)
	{
		parents[v] = GetParent(parents[v]);
	}

	return parents[v];
}

void SetUnion(int v1, int v2)
{
	if (v1 < v2)
	{
		parents[v2] = v1;
	}
	else
	{
		parents[v1] = v2;
	}
}
