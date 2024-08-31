#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

typedef pair<int, int> ii;

int R, C;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	vector<vector<char>> place(R, vector<char>(C));
	vector<vector<int>> count(R, vector<int>(C, 0));
	queue<ii> water;
	queue<ii> gosum;
	ii dist;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> place[i][j];
			if (place[i][j] == 'S') {
				gosum.push({ i,j });
				count[i][j] = 1;
			}
			else if (place[i][j] == 'D') {
				dist = { i,j };
			}
			else if(place[i][j] == '*') {
				water.push({ i,j });
				count[i][j] = -1;
			}
		}
	}
	while (!water.empty() && !gosum.empty()) {
		int w_size = water.size();
		int g_size = gosum.size();
		for (int j = 0; j < w_size; j++) {
			int y, x;
			tie(y, x) = water.front();
			water.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || place[ny][nx] == 'X' || place[ny][nx] == 'D' || count[ny][nx] != 0) continue;
				water.push({ ny,nx });
				count[ny][nx] = count[y][x] - 1;

			}
		}
		for (int j = 0; j < g_size; j++) {
			int y, x;
			tie(y, x) = gosum.front();
			if (y == dist.first && x == dist.second) {
				cout << count[y][x] - 1 << endl;
				return 0;
			}
			gosum.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || place[ny][nx] == 'X' || count[ny][nx] != 0)continue;
				gosum.push({ ny,nx });

				count[ny][nx] = count[y][x] + 1;

			}
		}
	}
	
 	if (gosum.empty()) {
		cout << "KAKTUS" << endl;
		return 0;
	}
	if (water.empty()) {
		while (!gosum.empty()) {
			int y, x;
			tie(y, x) = gosum.front();
			if (y == dist.first && x == dist.second) {
				cout << count[y][x] - 1 << endl;
				return 0;
			}
			gosum.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || ny >= C || place[ny][nx] == 'X' || count[ny][nx] != 0)continue;
				gosum.push({ ny,nx });
				count[ny][nx] = count[y][x] + 1;
			}
		}
	}
	cout << "KAKTUS" << endl;
	return 0;
}