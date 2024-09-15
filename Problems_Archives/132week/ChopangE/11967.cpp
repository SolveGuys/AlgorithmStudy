#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
int N, M;
int total = 0;
vector<vector<int>> place;
vector<vector<vector<ii>>> place2;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	place.resize(N + 1);
	place2.resize(N + 1);
	for ( int i = 0; i < N + 1; i++ )
	{
		place[i].resize(N + 1, 0);
		place2[i].resize(N + 1);
	}
	for ( int i = 0; i < M; i++ )
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		place2[a][b].push_back({ c,d });
	}
	queue<ii> que;
	place[1][1] = 2;
	total = 1;
	queue<ii> tmp;
	for ( ii &a : place2[1][1] )
	{
		tmp.push(a);
	}
	
	while ( !tmp.empty() )
	{
		while(!tmp.empty())
		{
			ii t = tmp.front();
			tmp.pop();
			int y = t.first;
			int x = t.second;
			if ( place[y][x] >= 1 )continue;
			place[y][x] = 1;
			total++;
		}
		que.push({ 1, 1 });
		vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, 0));
		visit[1][1] = 1;
		while ( !que.empty() )
		{
			int y, x;
			tie(y, x) = que.front();

			que.pop();
			for ( int i = 0; i < 4; i++ )
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if ( ny >= N + 1 || nx >= N + 1 || nx < 0 || ny < 0 || place[ny][nx] == 0 || visit[ny][nx] )continue;
				visit[ny][nx] = 1;
				if ( place[ny][nx] == 1 )
				{
					for ( ii &t : place2[ny][nx] )
					{
						tmp.push(t);
					}
					place[ny][nx] = 2;
					que.push({ ny,nx });
				}
				else
				{
					que.push({ ny,nx });
				}
			}


		}
	}
	cout << total << endl;
	return 0;
}