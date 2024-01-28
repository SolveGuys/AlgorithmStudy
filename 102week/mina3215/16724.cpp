#include<iostream>
#include<string>
#include<queue>
#include<map>

using namespace std;

int N, M;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<string> board;
int visited[1000][1000];
map<char, pair<int, int>> m;

void BFS(int y, int x){
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty()) {
		
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		int gy = y+m[board[y][x]].first;
		int gx = x+m[board[y][x]].second;
		if (!visited[gy][gx]) {
			visited[gy][gx] = 1;
			q.push({ gy,gx });
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (m[board[ny][nx]].first == -1 * dy[i] && m[board[ny][nx]].second == -1 * dx[i]) {
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	cin.ignore();
	m['U'] = { -1,0 };
	m['D'] = { 1,0 };
	m['L'] = { 0,-1 };
	m['R'] = { 0,1 };
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	int ans = 0;


	for (int y = 0; y < N;y++) {
		for (int x = 0; x < M; x++) {
			if (visited[y][x]) continue;
			BFS(y, x);
			ans += 1;
			
		}
	}

	std::cout << ans;

}