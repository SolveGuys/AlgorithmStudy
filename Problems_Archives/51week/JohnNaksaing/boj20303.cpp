#include<bits/stdc++.h>

std::vector<int> candies;
std::vector<int> weights;
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
	int n, m, k;
	std::cin >> n >> m >> k;

	candies.resize(n);
	parents.resize(n);
	weights.resize(n,1);
    
	for (int i = 0; i < n; i++)
		parents[i] = i;

	for (int i = 0; i < n; i++) 
	{
		std::cin >> candies[i];
	}

	for (int i = 0; i < m; i++) 
	{
		int a,b;
		std::cin >> a >> b;
		Union(a-1,b-1);
	}

	for (int i = 0; i < n; i++) 
	{
		if (parents[i] != i) 
		{
            int p = Find(i);
			candies[p] += candies[i];
			weights[p] += weights[i];
		}
	}

	std::vector<int> dp(k,0);

	for (int i = 0; i < n; i++) 
	{
		if (parents[i] != i)
			continue;
		for (int j = k-1; j >= weights[i]; j--) 
		{
			dp[j] = std::max(dp[j],dp[j-weights[i]] + candies[i]);
		}
	}

	std::cout << dp.back();
	return 0;
}
