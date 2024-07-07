#include<iostream>
#include<tuple>
#include<queue>
#include<vector>
#include<algorithm>

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int Board[10][10];

int ans = 2e9;
using namespace std;


void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0;i < 10;i++)
		for (int j = 0; j < 10; j++)
			cin >> Board[i][j];
}

bool available(int _y, int _x, int w) {
	for (int y = _y; y < _y + w;y++) {
		for (int x = _x; x < _x + w;x++) {
			if (Board[y][x] == 0)
				return false;
		}
	}
	return true;
}

void try_stick(int _y, int _x, int w,int num) {
	for (int y = _y; y < _y + w; y++) {
		for (int x = _x; x < _x + w; x++) {
			Board[y][x] = num;
		}
	}
}

bool check_empty() {
	for (int y = 0;y < 10;y++) {
		for (int x = 0; x < 10; x++) {
			if (Board[y][x])
				return false;
		}
	}
	return true;
}

void DFS(vector<int> &paper, int sum, int py) {
	if (ans <= sum)
		return;

	if (check_empty()) {
		ans = min(ans, sum);
		return;
	}


	for (int y = py; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (Board[y][x] == 1) {
				for (int w = 5;w > 0;w--) {
					if (paper[w] >= 5 || x + w > 10 || y + w > 10) continue;
					if (!available(y, x, w))
						continue;
					paper[w] += 1;
					try_stick(y, x, w, 0);
					DFS(paper, sum + 1, y);
					try_stick(y, x, w, 1);
					paper[w] -= 1;
				}
				return; // 어차피 색종이를 다 대입 시킨 후로 더 이상 반복문을 돌 필요가 없다.
			}
		}
	}

	return;
}



int main() {
	input();
	vector<int> paper(6);
	fill(paper.begin(), paper.end(), 0);
	DFS(paper, 0, 0);
	if (ans == 2e9)
		ans = -1;
	cout << ans;

	return 0;
}