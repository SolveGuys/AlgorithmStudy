#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int board[102][102];
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
int N;
int ans = 0;

int check_square() {
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (board[y][x] && board[y + 1][x] && board[y][x + 1] && board[y + 1][x + 1])ans++;
		}
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		vector<int> curve;
		cin >> x >> y >> d >> g;
		curve.push_back(d);

		for (int i = 0; i < g;i++) {
			int len = curve.size();

			for (int j = len - 1; j >= 0; j--) {
				int n = curve[j];
				curve.push_back((n + 1) % 4);
			}
		}

		for (int i = 0; i < curve.size(); i++) {
			int n = curve[i];
			board[y][x] = 1;
			y += dy[n];
			x += dx[n];
		}
		board[y][x] = 1;
	}
	check_square();
	cout << ans;
}