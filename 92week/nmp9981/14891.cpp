#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int k, num, dir;
string s;
const int wheelnum = 4,gear = 8;//톱니의 개수, 기어 개수
int cogwheel[wheelnum][gear];

//입력
void input() {
	//초기 톱니 상태
	for (int i = 0; i < wheelnum; i++) {
		cin >> s;
		for (int j = 0; j < gear; j++) {
			cogwheel[i][j] = s[j] - '0';//하나씩 받기
		}
	}
}

//회전하기
void ClockRotation(int x,int dir) {
	int cogline[gear];//임의 배열
	if (dir == 1) {//시계
		int rest = cogwheel[x][gear - 1];
		for (int i = 1; i < gear; i++) {
			cogline[i] = cogwheel[x][i - 1];
		}
		cogline[0] = rest;
	}
	else if (dir == -1) {//반시계
		int rest = cogwheel[x][0];
		for (int i = gear-1; i >= 1; i--) {
			cogline[i - 1] = cogwheel[x][i];
		}
		cogline[gear - 1] = rest;
	}
	//회전후의 톱니바퀴
	for (int i = 0; i < gear; i++) cogwheel[x][i] = cogline[i];
}

//다음 지점 회전 여부
void Rotates(int num,int dir) {
	switch (num) {
	case 0:
		if (cogwheel[0][2] != cogwheel[1][6]) {//가까운곳 부터
			if (cogwheel[1][2] != cogwheel[2][6]) {
				if (cogwheel[2][2] != cogwheel[3][6]) {
					ClockRotation(0, dir);
					ClockRotation(1, -dir);
					ClockRotation(2, dir);
					ClockRotation(3, -dir);
				}
				else {
					ClockRotation(0, dir);
					ClockRotation(1, -dir);
					ClockRotation(2, dir);
				}
			}
			else {
				ClockRotation(0, dir);
				ClockRotation(1, -dir);
			}
		}
		else {
			ClockRotation(0, dir);
		}
		break;
	case 1:
		if (cogwheel[1][2] == cogwheel[2][6]) {//1,2가 같다
			if (cogwheel[1][6] == cogwheel[0][2]) {//0,1이 같다
				ClockRotation(1, dir);
			}
			else {//0,1이 다르다
				ClockRotation(0, -dir);
				ClockRotation(1, dir);
			}
		}
		else {//1,2가 다르다
			if (cogwheel[0][2] == cogwheel[1][6]) {//0,1이 같다
				if (cogwheel[2][2] == cogwheel[3][6]) {//2,3이 같다
					ClockRotation(1, dir);
					ClockRotation(2, -dir);
				}
				else {//2,3이 다르다
					ClockRotation(1, dir);
					ClockRotation(2, -dir);
					ClockRotation(3, dir);
				}
			}
			else {//0,1이 다르다
				if (cogwheel[2][2] == cogwheel[3][6]) {//2,3이 같다
					ClockRotation(0, -dir);
					ClockRotation(1, dir);
					ClockRotation(2, -dir);
				}
				else {//2,3이 다르다
					ClockRotation(0, -dir);
					ClockRotation(1, dir);
					ClockRotation(2, -dir);
					ClockRotation(3, dir);
				}
			}
		}
		break;
	case 2:
		if (cogwheel[1][2] == cogwheel[2][6]) {//1,2가 같다
			if (cogwheel[2][2] == cogwheel[3][6]) {//2,3이 같다
				ClockRotation(2, dir);
			}
			else {//2,3이 다르다
				ClockRotation(2, dir);
				ClockRotation(3, -dir);
			}
		}
		else {//1,2가 다르다
			if (cogwheel[2][2] == cogwheel[3][6]) {//2,3이 같다
				if (cogwheel[0][2] == cogwheel[1][6]) {//0,1이 같다
					ClockRotation(1, -dir);
					ClockRotation(2, dir);
				}
				else {//0,1이 다르다
					ClockRotation(0, dir);
					ClockRotation(1, -dir);
					ClockRotation(2, dir);
				}
			}
			else {//2,3이 다르다
				if (cogwheel[0][2] == cogwheel[1][6]) {//0,1이 같다
					ClockRotation(1, -dir);
					ClockRotation(2, dir);
					ClockRotation(3, -dir);
				}
				else {//0,1이 다르다
					ClockRotation(0, dir);
					ClockRotation(1, -dir);
					ClockRotation(2, dir);
					ClockRotation(3, -dir);
				}
			}
		}
		break;
	case 3:
		if (cogwheel[2][2] != cogwheel[3][6]) {//가까운곳 부터
			if (cogwheel[1][2] != cogwheel[2][6]) {
				if (cogwheel[0][2] != cogwheel[1][6]) {
					ClockRotation(3, dir);
					ClockRotation(2, -dir);
					ClockRotation(1, dir);
					ClockRotation(0, -dir);
				}
				else {
					ClockRotation(3, dir);
					ClockRotation(2, -dir);
					ClockRotation(1, dir);
				}
			}
			else {
				ClockRotation(3, dir);
				ClockRotation(2, -dir);
			}
		}
		else {
			ClockRotation(3, dir);
		}
		break;
	}
}
//톱니 회전
void WheelnumRotation() {
	cin >> k;//회전 횟수
	for (int i = 0; i < k; i++) {
		cin >> num >> dir;
		//몇번이 회전 했는가?
		Rotates(num-1, dir);
	}
}

//점수
void score() {
	int ans = cogwheel[0][0] + 2 * cogwheel[1][0] + 4 * cogwheel[2][0] + 8 * cogwheel[3][0];
	cout << ans;
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	WheelnumRotation();//회전
	score();//점수
	return 0;
}
