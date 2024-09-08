#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<memory.h>
#include<stack>
using namespace std;

int n, m, x1, yy1, x2, y2, cnt, flag, res;
int visited[304][304];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
char a[304][304];
vector <pair<int, int>> v;
string s;

void go(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (visited[ny][nx] == 1)continue;
		if (a[ny][nx] == '0') {
			go(ny, nx);
		}
		else if (a[ny][nx]=='1') {
			v.push_back({ ny, nx });
			continue;
		}
		else if (a[ny][nx] == '#') {
			flag = 1;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> x1 >> yy1 >> x2 >> y2;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	while (1) {
		fill(&visited[0][0], &visited[0][0] + 304 * 304, 0);
		for (auto pos : v) {
			a[pos.first][pos.second] = '0';
		}
		v.clear();
		go(x1-1, yy1-1);
		cnt++;

		if (flag == 1) break;
	}
	
	cout << cnt << "\n";

	return 0;
}
