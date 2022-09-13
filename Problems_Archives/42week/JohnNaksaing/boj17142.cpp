
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int big = 1e9;
struct node
{
	int x, y;

	node& operator+=(const node& rht)
	{
		x += rht.x, y += rht.y;
		return *this;
	}
};

node operator+(node lft, node rht)
{
	return { lft.x + rht.x,lft.y + rht.y };
}

const node dir[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

std::vector<node> virus;
std::vector<bool> combination;

int n, k;

char arr[50][50];
int visited[50][50];

int empty_spaces;

int max_element()
{
	int a = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) 
	{
		if (arr[i][j] == '1' || arr[i][j] == '2') 
			continue;

		if (visited[i][j] == big)   
			return big;

		a = std::max(a, visited[i][j]);
	}
	return a;
}

int bfs()
{	
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		visited[i][j] = big;

	std::queue<node> q;
	for (int i = 0; i < virus.size(); i++)
	{
		if (combination[i])
		{
			node temp = { virus[i].x ,virus[i].y };
			visited[temp.x][temp.y] = 0;
			q.push(temp);
		}
	}

	int count = 0;
	while (!q.empty()) 
	{
		int qs = q.size();
		for (int k = 0; k < qs; k++)
		{
			node c = q.front();
			int cv = visited[c.x][c.y];

			q.pop();
			for (int i = 0; i < 4; i++) 
			{
				node next = c + dir[i];
				int nx = next.x;
				int ny = next.y;

				if (!(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] != '1'))
					continue;

				if (visited[nx][ny] > cv + 1)
				{
					visited[nx][ny] = cv + 1;
					q.push({ nx,ny });

					if (arr[nx][ny] == '0')
						count++;
				}
			}
		}
		if (count == empty_spaces)
			break;
	}
	if (count != empty_spaces)
		return big;
	else 
		return max_element();
}

int main() 
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::cin >> n >> k;
	
	empty_spaces = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) 
	{
		int a;
		std::cin >> a;
		arr[i][j] = a + '0';

		if (arr[i][j] == '2') 
			virus.push_back({ i,j });
		else if (arr[i][j] == '0')
			empty_spaces++;
	}
	
	int result = big;
	combination.resize(virus.size() - k, false);
	combination.insert(combination.end(), k, true);

	do 
	{
		int time = bfs();
		result = std::min(result, time);
	}
	while (std::next_permutation(combination.begin(), combination.end()));

	std::cout << (result == big ? -1 : result);

	return 0;
}