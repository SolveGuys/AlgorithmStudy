#include <cstring>
#include <cstdio>
#include <algorithm>
#include <array>

class table 
{
	std::array<char,25> square;
	std::array<int,25> comb_selected;

	bool m_visited[25];
	bool m_bmember[25];
public:
	table();
	int solve();
private:
	bool bConnected7(const std::array<int, 7>& comb_selected);
	bool bMore4S(const std::array<int, 7>& comb_selected);
};

table::table() : m_visited { false, }
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf(" %c", &square[5 * i + j]);
			//scanf_s(" %c", &square[5 * i + j]);
		}
	}

	for (int i = 0; i < 7; i++) comb_selected[24-i] = 1;
	for (int i = 0; i < 18; i++) comb_selected[i] = 0;
}

bool table::bConnected7(const std::array<int, 7>& seven)
{
	static const int dx[] = { 1, -1, 0,  0 };
	static const int dy[] = { 0,  0, 1, -1 };
	std::queue<int> bfs;

	m_visited[seven[0]] = true;
	bfs.push(seven[0]);

	int count = 1;
	while (!bfs.empty())
	{
		int xy = bfs.front();
		bfs.pop();

		int x = xy / 5;
		int y = xy % 5;

		for (int i = 0; i < 4; i++)
		{
			int n_x = x + dx[i];
			int n_y = y + dy[i];

			int n_xy = 5 * n_x + n_y;

			if (0 > n_x || n_x >= 5 || 0 > n_y || n_y >= 5) continue;
			if (m_visited[n_xy]) continue;
			if (!m_bmember[n_xy]) continue;

			count++;
			m_visited[n_xy] = true;
			bfs.push(n_xy);
		}
	}
	//printf("%d\n",count);
	return count == 7;
}

bool table::bMore4S(const std::array<int,7>& seven)
{
	int s_s = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (square[seven[i]] == 'S') s_s++;
	}
	if( s_s < 4) return false;
	else return true;
}

int table::solve() 
{
	int answer = 0;
	
	do
	{
		memset(m_bmember,false,sizeof(m_bmember));
		memset(m_visited,false,sizeof(m_visited));
		
		int j = 0;
		std::array<int,7> seven;
		for (int i = 0; i < 25; i++) 
		{
			if (comb_selected[i]) 
			{
				seven[j++] = i; 
				m_bmember[i] = true;
			}
		}

		if (bMore4S(seven) && bConnected7(seven))
			answer++;

	} while (std::next_permutation(comb_selected.begin(), comb_selected.end()));
	
	return answer;
}

int main()
{	
	table _table;
	
	printf("%d\n",_table.solve());
	return 0;
}