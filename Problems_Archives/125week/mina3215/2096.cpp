#include<iostream>
#include<algorithm>

using namespace std;

int N;
int MAP[100000][3];
int DP[3];

void input() {
	cin >> N;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < N; i++) {
		cin >> MAP[i][0] >> MAP[i][1] >> MAP[i][2];
	}
}

int main() {
	input();
	fill(DP, DP+3, 0);
	int _max = 0;
	for (int i = 0; i < N; i++) {
		int DP0 = max(DP[0], DP[1]) + MAP[i][0];
		int DP1 = max(DP[1], DP[2]) + MAP[i][1];
		DP1 = max(DP1, DP[0] + MAP[i][1]);
		int DP2 = max(DP[1], DP[2]) + MAP[i][2];
		DP[0] = DP0;
		DP[1] = DP1;
		DP[2] = DP2;
	}

	for (int i = 0; i < 3; i++) {
		_max = max(DP[i], _max);
	}

	fill(DP, DP + 3, 0);
	int _min = 2e9;
	for (int i = 0; i < N; i++) {
		int DP0 = min(DP[0], DP[1]) + MAP[i][0];
		int DP1 = min(DP[1], DP[2]) + MAP[i][1];
		DP1 = min(DP1, DP[0] + MAP[i][1]);
		int DP2 = min(DP[1], DP[2]) + MAP[i][2];
		DP[0] = DP0;
		DP[1] = DP1;
		DP[2] = DP2;
	}

	for (int i = 0; i < 3; i++) {
		_min = min(DP[i], _min);
	}

	cout << _max << ' ' << _min;


}