#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<vector>

using namespace std;

/*
* BFS() + 비트마스킹
* 1. 각 방 크기 확인
*	=> visited 배열에 방 번호를 저장
*	=> 벡터 v에 각 방 크기 저장
*	=> 출력 : 방 개수, 가장 넓은 방의 크기
*
* combine_room()
* 2. visited 기준으로 한번 더 BFS
*	=> 방의 경계를 지날 때 인접한 두 방의 크기를 합해서 max값을 찾아준다.
*/


int idx = 1; // 방 개수
int _max = 0; // 가장 넓은 방
int max_c = 0; // 하나의 벽을 제거해야 얻을 수 있는 가장 넓은 방
int N, M;
int MAP[51][51];
int visited[51][51];
// 서 북 동 남
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };
vector<int> v;

void BFS(int i, int j, int idx);

void combine_room() {
	int check[51][51];
	fill(&check[0][0], &check[0][0] + 51 * 51, 0);
	queue <tuple<int, int, int>> q;
	q.push({ 0,0,1 });
	check[0][0] = 1;

	while (!q.empty()) {
		int y, x, prev;
		tie(y, x, prev) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
			if (check[ny][nx]) continue;
			q.push({ ny,nx, visited[ny][nx] });
			check[ny][nx] = 1;
			// 방 번호가 다르면 => 경계
			if (visited[ny][nx] != prev)
				max_c = max(max_c, v[prev] + v[visited[ny][nx]]);
		}
	}
}

int main() {
	cin >> N >> M;
	// 입력
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	v.push_back(0);
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

	// 1. 벽을 부수지 않고 BFS 한 번 실행
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j])
				BFS(i, j, idx++);
		}
	}
	combine_room();

	cout << idx - 1 << '\n';
	cout << _max << '\n';
	cout << max_c << '\n';
}


// BFS
void BFS(int i, int j, int idx) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = idx; // visted 배열엔 방의 번호가 들어간다. 
	int cnt = 1; // 방 크기

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 방에 있는 벽 위치를 확인한다.
			// true -> 벽 있으니까 가지 않음. 
			if (MAP[y][x] & 1 << i)continue;
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
			if (visited[ny][nx]) continue;
			q.push({ ny,nx });
			visited[ny][nx] = idx;
			cnt++;
		}
	}
	_max = max(cnt, _max);
	// 구해진 크기를 저장.
	v.push_back(cnt);
}