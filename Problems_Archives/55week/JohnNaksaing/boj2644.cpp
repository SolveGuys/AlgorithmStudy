#include <bits/stdc++.h>

std::vector<std::vector<bool>> map;
std::vector<bool> visit;

int chon(int from, int to, int num) 
{
	static int n = map.size();
	visit[from] = true;
	int c = 1e9;
	if(from == to)
		return num;
	else
	{
		for (int i = 0; i < n; i++) 
		{
			if (map[from][i] && !visit[i])
			{
				visit[i] = true;
				c = std::min(c,chon(i,to,num+1));
				visit[i] = false;
			}
		}
	}
	return c;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	int a, b;
	std::cin >> n >> a >> b;
	
	map.resize(n+1,std::vector<bool>(n+1));
	visit.resize(n+1);
	int k;
	std::cin >> k;
	
	while (k--) 
	{
		int i, j;
		std::cin >> i >> j;

		map[i][j] = true;
		map[j][i] = true;
	}
	//map[i][j] : i에게 j라는 자식이 있는가?

	int ans = chon(a, b, 0);
	std::cout << (ans == 1e9?-1:ans);

	return 0;
}