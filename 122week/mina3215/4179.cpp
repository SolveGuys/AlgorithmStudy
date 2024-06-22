#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<set>

using namespace std;

int R, C;
pair<int, int> start;
vector<string> MAP;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

queue<tuple<int, int, int>> fires;
queue<tuple<int, int, int>> jihoon;

void input() {
	string s;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		MAP.push_back(s);
		for (int j=0; j<C; j++){
			if (s[j] == 'J')
				jihoon.push({ 0,i,j });
			if (s[j] == 'F')
				fires.push({ 0,i,j });
		}
	}

}

int move_fire(int n) {

	while (!fires.empty()&&get<0>(fires.front()) == n) {
		int n, y, x;
		tie(n, y, x) = fires.front();
		fires.pop();
		for (int i = 0; i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (MAP[ny][nx] == 'F'||MAP[ny][nx]=='#') continue;
			MAP[ny][nx] = 'F';
			fires.push({ n + 1,ny,nx });
		}
	}
	return 0;
}

int move_jihoon(int n) {
	while (!jihoon.empty() && get<0>(jihoon.front()) == n) {
		int n, y, x;
		tie(n, y, x) = jihoon.front();
		jihoon.pop();
		if (y == 0 || x == 0 || y == R - 1 || x == C - 1) return n + 1;
		for (int i = 0; i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (MAP[ny][nx] == 'F' || MAP[ny][nx] == '#'||MAP[ny][nx]=='J') continue;
			MAP[ny][nx] = 'J';
			jihoon.push({ n + 1,ny,nx });
		}
	}
	if (jihoon.empty())
		return -1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int ans = 0;
	int cnt = 0;

	while (ans==0) {
		move_fire(cnt);
		ans = move_jihoon(cnt);
		cnt++;
	}
	if (ans < 0)
		cout << "IMPOSSIBLE";
	else
		cout << ans;


}