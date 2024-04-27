#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<vector>

using namespace std;

/*
* BFS() + ��Ʈ����ŷ
* 1. �� �� ũ�� Ȯ��
*	=> visited �迭�� �� ��ȣ�� ����
*	=> ���� v�� �� �� ũ�� ����
*	=> ��� : �� ����, ���� ���� ���� ũ��
*
* combine_room()
* 2. visited �������� �ѹ� �� BFS
*	=> ���� ��踦 ���� �� ������ �� ���� ũ�⸦ ���ؼ� max���� ã���ش�.
*/


int idx = 1; // �� ����
int _max = 0; // ���� ���� ��
int max_c = 0; // �ϳ��� ���� �����ؾ� ���� �� �ִ� ���� ���� ��
int N, M;
int MAP[51][51];
int visited[51][51];
// �� �� �� ��
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
			// �� ��ȣ�� �ٸ��� => ���
			if (visited[ny][nx] != prev)
				max_c = max(max_c, v[prev] + v[visited[ny][nx]]);
		}
	}
}

int main() {
	cin >> N >> M;
	// �Է�
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	v.push_back(0);
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

	// 1. ���� �μ��� �ʰ� BFS �� �� ����
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
	visited[i][j] = idx; // visted �迭�� ���� ��ȣ�� ����. 
	int cnt = 1; // �� ũ��

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			// �濡 �ִ� �� ��ġ�� Ȯ���Ѵ�.
			// true -> �� �����ϱ� ���� ����. 
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
	// ������ ũ�⸦ ����.
	v.push_back(cnt);
}