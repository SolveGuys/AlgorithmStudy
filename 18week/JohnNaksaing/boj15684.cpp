#include <iostream>

class _map_ 
{
	bool map[31][11];
	int n, m, h;

public:
	int answer;
	_map_(int n, int m, int h) : n(n),m(m),h(h) ,answer(4), map()
	{
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			std::cin >> a >> b;
			map[a][b] = true;
		}
	}
	bool go_down();
	void set_line(int depth, int x, int y);
};

bool _map_::go_down() 
{
	for (int i = 1; i <= n; i++) 
	{
		int c = i;
		for (int j = 1; j <= h; j++)
		{
			if (map[j][c])
				c++;
			else if (map[j][c-1])
				c--;
		}

		if (c != i) return false;
	}
	return true;
}

void _map_::set_line(int depth, int x, int y) 
{
	if (answer <= depth) return;
	if (go_down())
	{
		answer = depth;
		return;
	}

	if (depth == 3) return;


	for (int j = y; j <= h; j++) 
	{
		for (int i = x; i <= n; i++) 
		{
			if (map[j][i] == 0 && map[j][i-1] == 0 && map[j][i+1] == 0)
			{
				map[j][i] = 1;
				set_line(depth + 1, i, j);
				map[j][i] = 0;
			}
		}
		x = 1;
	}
}

int main() 
{
	int n, m, h;
	std::cin >> n >> m >> h;

	_map_ map(n,m,h);

	map.set_line(0,1,1);
	if (map.answer > 3)
		std::cout << -1;
	else
		std::cout << map.answer;
	return 0;
}

//https://artjjong.tistory.com/67