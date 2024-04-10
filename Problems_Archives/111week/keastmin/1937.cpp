#include <iostream>
#include <vector>
using namespace std;

// 입력 벡터
int N;
vector<vector<int>> map;
vector<vector<int>> dp;

// DFS를 위한 방향 전환 변수
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

// 결과 저장 변수
int res = 0;

// 최대 범위를 넘어가는지 검사
bool check(int x, int y) {
	if (x <= 0 || x > N || y <= 0 || y > N) return false;
	return true;
}

// DFS와 DP를 결합한 그래프 이론 진행
int dfs(int x, int y) {

	// 방문한 적이 있다면 해당 칸의 최대 이동 가능 칸 수 리턴
	if (dp[y][x] != 0) return dp[y][x];

	// 방문한 적 없다면 최대 이동 가능 칸 수 초기화, 일종의 방문처리
	dp[y][x] = 1;

	// 현재 위치로부터 사분면 이동 진행: DFS 그래프 이론
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];


		/********************************************
			최대로 이동할 수 있는 칸을 dp식으로 저장
					dp배열의 변화
			1 1 1 0				7 6 5 0
			0 0 1 0		->		0 0 4 0
			0 0 1 0		->		0 0 3 0
			0 0 1 1				0 0 2 1

			위와 같이 최대 이동 칸 수가 업데이트
		********************************************/
		if (check(nx, ny)) {					// 범위 검사
			if (map[y][x] < map[ny][nx]) {		// 더 숫자가 큰 지역만 이동 가능
				dp[y][x] = max(dp[y][x], dfs(nx, ny) + 1);
			}
		}
	}

	// 현재 최대 이동 가능 칸 수 리턴
	return dp[y][x];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 입력 및 초기화
	cin >> N;
	map.resize(N + 1, vector<int>(N + 1));
	dp.resize(N + 1, vector<int>(N + 1, 0));

	// 대나무 숲 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// 모든 인덱스를 순회하며 이동 가능 칸 수가 가장 큰 정답 찾기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res = max(res, dfs(j, i));
		}
	}

	// 정답 출력
	cout << res << '\n';

	return 0;
}
