#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;
#define OLD_MAX 1110

int dy[] = { 0,0,1,-1, 1, -1, 1, -1 };
int dx[] = { 1,-1,0,0, 1, -1, -1, 1 };

// �ܿ￡ �߰��� ���
int A[11][11];

// ���� ���� ����� ����.
int _nutrition[11][11];

// �� ����� ����
int nutrition[11][11];

// �����ϴ� ������ ���� ����
int board[11][11];

int N, M, K;

// �����ϴ� ����
queue<pair<int, int>> trees[11][11];


// board-> N 
// 10*10 * (a+b+c+d) < 3õ����

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
	// ��ü Ž�� (100)
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			// ���� ���� ������ ����Һ��� ������ ���� �� ���� pop
			if (trees[y][x].empty())
				continue;
			// board = ������ ���� ����.
			while (board[y][x] > nutrition[y][x]) {
				// front()�� ���� ���� ���� ����( ���� ���̰� ���� �� ) 
				pair<int,int> tree = trees[y][x].front();
				// ���� ���̰� ���� ������ ���� = ��� ���� �� ���� + �ð��� ���� ���� ����
				int old = tree.first + k - tree.second + 1;
				// ���� ���� ������ �������� pop()
				trees[y][x].pop();
				// ������ �տ��� �ش� ���̸� ����.
				board[y][x] -= old;
				// ���� ������ ����Ұ� ��
				_nutrition[y][x] += old/2;
			}
			nutrition[y][x] -= board[y][x];
			// ���� ��ü ���� += ���� ��ü ����
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
	// �ʱ�ȭ
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
