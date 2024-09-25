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
int T, H, W;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for ( int c = 0; c < T; c++ )
	{
		cin >> H >> W;
		vector<vector<char>> place(H, vector<char>(W));
		vector<vector<ii>> door(28, vector<ii>());
		queue<char> now_key;
		for ( int i = 0; i < H; i++ )
		{
			for ( int j = 0; j < W; j++ )
			{
				cin >> place[i][j];
				if ( place[i][j] >= 'A' && place[i][j] <= 'Z' )
				{
					door[place[i][j] - 'A'].push_back({ i,j });

				}
			}
		}
		string t;
		cin >> t;
		for ( int i = 0; i < t.size(); i++ )
		{
			if ( t[i] == '0' )break;
			now_key.push(t[i]);
		}
		for ( int i = 0; i < H; i++ )
		{
			if ( place[i][0] >= 'a' && place[i][0] <= 'z' )
			{
				now_key.push({ place[i][0] });
				place[i][0] = '.';
			}
			if ( place[i][W-1] >= 'a' && place[i][W-1] <= 'z' )
			{
				now_key.push({ place[i][W - 1] });
				place[i][W-1] = '.';
			}
		}

		for ( int i = 0; i < W; i++ )
		{
			if ( place[0][i] >= 'a' && place[0][i] <= 'z' )
			{
				now_key.push({ place[0][i] });
				place[0][i] = '.';
			}
			if ( place[H-1][i] >= 'a' && place[H-1][i] <= 'z' )
			{
				now_key.push({ place[H - 1][i] });
				place[H-1][i] = '.';
			}
		}

		int key_size = now_key.size();
		for ( int i = 0; i < key_size; i++ )
		{
			char key_num = now_key.front();
			now_key.pop();
			for ( ii &t : door[key_num - 'a'] )
			{
				int y = t.first;
				int x = t.second;
				place[y][x] = '.';
			}
		}
		int res = 0;

		while ( 1 )
		{
			int time = 0;

			queue<ii> que;
			for ( int i = 0; i < W; i++ )
			{
				if ( place[0][i] == '.' )que.push({ 0,i });
				else if ( place[0][i] == '$' )
				{
					que.push({ 0,i });
					place[0][i] = '.';
					res++;
				}
				if ( place[H - 1][i] == '.' )que.push({ H - 1,i });
				else if ( place[H - 1][i] == '$' )
				{
					que.push({ H - 1,i });
					place[H - 1][i] = '.';
					res++;
				}
			}
			for ( int i = 0; i < H; i++ )
			{
				if ( place[i][0] == '.' )que.push({ i,0 });
				else if ( place[i][0] == '$' )
				{
					que.push({ i,0 });
					place[i][0] = '.';
					res++;
				}
				if ( place[i][W - 1] == '.' )que.push({ i,W - 1 });
				else if ( place[i][W-1] == '$' )
				{
					que.push({ i,W - 1 });
					place[i][W - 1] = '.';
					res++;
				}
			}
			vector<vector<bool>> visit(H, vector<bool>(W, 0));
			while ( !que.empty() )
			{
				int y, x;
				tie(y, x) = que.front();
				que.pop();
				if ( visit[y][x] )continue;
				visit[y][x] = 1;
				for ( int i = 0; i < 4; i++ )
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if ( nx >= W || nx < 0 || ny >= H || ny < 0 || visit[ny][nx] || place[ny][nx] == '*' || (place[ny][nx] >= 'A' && place[ny][nx] <= 'Z') )continue;
					if ( place[ny][nx] == '$' )
					{
						res++; 
						que.push({ ny,nx });
						//cout << "ny : " << ny << " nx : " << nx << endl;
						place[ny][nx] = '.';
					}
					else if ( place[ny][nx] == '.' )	
					{
						que.push({ ny,nx });
					}
					else if ( place[ny][nx] >= 'a' && place[ny][nx] <= 'z' )	//열쇠를 찾은경우
					{
						que.push({ ny,nx });
						for ( ii &dd : door[place[ny][nx] - 'a'] )
						{
							place[dd.first][dd.second] = '.';
						}
						place[ny][nx] = '.';
						
						time++;
					}
				}
			}
			if ( time == 0 )
			{
				cout << res << endl;
				break;
			}
			
		}

	}
	return 0;
}