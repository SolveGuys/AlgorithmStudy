#include <bits/stdc++.h>

int n;
const int big = 1e9;

using bitmask = int;

int map[16][16];
int dp[16][1<<16]{0};

int TSP(int idx, bitmask visit_info)
{	
	visit_info |= (1 << idx);

	if (visit_info == (1 << n) - 1)
	{
		return map[idx][0] == 0 ? big : map[idx][0];
	}

	int& weight = dp[idx][visit_info];
	
	if (weight == 0)
	{
		weight = big;
		for (int i = 0; i < n; i++) 
		{
            if (idx == i) continue;
			if (map[idx][i] == 0) continue;
			if (visit_info & (1 << i))continue;
			
			weight = std::min(weight,TSP(i,visit_info) + map[idx][i]);
		}
	}

	return weight;
}

int main() 
{
	std::cin >> n;

	//std::vector<std::vector<int>> _map(n, std::vector<int>(n));
	//std::vector<std::vector<bitmask>> _dp(n,std::vector<bitmask>(1<<n));

	for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++)
	{
		std::cin >> map[i][j];
	}
	int ans = TSP(0, 0x1);
	std::cout << ans;
	return 0;
}
