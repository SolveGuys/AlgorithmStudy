#include <bits/stdc++.h>

constexpr int max_given_size = 100;
constexpr int dy[]{0,-1,0,1};
constexpr int dx[]{1,0,-1,0};

bool map[max_given_size + 1][max_given_size + 1];

#define using_class 1
#if using_class 
class curve 
{
	int x, y, d, g;
	std::stack<int> m_sDirections;
public:
	curve(int x, int y, int d, int g) : x(x), y(y), d(d), g(g)
	{
		//gen 0
		map[x][y] = true;
		m_sDirections.push(d);
		x += dx[d];
		y += dy[d];

		map[x][y] = true;
	}
	inline bool bValid(int x, int y) { return (0 <= x && x <= 100 && 0 <= y && y <= 100); }
	void grow() 
	{
		//other gens
		for (int _ = 0; _ < g; _++)
		{
			std::stack<int> s_temp = m_sDirections;
			int size = s_temp.size();
			for (int i = 0; i < size; i++)
			{
				d = s_temp.top();
				s_temp.pop();

				d = (d + 1) % 4;
				x += dx[d];
				y += dy[d];

				map[x][y] = true;

				m_sDirections.push(d);
			}
		}
	}
};
#endif

int search(int N) 
{
	int answer = 0;
	for (int i = 0; i < max_given_size; i++)
	for (int j = 0; j < max_given_size; j++)
	{
		if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
			answer++;
	}
	return answer;
}
void print_map(int N);

int main()
{
	int N;
	std::cin >> N;
	for(int __ = 0; __ < N; __++)
	{
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;

#if using_class
		
		//gen 0
		map[x][y] = true;

		x += dx[d];
		y += dy[d];

		map[x][y] = true;

		//other gens
		std::stack<int> s_dirs;
		s_dirs.push(d);
		for (int _ = 0; _ < g; _++) 
		{
			std::stack<int> s_temp = s_dirs;
			int size = s_dirs.size();
			for (int i = 0; i < size; i++) 
			{
				d = s_temp.top();
				s_temp.pop();

				d = (d + 1) % 4;
				x += dx[d];
				y += dy[d];

				map[x][y] = true;

				s_dirs.push(d);
			}
		}
#else
		curve(x,y,d,g).grow();
#endif
	}

	std::cout << search(N) << '\n';
	
	//print_map(N);
	return 0;
}