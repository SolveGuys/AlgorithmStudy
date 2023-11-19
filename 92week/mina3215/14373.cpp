#include<bits/stdc++.h>

using namespace std;

string gear[5];
int number[5] = {0,0,0,0,0}; // 12시 방향의 톱니들을 담을 배열
int T;

void turn(int n, int d) {
	int turns[5] = { 0,0,0,0,0 }; // 바퀴를 돌릴 방향을 담을 배열
	turns[n] = d; // 일단 n번째 톱니를 d방향으로 돌린다.
	
	int right_gear = n; 
	int left_gear = n;
	
	// n번째 톱니의 우측 톱니들의 방향을 정한다.
	while (right_gear < 4) {
		int connect = (number[right_gear] + 2) % 8; // 현재 바퀴 오른쪽에 접하는 톱니
		int connect_r = (number[right_gear + 1] + 6) % 8;  // (number[n+1] -2 + 8)%8 우측 바퀴의 기준 톱니에 접해있는 톱니
		//다르면
		if (gear[right_gear][connect] != gear[right_gear + 1][connect_r]) {
			turns[right_gear + 1] = turns[right_gear]*-1;
			right_gear++;
		}
		// 같으면 더 이상의 회전은 없음 => 그 다음의 톱니바퀴들도 돌지 않는다..
		else break;
	}
	
	//위와 같은 방식으로 좌측 톱니까지 시행한다. 
	while (left_gear > 1) {
		int connect = (number[left_gear] + 6) % 8;
		int connect_l = (number[left_gear - 1] + 2) % 8;
		if (gear[left_gear][connect] != gear[left_gear - 1][connect_l]) {
			turns[left_gear - 1] = turns[left_gear] * -1;
			left_gear--;
		}
		else break;
	}

	// 톱니들을 돌린다.
	for (int i = 0;i < 5;i++) {
		number[i] = (number[i] + turns[i] + 8) % 8;
	}
}

int main() {
	//편의를 위해 0을 임의로 넣어줌
	gear[0]="00000000";
	int n, d;
	for (int i = 1; i <= 4; i++) cin >> gear[i];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> d; // n 번째 톱니를 d방향으로
		turn(n, d*-1);
	}
	int ans = 0;
	int score = 1;
	
	// 12시 방향의 톱니가 1일때 score를 추가하는데 2의 제곱씩 늘어남.
	for (int i = 1; i < 5; i++) {
		if (gear[i][number[i]] == '1') {
			ans += score;
		}
		score *= 2;
	}
	cout << ans;

	return 0;
}
