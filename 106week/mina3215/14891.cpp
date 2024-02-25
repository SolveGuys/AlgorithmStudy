#include<bits/stdc++.h>

using namespace std;

string gear[5];
int number[5] = { 0,0,0,0,0 };
int T;

void turn(int n, int d) {
	int turns[5] = { 0,0,0,0,0 };
	turns[n] = d;
	int right_gear = n;
	int left_gear = n;
	while (right_gear < 4) {
		int connect = (number[right_gear] + 2) % 8; // 현재 바퀴 오른쪽에 접해있는 톱니
		int connect_r = (number[right_gear + 1] + 6) % 8;  // (number[n+1] -2 + 8)%8 // 우측 바퀴 접한 톱니
		if (gear[right_gear][connect] != gear[right_gear + 1][connect_r]) {
			turns[right_gear + 1] = turns[right_gear] * -1;
			right_gear++;
		}
		else break;
	}

	while (left_gear > 1) {
		int connect = (number[left_gear] + 6) % 8;
		int connect_l = (number[left_gear - 1] + 2) % 8;
		if (gear[left_gear][connect] != gear[left_gear - 1][connect_l]) {
			turns[left_gear - 1] = turns[left_gear] * -1;
			left_gear--;
		}
		else break;
	}
	for (int i = 0;i < 5;i++) {
		number[i] = (number[i] + turns[i] + 8) % 8;
	}
}

int main() {
	gear[0] = "00000000";
	int n, d;
	for (int i = 1; i <= 4; i++) cin >> gear[i];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> d; // n을 d방향으로
		turn(n, d * -1);
	}
	int ans = 0;
	int score = 1;
	for (int i = 1; i < 5; i++) {
		if (gear[i][number[i]] == '1') {
			ans += score;
		}
		score *= 2;
	}
	cout << ans;

	return 0;
}
