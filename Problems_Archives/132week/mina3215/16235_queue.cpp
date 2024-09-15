#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;
#define OLD_MAX 1110

int dy[] = { 0,0,1,-1, 1, -1, 1, -1 };
int dx[] = { 1,-1,0,0, 1, -1, -1, 1 };

// 겨울에 추가할 양분
int A[11][11];

// 죽은 나무 영양분 저장.
int _nutrition[11][11];

// 띵 영양분 저장
int nutrition[11][11];

// 존재하는 나무의 총합 나이
int board[11][11];

int N, M, K;

// 존재하는 나무
queue<pair<int, int>> trees[11][11];


// board-> N 
// 10*10 * (a+b+c+d) < 3천만번

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}
	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> z;
		y -= 1; x -= 1;
		trees[y][x].push({ z,0 });
		board[y][x] += z;
	}
}

void spring_summer(int k) {
	// 전체 탐색 (100)
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			// 나무 나이 총합이 영양소보다 많으면 적을 때 까지 pop
			if (trees[y][x].empty())
				continue;
			// board = 나무의 나이 총합.
			while (board[y][x] > nutrition[y][x]) {
				// front()는 가장 먼저 들어온 나무( 가장 나이가 많을 것 ) 
				pair<int,int> tree = trees[y][x].front();
				// 가장 나이가 많은 나무의 나이 = 들어 왔을 때 나이 + 시간이 지나 쌓인 나이
				int old = tree.first + k - tree.second + 1;
				// 가장 많은 나이인 나무부터 pop()
				trees[y][x].pop();
				// 나이의 합에서 해당 나이를 뺀다.
				board[y][x] -= old;
				// 죽은 나무는 영양소가 됨
				_nutrition[y][x] += old/2;
			}
			nutrition[y][x] -= board[y][x];
			// 나무 전체 나이 += 나무 전체 개수
			board[y][x] += trees[y][x].size();
		}
	}
}

void expand(int y, int x, int k) {
	for (int i = 0; i < 8;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		trees[ny][nx].push({ 1,k+1 });
		board[ny][nx] += 1;
	}
}

void fall(int k) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (trees[y][x].empty())
				continue;
			int size = trees[y][x].size();
			for (int i = 0; i < size; i++) {
				pair<int, int> tree = trees[y][x].front();
				int old = tree.first + k + 1 - tree.second;
				trees[y][x].pop();
				if ((old % 5)==0)
					expand(y, x, k);
				trees[y][x].push({ tree.first, tree.second });
			}
		}
	}

}

void winter() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			nutrition[y][x] += (_nutrition[y][x] + A[y][x]);
			_nutrition[y][x] = 0;
		}
	}
}
/*
void print_trees() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << trees[i][j].size()<<' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "-------------------------- - " << '\n';
}*/

int main() {
	// 초기화
	fill(&board[0][0], &board[0][0] + 11 * 11, 0);
	fill(&nutrition[0][0], &nutrition[0][0] + 11 * 11, 5);
	fill(&_nutrition[0][0], &_nutrition[0][0] + 11 * 11, 0);

	input();

	for (int i = 0; i < K; i++) {
		spring_summer(i);
		fall(i);
		winter();
		//print_trees();
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ans += trees[i][j].size();
	}
	cout << ans;
}
