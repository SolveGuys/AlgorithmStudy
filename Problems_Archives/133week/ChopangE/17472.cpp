#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int N, M;
int d = 2;
bool cmp(iii&a, iii&b)
{
	return a.second < b.second;
}
vector<vector<int>> place;
vector<vector<ii>> island(8, vector<ii>());
vector<vector<int>> adj(8, vector<int>(8, 1000));
vector<int> s;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS()
{
	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			if ( place[i][j] == 1 )
			{
				queue<ii> que;
				que.push({ i,j });
				while ( !que.empty() )
				{
					int y, x;
					tie(y, x) = que.front();
					que.pop();
					if ( place[y][x] != 1 )continue;
					place[y][x] = d;
					island[d].push_back({ y,x });
					for ( int k = 0; k < 4; k++ )
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if ( nx >= M || nx < 0 || ny >= N || ny < 0 || place[ny][nx] != 1 )continue;
						que.push({ ny,nx });
					}
				}
				d++;
			}
		}
	}

}

int Find(int x)
{
	if ( s[x] == -1 )return x;
	return s[x] = Find(s[x]);
}

bool Union(int x, int y)
{
	int sx = Find(x);
	int sy = Find(y);
	if ( sx == sy ) return false;
	if ( sx < sy ) s[sy] = sx;
	else s[sx] = sy;
	return true;
}

void DFS(int dir, int y, int x, int d, int num)
{
	if ( dir == 1 ) //오른쪽
	{
		if ( x + 1 < M)
		{
			if ( place[y][x + 1] == 0 )
			{
				DFS(dir, y, x + 1, d + 1, num);
			}
			else if ( place[y][x + 1] != num )
			{
				if ( d == 1 )return;
				int destNum = place[y][x + 1];
				adj[num][destNum] = min(adj[num][destNum], d);
				return;
			}
			else return;
		
		}
	}
	else if ( dir == 2 ) // 왼쪽
	{
		if ( x - 1 >= 0 )
		{
			if ( place[y][x - 1] == 0 )
			{
				DFS(dir, y, x-1, d + 1, num);
			}
			else if ( place[y][x - 1] != num )
			{
				if ( d == 1 )return;
				int destNum = place[y][x - 1];
				adj[num][destNum] = min(adj[num][destNum], d);
				return;
			}
			else return;
		}
	}
	else if ( dir == 3 ) //위쪽
	{
		if ( y - 1 >= 0 )
		{
			if ( place[y-1][x] == 0 )
			{
				DFS(dir, y - 1, x, d + 1, num);
			}
			else if ( place[y-1][x] != num )
			{
				if ( d == 1 )return;
				int destNum = place[y - 1][x];
				adj[num][destNum] = min(adj[num][destNum], d);
				return;
			}
			else return;

		}
	}
	else //아래쪽
	{
		if ( y + 1 < N )
		{
			if ( place[y + 1][x] == 0 )
			{
				DFS(dir, y + 1, x, d + 1, num);
			}
			else if ( place[y + 1][x ] != num )
			{
				if ( d == 1 )return;
				int destNum = place[y + 1][x];
				adj[num][destNum] = min(adj[num][destNum], d);
				return;
			}
			else return;

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	place.resize(N, vector<int>(M));
	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			cin >> place[i][j];
		}
	}
	BFS();
	s.resize(d + 1, -1);
	/*for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			cout << place[i][j] << " ";
		}
		cout << endl;
	}
	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			if ( place[i][j] != 0 )
			{
				int start = place[i][j];
				for ( int k = 1; k < 5; k++ )
				{
					DFS(k, i, j, 0, start);
				}
			}
		}
	}*/

	for ( int i = 2; i < d; i++ )
	{
		vector<ii> sums = island[i];
		for ( ii &start : sums )
		{
			for ( int j = 1; j < 5; j++ )
			{
				DFS(j, start.first, start.second, 0, i);
			}
		}
	}
	vector<iii> arr;
	for ( int i = 2; i < d; i++ )
	{
		for ( int j = 2; j < d; j++ )
		{
			if ( adj[i][j] == 1000 )continue;
			arr.push_back({ { i,j },  adj[i][j] });
		}
	}
	sort(arr.begin(), arr.end(), cmp);
	int total = 0;
	for ( int i = 0; i < arr.size(); i++ )
	{
		iii &t = arr[i];
		int x = t.first.first;
		int y = t.first.second;
		int d = t.second;
		if ( Find(x) != Find(y) )
		{
			total += d;
			Union(x, y);
		}
	}
	for ( int i = 2; i < d; i++ )
	{
		if ( Find(i) != 2 )
		{
			
			cout << -1 << endl;
			return 0;
		}
	}
	cout << total << endl;
	return 0;
}