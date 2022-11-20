#include <bits/stdc++.h>
//2024. 0
std::vector<int> parents;
int Find(int x)
{
	if (parents[x] == x)
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int x, int y)
{
	int px = Find(x);
	int py = Find(y);

	if (px <= py)
		parents[py] = px;
	else
		parents[px] = py;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
    
	int n, m;
	std::cin >> n >> m;

	parents.resize(n+1);
	for (int i = 1; i <= n; i++)
		parents[i] = i;

	int a;
	std::cin >> a;
	std::vector<int> know(a);
	for (int i = 0; i < a; i++) 
	{
		std::cin >> know[i];
	}

	std::vector < std::vector<int> > parties(m);
	for (int i = 0; i < m; i++) 
	{
		std::vector<int>& party = parties[i];
		int k;
		std::cin >> k;
		
		party.resize(k);

		std::cin >> party[0];
		for (int j = 1; j < k; j++) 
		{
			std::cin >> party[j];
			Union(party[j-1],party[j]);
		}
	}

	int lies = m;
	for (int i = 0; i < m; i++) 
	{
		std::vector<int>& party = parties[i];
		bool bLie = true;
		for (int j = 0; j < a && bLie; j++) 
		for (int k = 0; k < party.size(); k++) 
		{
			if (Find(party[k]) == Find(know[j])) 
			{
				bLie = false;
				break;
			}
		}

		if (!bLie)
			lies--;
	}
	std::cout << lies;
	return 0;
}
