#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void search_puyo_bfs(std::string map[], bool visited[][6], std::vector<std::pair<int, int>>& vec_xys, int x_start, int y_start);
//void boom(std::string map[], std::vector<std::pair<int, int>>& vec_xys, int& answer);
//void fall(std::string map[], std::vector<std::pair<int, int>>& vec_booms);

//std::vector<std::pair<int, int>> 
bool search_puyo(std::string map[], std::vector<std::pair<int, int>>& vec_xys)
{
	const int ROW = 12, COL = 6;
	//loop를 ROW * COL까지 걸고 
	bool visited[ROW][COL] = { false, };
	for (int i = ROW - 1; i >= 0; i--)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == '.') continue;

			//bfs로 근처 뭉탱이 탐색
			search_puyo_bfs(map, visited, vec_xys, i, j);
		}
	}

	//모두 터뜨렸으면 true
	return vec_xys.empty();
}

void search_puyo_bfs(std::string map[], bool visited[][6], std::vector<std::pair<int, int>>& vec_xys, int x_start, int y_start)
{
	const int DX[] = { -1, 1, 0, 0 };
	const int DY[] = { 0, 0, 1,-1 };
	const int ROW = 12, COL = 6;

	
	std::queue<std::pair<int, int>> temp;
	std::vector<std::pair<int, int>> searched;

	temp.push(std::make_pair(x_start, y_start));
	visited[x_start][y_start] = true;

	while (!temp.empty())
	{
		int x_now = temp.front().first;
		int y_now = temp.front().second;

		temp.pop();

		searched.push_back(std::make_pair(x_now,y_now));

		for (int i = 0; i < 4; i++)
		{
			int x_next = x_now + DX[i];
			int y_next = y_now + DY[i];

			//out of range
			if (x_next < 0 || x_next >= ROW || y_next < 0 || y_next >= COL) continue;

			if (map[x_next][y_next] == map[x_now][y_now] && !visited[x_next][y_next])
			{
				visited[x_next][y_next] = true;
				temp.push(std::make_pair(x_next, y_next));	
			}
		}
	}
	
	if (searched.size() >= 4) 
	{
		vec_xys.insert(vec_xys.end(),searched.begin(),searched.end());
	}
}

void boom(std::string map[], std::vector<std::pair<int, int>>& vec_booms, int& answer)
{
	for (auto pair_xy : vec_booms)
	{
		int x = pair_xy.first;
		int y = pair_xy.second;

		map[x][y] = '.';
	}

	answer++;
}

void fall(std::string map[], std::vector<std::pair<int, int>>& vec_booms)
{
	const int ROW = 12, COL = 6;
	static struct _pair_compare 
	{
		bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) 
		{
			if (a.first == b.first) return a.second < b.second;
			else return a.first < b.first;
		}
	} pair_compare;
	std::sort(vec_booms.begin(),vec_booms.end(), pair_compare);
	for (auto boom : vec_booms) 
	{
		for (int i = boom.first; i > 0; i--)
		{
			map[i][boom.second] = map[i-1][boom.second];
		}
		map[0][boom.second] = '.';
	}
	vec_booms.clear();
}

int main()
{
	const int ROW = 12, COL = 6;
	std::string map[12];
	for (int i = 0; i < ROW; i++)
	{

		std::cin >> map[i];	
	}

	int answer = 0;

	std::vector<std::pair<int, int>> vec_xys;
	while (true) 
	{
		bool bDone = search_puyo(map, vec_xys); 
		if (bDone) break;

		boom(map, vec_xys, answer);
		fall(map, vec_xys);
	};
	
	std::cout << answer;
	
	//for (int i = 0; i < ROW; i++)	std::cout << map[i] << '\n';

	return 0;
}
