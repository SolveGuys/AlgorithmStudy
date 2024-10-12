#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;


typedef pair<int, int> ii;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int total = 0;
vector<vector<char>> arr(5, vector<char>(5));

bool BFS(vector<ii>& res)
{
	vector<vector<bool>> arr2(5, vector<bool>(5, 0));
	vector<vector<bool>> visit(5, vector<bool>(5, 0));

	for (ii a : res)
	{
		arr2[a.first][a.second] = 1;
	}
	queue<ii> que;
	que.push(res[0]);
	int cnt = 0;
	int S_count = 0;
	while (!que.empty())
	{
		int y, x;
		tie(y, x) = que.front();
		que.pop();
		if (visit[y][x])continue;
		cnt++;
		if (arr[y][x] == 'S') S_count++;
		visit[y][x] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || arr2[ny][nx] == 0 || visit[ny][nx])continue;
			que.push({ ny,nx });
		}
	}
	return cnt == 7 && S_count >= 4;
}
void Back(int y, int x, int depth, vector<ii> res)
{
	if (depth == 7)
	{
		if (BFS(res)) total++;
		return;
	}
	for (; y < 5; y++)
	{
		for (; x < 5; x++)
		{
			res.push_back({ y,x });
			Back(y, x + 1, depth + 1, res);
			res.pop_back();
		}
		x = 0;
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<ii> res;
	Back(0, 0, 0, res);

	cout << total << endl;

	return 0;
}