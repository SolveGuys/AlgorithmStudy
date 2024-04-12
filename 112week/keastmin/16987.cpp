/**********************************************************
2024-04-12
https://github.com/keastmin
백준/16987/계란으로 계란치기
난이도: 골드5
유형: 브루트포스, 백트래킹
**********************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 계란의 내구도와 무게에 관한 구조체
struct Egg {
	int S, W;
};

int N;				// 계란의 수
vector<Egg> eggs;	// 계란 구조체 벡터
int res = 0;		// 결과

// 백트래킹을 통해 깨지는 계란의 최대값 계산
void backTracking(int curr) {
	if (curr > N) return;	// 계란의 수를 넘어가는 인덱스라면 리턴

	// 모든 계란 탐색
	for (int i = 0; i < N; i++) {

		// 현재 잡은 계란의 내구도가 0 이하라면 다음 계란으로 백트래킹 진행
		if (eggs[curr].S <= 0) backTracking(curr + 1);
		
		// 계란 탐색 중 현재 계란이나 이미 내구도가 0인 계란은 무시
		else if (curr == i || eggs[i].S <= 0) continue;

		// 계란끼리 부딫힐 수 있는 조건이라면 진입
		else {

			// 계란끼리 부딫혀 본 후
			eggs[curr].S -= eggs[i].W;
			eggs[i].S -= eggs[curr].W;

			// 다음 계란으로 진행
			backTracking(curr + 1);

			// 백트래킹을 위해 원상 복구
			eggs[curr].S += eggs[i].W;
			eggs[i].S += eggs[curr].W;
		}
	}

	// 현재 계란들 중 깨진 계란의 수 계산
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (eggs[i].S <= 0) cnt++;
	}

	res = max(res, cnt);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	eggs.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> eggs[i].S >> eggs[i].W;
	}

	// 가장 왼쪽 계란부터 백트래킹 진행
	backTracking(0);

	// 결과 출력
	cout << res << '\n';

	return 0;
}
