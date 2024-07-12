/*
	10x10 종이에 1x1 ~ 5x5 색종이(종류 별로 5개)를 붙인다
	종이에 0이 적힌 칸은 색종이를 붙일 수 없고, 경계 밖으로 나가거나 색종이 끼리 겹쳐서는 안된다
	1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수 구하기
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include <set>
using namespace std;

int a[12][12];
int paper[6] = { 0,5,5,5,5,5 }; // 5종류 색종이 개수
int ans=1000;

// 모든 칸이 1일 때 1 반환
int isPossible(int y, int x, int k) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (a[i][j] != 1) return 0;
		}
	}
	return 1;
}

// (y, x) 좌표에서 k 만큼 범위를 num으로 바꿔준다
void update(int y, int x, int k, int num) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k;j++) {
			a[i][j] = num;
		}
	}
}

// (0, 0) ~ (9, 9)를 탐색 해 1이면 큰 색종이 부터 붙여줌
// 1이 적힌 모든 칸에 색종이를 붙일 수 있으면 값 저장
// 색종이를 떼어 내고 다른 크기 색종이를 붙여줌
void go(int y, int x, int cnt) {

	if (ans <= cnt) return; //  최소 색종이 개수만 구하면 됨

	// (10 x 10) 종이 탐색
	while (a[y][x] == 0) {
		if (x < 9) {
			x++;
		}
		else if (y < 9) {
			x = 0;
			y++;
		}
		else { // (9, 9)일 때 색종이 개수 저장
			ans = cnt;
			return;
		}
	}
	
	for (int k = 5; k >= 1; k--) { // (5 x 5) ~ (1 x 1)
		if (paper[k] != 0 && isPossible(y, x, k) == 1) { // (k x k) 색종이가 있고, 해당 범위의 모든 칸이 1일 때 색종이를 붙일 수 있다
			paper[k]--; // 사용한 색종이 표시
			update(y, x, k, 0); // 같은 곳에 색종이를 붙이지 않기 위해, 색종이를 붙인 곳은 0으로 바꿔준다

			go(y, x, cnt + 1); // 색종이 수 + 1, 재귀

			paper[k]++; // 복구
			update(y, x, k, 1); // 복구
		}
		else if (k == 1) return; // 색종이를 붙이지 못하면 불가능한 경우
	}

}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, 0); // 백트래킹

	if (ans == 1000) ans = -1; // 모두 덮는 것이 불가능한 경우 -1 출력
	cout << ans << "\n";

	return 0;
}
